global cli_api
global sti_api
global get_cs_api
global endless_loop
global lidt_api
global call_int_104
global outb_api
global inb_api

cli_api:
    cli
    ret

sti_api:
    sti
    ret

get_cs_api:
    mov eax, cs
    ret

lidt_api:
    mov eax, [esp + 4]
    lidt [eax]
    ret

endless_loop:
    .start:
        jmp .start
    ret

call_int_104:
    int 104
    ret

outb_api:
    mov edx, [esp + 4]
    mov eax, [esp + 8]
    out dx, al
    ret

inb_api:
    mov edx, [esp + 4]
    mov eax, -1
    in al, dx
    ret
