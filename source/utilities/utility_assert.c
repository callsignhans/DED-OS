//
// Created by adminguns on 05.07.2026.
//

#include "utility_assert.h"
#include "utility_printf.h"
#include "kernel_panic.h"

void assert_catch(int line, const char* function, const char* file, const char* condition,
                  const char* massage, ...) {
    va_list arguments;
    va_start(arguments, massage);
    assert result;
    result.line = line;
    result.name_function = function;
    result.name_file = file;
    result.condition = condition;
    result.massage = massage;
    result.arguments = arguments;
    kernel_panic("I FIND ASSERT, COMRADE \r\n%a", &result);
}

