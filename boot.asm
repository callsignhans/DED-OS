[BITS 16]

start:
	cli                 ; Отключаем прерывания
	xor cx, cx          ; Зануляем bx, запись для записи в регистр
	mov ss, cx          ; Устанавливаем базу стека
	mov sp, 0x7C00      ; Устанавливаем верхнюю границу стека на ячейку в которую выгружается загрузчик
	sti                 ; Включаем прерывания

    inc cl
	mov si, 0x7C0       ; Заполняем регистр ax, запись для записи в регистр
	mov ds, si          ; Устанавливаем cегмент данных

driver_read:
        xor dh, dh       ;
.loop:
        add si, 0x20
        inc cl
        cmp cl, 19
        jnz .post
        mov cl, 1
        add ch, dh
        xor dh, cl
.post:      
        mov es, si
.return:
        mov ax, 0x0201
        int 0x13
        jc .return
        cmp si, 0x7FE0
        jnz .loop
.end:
        jmp .end

times 510-($-$$) db 0
dw 0xAA55

