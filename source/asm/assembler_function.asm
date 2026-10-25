extern assert_enable

global assert_interrupt
global assembler_while

assembler_while:
    .start:
        jmp .start

assert_interrupt:
    mov eax, [esp + 4]
    push eax
    call assert_enable
    pop eax
    ret
