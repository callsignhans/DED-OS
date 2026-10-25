//
// Created by adminguns on 05.07.2026.
//

#ifndef MBRBOOTLOADER_ASSERT_H
#define MBRBOOTLOADER_ASSERT_H


#include "utility_allocator.h"
#include "utility_va_list.h"

typedef struct utility_assert {
        int line;
        const char* name_function;
        const char* name_file;
        const char* condition;
        const char* massage;
        va_list arguments;
    } assert;

    extern void assert_interrupt(assert* text);

    assert* create_assert(int line, const char* function,const char* file, const char* condition,
        const char* massage, ...);

#ifdef DEBUG_MODE
    #define ASSERT(condition, ...)                                                                          \
        if (!(condition)) {                                                                                 \
            assert* result = create_assert(__LINE__, __FUNCTION__, __FILE_NAME__, #condition, __VA_ARGS__); \
            assert_interrupt(result);                                                          \
        }
#else
    #define ASSERT(condition, ...)
#endif


#ifdef DEBUG_MODE
    #define ASSERT_NOT_COND(...)                                                                            \
    {                                                                                                       \
        assert* result = create_assert(__LINE__, __FUNCTION__, __FILE_NAME__, "assert hasn't condition",    \
            __VA_ARGS__);                                                                 \
        assert_interrupt(result);                                                                           \
    }
#else
    #define ASSERT_NOT_COND(...)
#endif

#endif //MBRBOOTLOADER_ASSERT_H
