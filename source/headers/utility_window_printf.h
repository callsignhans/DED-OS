//
// Created by adminguns on 24.10.2026.
//

#ifndef MBRBOOTLOADER_WINDOW_PRINT_H
#define MBRBOOTLOADER_WINDOW_PRINT_H

#include "kernel_window.h"

extern

void window_print_fyr(window* wind, char* str, ...);
void window_print_int(window* wind, i32 number);
void window_print_hex(window* wind, i32 number);
void window_print_unsigned_hex(window* wind, i32 number);
void window_print_str(window* wind, char *anInt);

#endif //MBRBOOTLOADER_WINDOW_PRINT_H
