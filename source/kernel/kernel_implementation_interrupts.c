//
// Created by adminguns on 25.10.2026.
//

#include "../headers/kernel_ipmlementation_interrupts.h"
#include "../headers/utility_printf.h"
#include "../headers/utility_assert.h"
#include "../headers/driver_vga.h"
#include "../headers/utility_asm_fuctions.h"

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
    print_fyr("Guilty, but the task was not completed...\r\nKERNEL PANIC\r\n");
    print_fyr_v(str, args);
    endless_loop();
}