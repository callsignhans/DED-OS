[BITS 32]

global trampoline_with_errorcode_start
global trampoline_with_errorcode_end
global trampoline_without_errorcode_start
global trampoline_without_errorcode_end

extern interrupt_handler

trampoline_with_errorcode_start:
    push eax
    mov eax, generate_collect_context
    jmp eax
trampoline_with_errorcode_end:

trampoline_without_errorcode_start:
    push 0xDEADC0DE
    push eax
    mov eax, generate_collect_context
    jmp eax
trampoline_without_errorcode_end:


generate_collect_context:
    push ds
    push es
    push fs
    push gs
    pusha
    mov ebx, esp
    mov eax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    and esp, -16
    sub esp, 12
    push ebx
    call interrupt_handler
    mov esp, ebx
    popa
    pop gs
    pop fs
    pop es
    pop ds
    add esp, 8
    iretd

