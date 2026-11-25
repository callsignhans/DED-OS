//
// Created by modnick on 28.10.2024 and Anqeliccom on 30.12.2024, 24.11.2024
//

#include <stdarg.h>

#include "driver_vga.h"
#include "_structs.h"
#include "utility_printf.h"
#include "utility_assert.h"

void print_fyr(char* str, ...) {
    va_list list;
    va_start(list, str);
    print_fyr_v(str, list);
}

void print_fyr_v(char* str, va_list list) {
    for (i32 i = 0; str[i] != 0; ++i) {
        if (str[i] == '%') {
            i++;
            switch (str[i]) {
                case 'd': {
                    i32 number = va_arg(list, i32);
                    print_int(number);
                    break;
                }
                case 'x': {
                    i32 number = va_arg(list, i32);
                    print_unsigned_hex(number);
                    break;
                }
                case 's': {
                    char* string = va_arg(list, char*);
                    print_str(string);
                    break;
                }
                case '%': {
                    vga_print_char_carriage('%', white_f, black_b);
                    break;
                }
                case 'a': {
                    assert* asrt = va_arg(list, assert*);
                    assert_print(asrt);
                    break;
                }
                case 'c':
                    context* ctx = va_arg(list, context*);
                    print_context(ctx);
                default: {
                    break;
                }
            }
        } else {
            vga_print_char_carriage(str[i], white_f, black_b);
        }
    }
}

void print_int(i32 number) {
    if (number == -2147483647 - 1) {
        print_str("-2147483648");
        return;
    }
    if (number < 0) {
        vga_print_char_carriage('-', white_f, black_b);
        number = -number;
    }

    if (number == 0) {
        vga_print_char_carriage('0', white_f, black_b);
        return;
    }

    char buffer[10];
    i32 i = 0;

    while (number > 0) {
        buffer[i++] = (char)((number % 10) + '0');
        number /= 10;
    }

    for (i32 j = i - 1; j >= 0; j--) {
        vga_print_char_carriage(buffer[j], white_f, black_b);
    }
}

void print_hex(i32 number) {
    if (number < 0) {
        vga_print_char_carriage('-', white_f, black_b);
        number = -number;
    }

    vga_print_char_carriage('0', white_f, black_b);
    vga_print_char_carriage('x', white_f, black_b);

    char buffer[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
    i32 i = 0;

    while (number > 0) {
        i32 remainder = number % 16;
        buffer[i++] = (char)(remainder < 10 ? remainder + '0' : remainder - 10 + 'A');
        number /= 16;
    }

    i = 8;
    for (i32 j = i - 1; j >= 0; j--) {
        vga_print_char_carriage(buffer[j], white_f, black_b);
    }
}

void print_unsigned_hex(i32 number) {
    u32 unsigned_number = (u32)number;

    vga_print_char_carriage('0', white_f, black_b);
    vga_print_char_carriage('x', white_f, black_b);

    char buffer[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
    i32 i = 0;

    while (unsigned_number > 0) {
        u32 remainder = unsigned_number % 16;
        buffer[i++] = (char)(remainder < 10 ? remainder + '0' : remainder - 10 + 'A');
        unsigned_number /= 16;
    }

    i = 8;
    for (i32 j = i - 1; j >= 0; j--) {
        vga_print_char_carriage(buffer[j], white_f, black_b);
    }
}


void print_str(char *str) {
    print_str_color(str, white_f, black_b);
}

void print_str_color(char *str, color_front cf, color_back cb) {
    for (i32 i = 0; str[i] != 0; ++i) {
        vga_print_char_carriage(str[i], cf, cb);
    }
}

void print_context(const context* ctx) {
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

void assert_print(const assert *error_assert) {
    print_fyr("Line: %d\r\n", error_assert->line);
    print_fyr("Function: %s\r\n", error_assert->name_function);
    print_fyr("File: %s\r\n", error_assert->name_file);
    print_fyr("Condition assert: %s\r\n", error_assert->condition);
    print_fyr("Description: ");
    print_fyr_v(error_assert->massage, error_assert->arguments);
}
