//
// Created by adminguns on 25.11.2026.
//

#ifndef MBRBOOTLOADER__STRUCTS_H
#define MBRBOOTLOADER__STRUCTS_H

#include <stdarg.h>

#include "_macroses.h"

typedef struct utility_assert {
    int line;
    const char* name_function;
    const char* name_file;
    const char* condition;
    const char* massage;
    va_list arguments;
} assert;

#pragma pack(push, 1)
typedef struct context {
    u32 edi;
    u32 esi;
    u32 ebp;
    u32 esp;
    u32 ebx;
    u32 edx;
    u32 ecx;
    u32 eax;
    u16 gs;
    u16 padding_1;
    u16 fs;
    u16 padding_2;
    u16 es;
    u16 padding_3;
    u16 ds;
    u16 padding_4;
    u32 vector;
    u32 error_code;
    u32 eip;
    u16 cs;
    u16 padding_5;
    u32 eflags;
} context;
#pragma pack(pop)

#endif //MBRBOOTLOADER__STRUCTS_H
