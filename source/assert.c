//
// Created by adminguns on 05.07.2026.
//

#include "headers/assert.h"


    assert* create_assert(int line, const char* function, const char* file, const char* condition, const char* message) {
        assert* result = kernel_malloc(sizeof(assert));
        result->line = line;
        result->name_function = function;
        result->name_file = file;
        result->condition = condition;
        result->massage = message;
        return result;
    }
