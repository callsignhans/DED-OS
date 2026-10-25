//
// Created by adminguns on 25.10.2026.
//

#include "../headers/kernel_ipmlementation_interrupts.h"
#include "../headers/utility_printf.h"
#include "../headers/utility_assert.h"
#include "../headers/driver_vga.h"
#include "../headers/utility_asm_fuctions.h"

extern void assembler_while();

void assert_enable(assert *error_assert) {
    print_fyr("I FIND ASSERT, COMRADE \r\n");
    print_fyr("Line: %d\r\n", error_assert->line);
    print_fyr("Function: %s\r\n", error_assert->name_function);
    print_fyr("File: %s\r\n", error_assert->name_file);
    print_fyr("Condition assert: %s\r\n", error_assert->condition);
    print_fyr("Description: ");
    print_fyr_v(error_assert->massage, error_assert->arguments);
    assembler_while();
}

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
}