extern assert_catch

global assert_interrupt

assert_interrupt:
    mov eax, [esp + 4]
    push eax
    call assert_catch
    pop eax
    ret
