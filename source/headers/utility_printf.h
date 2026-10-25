//
// Created by modnick on 28.10.2024.
//

#ifndef FYRFYROS_PRINTF_H
#define FYRFYROS_PRINTF_H

#include "_flags.h"
#include "_macroses.h"
#include "utility_va_list.h"

void print_fyr(char* str, ...);
void print_int(i32 number);
void print_hex(i32 number);
void print_unsigned_hex(i32 number);
void print_str(char *anInt);
void print_fyr_v(char* str, va_list list);

#endif //FYRFYROS_PRINTF_H
