[BITS 16]

global start
 start:
 	cli                 ; Отключаем прерывания
 	xor bx, bx          ; Зануляем bx, обнуляем для записи в ss, и одновременно для команды int 0x13 выставляем смещение адреса записи
 	mov ss, bx          ; Устанавливаем базу стека на 0
 	mov sp, 0x7C00      ; Устанавливаем верхнюю границу стека на ячейку в которую выгружается загрузчик

     mov cx, 1           ; Устанавливаем в байты номера цилиндра 0, а в сектора 1, чтоб потом он инкрементировался сразу до 2
 	mov si, 0x7C0       ; Заполняем регистр si, из смещение базы сегмента 0x7C00 << 4, также после добавлении 0x20 сразу установим базу адреса записи на 0x7E00;
 	mov ds, si          ; Устанавливаем cегмент данных на 0x7C00

 driver_read:
         xor dh, dh      ; Зануляем указатель на головку, нижнюю часть регистра не зануляем, в нём лежит установленный bios номер диска
 .loop:
         add si, 0x20    ; Смещаем адрес записи на 512 байт
         inc cl          ; Инкрементируем номера сектора
         cmp cl, 19      ; Проверка заходим ли за максимальное количество секторов на дискете т.е за 18
         jnz .post       ; Если всё ОК, то сразу переходим к чтению
         mov cl, 1       ; Сбрасываем в самое начало номер читаемого сектора
         add ch, dh      ; Прибавляем к номеру цилиндра номер головки, это корректно ведь если головка равна нулю, то номер цилиндра не меняется, если равна 1 то инкрементировать и нужно
         xor dh, cl      ; dh меняется на противоположный
 .post:
         mov es, si      ; Сдвигаем адрес записи
         mov di, 4
 .return:
         mov ax, 0x0201  ; Задаём в ah - номер команды чтения с диска, al - количество читаемых секторов
         int 0x13        ; Производим чтение
         jc .error
         cmp si, 0x7FE0  ; Смотрим сколько уже выгруженно (0x8FE00 - 0x7E00 = 480кб)
         jnz .loop       ; Переходим в начало цикла если не превысили 480 кб
         jmp protected_mode_enable
.error
         inc di
         jnz .return


protected_mode_enable:
        cli
        ;cld
        mov ax, 0x7c00
        lgdt [gdt_descriptor - 0x7C00]
        mov eax, cr0
        or al, 1
        mov cr0, eax
        jmp dword CODE_SEG:protected_mode_tramplin

[BITS 32]
protected_mode_tramplin:
        cli
        mov bx, DATA_SEG
        mov ds, bx
        mov ss, bx
        mov es, bx
        mov fs, bx
        mov gs, bx
[EXTERN kernel_entry]
        jmp kernel_entry

gdt_start:
        dq 0x0
gdt_code:
        dw 0xFFFF
        dw 0x0000
        db 0x00
        db 0x9A
        db 0xCF
        db 0x00
gdt_data:
        dw 0xFFFF
        dw 0x0000
        db 0x00
        db 0x92
        db 0xCF
        db 0x00
gdt_end:

gdt_descriptor:
        dw gdt_end - gdt_start - 1
        dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

times 510-($-$$) db 0
dw 0xAA55

