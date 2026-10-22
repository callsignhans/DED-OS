//
// Created by adminguns on 05.07.2026.
//

#ifndef MBRBOOTLOADER_ASSERT_H
#define MBRBOOTLOADER_ASSERT_H


#include "kernel_allocator.h"

    typedef struct assert {
        int line;
        const char* name_function;
        const char* name_file;
        const char* condition;
        const char* massage;

    } assert;

    extern void assert_interrupt(assert* text, ...);

    assert* create_assert(int line, const char* function,const char* file, const char* condition, const char* massage);

#ifdef DEBUG_MODE
    #define ASSERT(condition, ...)                                                                          \
        if (!(condition)) {                                                                                 \
            assert* result = create_assert(__LINE__, __FUNCTION__, __FILE_NAME__, #condition,               \
                FIRST_ARG_HELPER(__VA_ARGS__));                                                             \
            assert_interrupt(result, __VA_ARGS__);                                                          \
        }
#else
    #define ASSERT(condition, massage)
#endif


#ifdef DEBUG_MODE
    #define ASSERT_NOT_COND(...)                                                                            \
    {                                                                                                       \
        assert* result = create_assert(__LINE__, __FUNCTION__, __FILE_NAME__, "assert hasn't condition",    \
            FIRST_ARG_HELPER(__VA_ARGS__));                                                                 \
        assert_interrupt(result, __VA_ARGS__);                                                              \
    }
#else
    #define ASSERT_NOT_COND(massage)
#endif

#endif //MBRBOOTLOADER_ASSERT_H
