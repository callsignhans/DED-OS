//
// Created by adminguns on 05.07.2026.
//

#include "../headers/utility_assert.h"


assert* create_assert(int line, const char* function, const char* file, const char* condition,
        const char* massage, ...) {
    va_list arguments;
    va_start(arguments, massage);
    assert* result = kernel_malloc(sizeof(assert));
    result->line = line;
    result->name_function = function;
    result->name_file = file;
    result->condition = condition;
    result->massage = massage;
    result->arguments = arguments;
    return result;
}
