//
// Created by modnick on 28.10.2024.
//

#ifndef FYRFYROS_PRINTF_H
#define FYRFYROS_PRINTF_H

#include <stdarg.h>

#include "_macroses.h"
#include "_structs.h"
#include "driver_vga.h"

void print_fyr(char* str, ...);
void print_fyr_v(char* str, va_list list);
void print_int(i32 number);
void print_hex(i32 number);
void print_unsigned_hex(i32 number);
void print_str(char *anInt);
void print_str_color(char *str, color_front cf, color_back cb);
void assert_print(const assert* assert);
void print_context(const context* ctx);

#endif //FYRFYROS_PRINTF_H
