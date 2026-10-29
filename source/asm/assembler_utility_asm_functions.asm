global cli_api
global sti_api
global endless_loop

cli_api:
    cli
    ret

sti_api:
    sti
    ret

endless_loop:
    .start:
        jmp .start
    ret