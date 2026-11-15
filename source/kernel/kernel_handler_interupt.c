//
// Created by modnick on 23.11.2024.
//

#include "kernel_handler_interupt.h"

#include "kernel_panic.h"
#include "utility_asm_fuctions.h"
#include "utility_logger.h"


void interrupt_handler(context* ctx) {
    switch (ctx->vector) {
        case 0x8:
            abort_handler(ctx);
            break;
        default:
            trap_handler(ctx);
            break;
    }
}

void trap_handler(context* ctx) {
    print_context(ctx);
    endless_loop();
}

void fault_handler(context* ctx) {
    print_context(ctx);
    endless_loop();
}

void abort_handler(context* ctx) {
    print_context(ctx);
    endless_loop();
}

void print_context(context* ctx) {
    vga_clear_screen();
    print_fyr("\r\nKernel panic: unhandled interrupt %x, interrupted process context:\r\n", ctx->vector);
    print_fyr("  EAX = %x ", ctx->eax);
    print_fyr("ECX = %x ", ctx->ecx);
    print_fyr("EDX = %x ", ctx->edx);
    print_fyr("EBX = %x\r\n", ctx->ebx);
    print_fyr("  ESP = %x ", ctx->esp);
    print_fyr("EBP = %x ", ctx->ebp);
    print_fyr("ESI = %x ", ctx->esi);
    print_fyr("EDI = %x\r\n", ctx->edi);
    print_fyr("  DS  = %x ", ctx->ds);
    print_fyr("ES  = %x ", ctx->es);
    print_fyr("FS  = %x ", ctx->fs);
    print_fyr("GS  = %x\r\n", ctx->gs);
    print_fyr("  CS  = %x ", ctx->cs);
    print_fyr("EIP = %x ", ctx->eip);
    print_fyr("EFLAGS = %x\r\n", ctx->eflags);
    print_fyr("  error code = %x\r\n", ctx->error_code);
}

