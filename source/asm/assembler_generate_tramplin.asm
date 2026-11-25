[BITS 32]

global trampoline_with_errorcode_start
global trampoline_with_errorcode_end
global trampoline_without_errorcode_start
global trampoline_without_errorcode_end
global vector_number

extern interrupt_handler

vector_number:
    dd 0x00000000

trampoline_with_errorcode_start:
    push 0xffffffff
    push eax
    mov eax, generate_collect_context
    jmp eax
trampoline_with_errorcode_end:

trampoline_without_errorcode_start:
    push 0xDEADC0DE
    push 0xffffffff
    push eax
    mov eax, generate_collect_context
    jmp eax
trampoline_without_errorcode_end:


generate_collect_context:
    mov eax, [vector_number]
    mov [esp + 4], eax
    pop eax
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

