//
// Created by adminguns on 25.10.2026.
//

#include "kernel_panic.h"
#include "utility_printf.h"
#include "driver_vga.h"
#include "utility_asm_fuctions.h"

extern void assembler_while();


void kernel_panic(const char* str, ...) {
    cli_api();
    va_list args;
    va_start(args, str);
    kernel_panic_v(str, args);
}

void kernel_panic_v(const char* str, va_list args) {
    cli_api();
    vga_clear_screen();
    print_str_color("Guilty, but the task was not completed...\r\nKERNEL PANIC\r\n", red_f, black_b);
    print_fyr_v(str, args);
    endless_loop();
}