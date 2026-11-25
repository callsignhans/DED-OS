//
// Created by modnick on 23.11.2024.
//

#include "kernel_handler_interupt.h"

#include "kernel_panic.h"
#include "utility_asm_fuctions.h"
#include "utility_logger.h"
#include "utility_printf.h"


void interrupt_handler(context* ctx) {

    if ((ctx->vector >= START_VECTOR_MASTER && ctx->vector < END_VECTOR_MASTER) ||
        (ctx->vector >= START_VECTOR_SLAVE && ctx->vector < END_VECTOR_SLAVE)) {
        intel8259_start_interrupt(ctx->vector, ctx);
        return;
    }
    switch (ctx->vector) {
        default:
            trap_handler(ctx);
            break;
    }
}

void timer(context* ctx) {
    static int test = 0;
    vga_clear_screen();
    print_hex(test);
    test++;
    intel8259_eoi(master);
}

void trap_handler(context* ctx) {
    kernel_panic("%c", ctx);
}

void fault_handler(context* ctx) {
    print_context(ctx);
    endless_loop();
}

void abort_handler(context* ctx) {
    print_context(ctx);
    endless_loop();
}


