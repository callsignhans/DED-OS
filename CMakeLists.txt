cmake_minimum_required(VERSION 3.10)
project(MbrBootloader NONE)

# Включаем ТОЛЬКО Си. Ассемблер будем контролировать вручную.
enable_language(C)

# Находим NASM в системе
find_program(NASM_EXEC nasm REQUIRED)

# --- 1. Конфигурация компилятора C для 32-bit Bare-Metal ---
set(CMAKE_C_FLAGS "-m32 -ffreestanding -fno-pie -mno-sse -mno-sse2 -mno-sse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -mfpmath=387")
set(CMAKE_BUILD_TYPE Debug)

# --- 2. Сборка Загрузчика (boot.bin) ---
set(BOOTLOADER_BIN ${CMAKE_CURRENT_BINARY_DIR}/Binary/boot.bin)

add_custom_command(
        OUTPUT ${BOOTLOADER_BIN}
        COMMAND ${NASM_EXEC} -f bin ${CMAKE_CURRENT_SOURCE_DIR}/boot.asm -o ${BOOTLOADER_BIN}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/boot.asm
        COMMENT "Компиляция MBR загрузчика boot.asm -> boot.bin..."
)
add_custom_target(bootloader DEPENDS ${BOOTLOADER_BIN})

#

# --- 3. Сборка Ядра (kernel.bin) ---
file(GLOB_RECURSE KERNEL_ASM_SRCS "source/asm/*.asm")

# Вручную компилируем каждый .asm файл ядра в объектный файл elf32
set(KERNEL_ASM_OBJS "")
foreach(ASM_FILE ${KERNEL_ASM_SRCS})
    # Получаем имя файла без расширения и пути
    get_filename_component(ASM_NAME ${ASM_FILE} NAME_WE)
    set(OBJ_FILE "${CMAKE_CURRENT_BINARY_DIR}/asm-obj/${ASM_NAME}_asm.o")

    add_custom_command(
            OUTPUT ${OBJ_FILE}
            # Принудительно передаем -f elf32 и подключаем заголовочную папку
            COMMAND ${NASM_EXEC} -f elf32 -I"${CMAKE_CURRENT_SOURCE_DIR}/source/headers/" ${ASM_FILE} -o ${OBJ_FILE}
            DEPENDS ${ASM_FILE}
            COMMENT "Компиляция ассемблера ядра: ${ASM_NAME}.asm -> elf32"
    )
    list(APPEND KERNEL_ASM_OBJS ${OBJ_FILE})
endforeach()
#[[
# Собираем Си-файлы ядра и подкидываем к ним наши скомпилированные elf32 объекты
add_executable(kernel_elf kernel.c source/floppy_driver.c
        source/handler_interupt.c
        source/intel8259A.c
        source/kernel_allocator.c
        source/loger.c
        source/page_allocator.c
        source/page_translator.c
        source/printf.c
        source/process.c
        source/stack_chk_fail.c
        source/tramplins.c
        source/vga_driver.c
        ${KERNEL_ASM_OBJS}
        source/intel8042.c
        source/assert.c
        source/drivers/ps2_keyboard.c
        source/headers/ps2_keyboard.h
        source/drivers/ps2_mouse.c
        source/headers/ps2_mouse.h)

# Настройки линковки 32-битного ядра с использованием скрипта компоновщика
target_link_options(kernel_elf PRIVATE
        "-m32"
        "-Wl,-m,elf_i386"
        "-static"
        "-nostdlib"
        "-Wl,-T,${CMAKE_CURRENT_SOURCE_DIR}/kernel.ld"
)

target_include_directories(kernel_elf PRIVATE source/headers)

# Извлекаем плоский бинарник ядра из ELF
set(KERNEL_BIN ${CMAKE_CURRENT_BINARY_DIR}/Binary/kernel.bin)
add_custom_command(
        OUTPUT ${KERNEL_BIN}
        COMMAND ${CMAKE_OBJCOPY} -O Binary $<TARGET_FILE:kernel_elf> ${KERNEL_BIN}
        DEPENDS kernel_elf
        COMMENT "Извлечение бинарного кода ядра (objcopy)..."
)
add_custom_target(kernel_bin DEPENDS ${KERNEL_BIN})
]]

# --- 4. Создание финального образа дискеты 1.44МБ (boot.img) ---
set(IMAGE_FILE ${CMAKE_CURRENT_BINARY_DIR}/Binary/boot.img)

add_custom_command(
        OUTPUT ${IMAGE_FILE}
        # Гарантируем, что папка Binary существует перед записью dd
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Binary
        COMMAND dd if=/dev/zero of=${IMAGE_FILE} bs=1024 count=1440 2>/dev/null
        COMMAND dd if=${BOOTLOADER_BIN} of=${IMAGE_FILE} conv=notrunc 2>/dev/null
        #COMMAND dd if=${KERNEL_BIN} of=${IMAGE_FILE} conv=notrunc seek=1 2>/dev/null

        # КРИТИЧЕСКОЕ ИСПРАВЛЕНИЕ: привязываемся к путям файлов, а не к таргетам-пустышкам
        DEPENDS ${BOOTLOADER_BIN} ${KERNEL_BIN}

        COMMENT "Сборка финального образа дискеты boot.img..."
)

# Этот таргет заставляет всю цепочку работать при сборке проекта
add_custom_target(image ALL DEPENDS ${IMAGE_FILE})
