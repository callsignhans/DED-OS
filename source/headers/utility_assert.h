//
// Created by adminguns on 05.07.2026.
//

#ifndef MBRBOOTLOADER_ASSERT_H
#define MBRBOOTLOADER_ASSERT_H


#include "utility_allocator.h"
#include <stdarg.h>

typedef struct utility_assert {
        int line;
        const char* name_function;
        const char* name_file;
        const char* condition;
        const char* massage;
        va_list arguments;
    } assert;

    extern void assert_interrupt(assert* text);

    assert* assert_create(int line, const char* function,const char* file, const char* condition,
        const char* massage, ...);
    void assert_print(assert* assert);
    void assert_catch(assert* assert);


#ifdef DEBUG_MODE
    #define ASSERT(condition, ...)                                                                          \
        if (!(condition)) {                                                                                 \
            assert* result = assert_create(__LINE__, __FUNCTION__, __FILE_NAME__, #condition, __VA_ARGS__); \
            assert_catch(result);                                                          \
        }
#else
    #define ASSERT(condition, ...)
#endif

#endif //MBRBOOTLOADER_ASSERT_H
