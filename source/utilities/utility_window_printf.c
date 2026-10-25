//
// Created by adminguns on 24.10.2026.
//

#include "../headers/utility_window_printf.h"
#include "../headers/utility_va_list.h"
#include "../headers/kernel_window.h"

void window_print_str(window* wind, char *str) {
    for (i32 i = 0; str[i] != 0; ++i) {
        window_vga_print_char_carriage(wind, str[i], white_f, black_b);
    }
}

void window_print_fyr(window* wind, char* str, ...) {
    va_list list;
    va_start(list, str);
    for (i32 i = 0; str[i] != 0; ++i) {
        if (str[i] == '%') {
            i++;
            switch (str[i]) {
                case 'd': {
                    i32 number = va_arg(list, i32);
                    window_print_int(wind, number);
                    break;
                }
                case 'x': {
                    i32 number = va_arg(list, i32);
                    window_print_unsigned_hex(wind, number);
                    break;
                }
                case 's': {
                    char* string = va_arg(list, char*);
                    window_print_str(wind, string);
                    break;
                }
                case '%': {
                    window_vga_print_char_carriage(wind, '%', white_f, black_b);
                    break;
                }
            }
        } else {
            window_vga_print_char_carriage(wind, str[i], white_f, black_b);
        }
    }
}

void window_print_int(window* wind, i32 number) {
    if (number == -number) {
        window_print_str(wind, "-2147483648\0");
        return;
    }
    if (number < 0) {
        window_vga_print_char_carriage(wind, '-', white_f, black_b);
        number = -number;
    }

    if (number == 0) {
        window_vga_print_char_carriage(wind, '0', white_f, black_b);
        return;
    }

    char buffer[10];
    i32 i = 0;

    while (number > 0) {
        buffer[i++] = (char)((number % 10) + '0');
        number /= 10;
    }

    for (i32 j = i - 1; j >= 0; j--) {
        window_vga_print_char_carriage(wind, buffer[j], white_f, black_b);
    }
}

void window_print_hex(window* wind, i32 number) {
    if (number == -number) {
        window_print_str(wind, "-0x80000000\0");
        return;
    }
    if (number < 0) {
        window_vga_print_char_carriage(wind, '-', white_f, black_b);
        number = -number;
    }

    window_vga_print_char_carriage(wind, '0', white_f, black_b);
    window_vga_print_char_carriage(wind, 'x', white_f, black_b);

    char buffer[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
    i32 i = 0;

    while (number > 0) {
        i32 remainder = number % 16;
        buffer[i++] = (char)(remainder < 10 ? remainder + '0' : remainder - 10 + 'A');
        number /= 16;
    }

    i = 8;
    for (i32 j = i - 1; j >= 0; j--) {
        window_vga_print_char_carriage(wind, buffer[j], white_f, black_b);
    }
}

void window_print_unsigned_hex(window* wind, i32 number) {
    if (number == -number) {
        window_print_str(wind, "0x80000000\0");
        return;
    }
    u32 unsigned_number = (u32)number;

    window_vga_print_char_carriage(wind, '0', white_f, black_b);
    window_vga_print_char_carriage(wind, 'x', white_f, black_b);

    char buffer[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
    i32 i = 0;

    while (unsigned_number > 0) {
        u32 remainder = unsigned_number % 16;
        buffer[i++] = (char)(remainder < 10 ? remainder + '0' : remainder - 10 + 'A');
        unsigned_number /= 16;
    }

    i = 8;
    for (i32 j = i - 1; j >= 0; j--) {
        window_vga_print_char_carriage(wind, buffer[j], white_f, black_b);
    }
}
