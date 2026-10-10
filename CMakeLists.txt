cmake_minimum_required(VERSION 3.10)
project(MbrBootloader NONE)

enable_language(C)
find_program(NASM_EXEC nasm REQUIRED)

# --- 1. Конфигурация компилятора C для 32-bit Bare-Metal ---
set(CMAKE_C_FLAGS "-m32 -ffreestanding -fno-pie -mno-sse -mno-sse2 -mno-sse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -mfpmath=387")
set(CMAKE_BUILD_TYPE Debug)

# --- 2. Компиляция MBR загрузчика в объектный файл elf32 ---
set(BOOTLOADER_OBJ ${CMAKE_CURRENT_BINARY_DIR}/AsemblerObjects/boot.o)

add_custom_command(
        OUTPUT ${BOOTLOADER_OBJ}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/AsemblerObjects
        COMMAND ${NASM_EXEC} -f elf32 ${CMAKE_CURRENT_SOURCE_DIR}/boot.asm -o ${BOOTLOADER_OBJ}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/boot.asm
        COMMENT "Компиляция MBR загрузчика boot.asm -> elf32 объект..."
)

# Создаём цель-пустышку, чтоб сформировать зависимость цели os_elf от существования boot.o
add_library(boot_obj OBJECT boot.asm)
set_target_properties(boot_obj PROPERTIES
        #ASM_NASM_FLAGS "-f elf32"
        LINKER_LANGUAGE ASM_NASM
)

add_custom_target(compile_boot DEPENDS ${BOOTLOADER_OBJ})

# --- 3. Компиляция остальных .asm файлов ядра ---
file(GLOB_RECURSE KERNEL_ASM_SRCS "source/asm/*.asm")

set(KERNEL_ASM_OBJS "")
foreach(ASM_FILE ${KERNEL_ASM_SRCS})
    get_filename_component(ASM_NAME ${ASM_FILE} NAME_WE)
    set(OBJ_FILE "${CMAKE_CURRENT_BINARY_DIR}/AsemblerObjects/${ASM_NAME}_asm.o")

    add_custom_command(
            OUTPUT ${OBJ_FILE}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/AsemblerObjects
            COMMAND ${NASM_EXEC} -f elf32 -I"${CMAKE_CURRENT_SOURCE_DIR}/source/headers/" ${ASM_FILE} -o ${OBJ_FILE}
            DEPENDS ${ASM_FILE}
            COMMENT "Компиляция ассемблера ядра: ${ASM_NAME}.asm -> elf32"
    )
    set_source_files_properties(${OBJ_FILE} PROPERTIES GENERATED TRUE)
    list(APPEND KERNEL_ASM_OBJS ${OBJ_FILE})

endforeach()

# --- 4. Единая линковка (ld boot.o kernel.o ... -> os.elf) ---
add_executable(os_elf
        kernel.c
        source/stack_chk_fail.c
        ${KERNEL_ASM_OBJS}
)

add_dependencies(os_elf compile_boot)

# Настройки линковщика (соответствуют флагу -T link.ld)
target_link_options(os_elf PRIVATE
        "-std=c99"
        "-m32"
        "-O2"
        "-ffreestanding"
        "-no-pie"
        "-fno-pie"
        "-mno-sse"
        "-fno-stack-protector"
        "-nostdlib"
        "-Wl,-T,${CMAKE_CURRENT_SOURCE_DIR}/kernel.ld" # Ваш скрипт линковщика
)

target_include_directories(os_elf PRIVATE source/headers)

# --- 5. Извлечение финального плоского бинарника ОС (objcopy -> tmp_boot.img) ---
set(OS_BIN ${CMAKE_CURRENT_BINARY_DIR}/Binary/tmp_boot.img)

add_custom_command(
        OUTPUT ${OS_BIN}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Binary
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:os_elf> ${OS_BIN}
        DEPENDS os_elf
        COMMENT "Извлечение плоского бинарного файла из os_elf"
)

# --- 6. Создание финального образа дискеты (boot.img на Диске) ---
set(IMAGE_FILE ${CMAKE_CURRENT_BINARY_DIR}/Binary/boot.img)

# Заменяем add_custom_command на add_custom_target, чтобы CMake жестко контролировал этот этап
add_custom_target(build_boot_image ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Binary
        COMMAND dd if=/dev/zero of=${IMAGE_FILE} bs=1024 count=1440 2>/dev/null
        COMMAND dd if=${OS_BIN} of=${IMAGE_FILE} conv=notrunc 2>/dev/null
        COMMAND ${CMAKE_COMMAND} -E rm -f ${OS_BIN}

        DEPENDS ${OS_BIN}
        COMMENT "Сборка финального образа дискеты boot.img на диск..."
)

# Указываем, что образ дискеты жестко зависит от компиляции os_elf
add_dependencies(build_boot_image os_elf)
