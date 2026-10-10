global assembler_while

assembler_while:
    .start:
        jmp .start


assembler_write_test:
    .start:
        mov eax, 0xB8000
    .loop:
        mov [eax], 'C'
        mov [eax + 1], 0xBB
        add eax, 2
        cmp eax, 0xB8100
        jnz .loop
        jmp .start
