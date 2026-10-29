//
// Created by adminguns on 05.07.2026.
//

#include "../headers/utility_assert.h"
#include "../headers/utility_printf.h"
#include "../headers/utility_asm_fuctions.h"

assert* assert_create(int line, const char* function, const char* file, const char* condition,
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

void assert_catch(assert* assert) {
    cli_api();
    assert_print(assert);
    endless_loop();
}

void assert_print(assert *error_assert) {
    print_fyr("I FIND ASSERT, COMRADE \r\n");
    print_fyr("Line: %d\r\n", error_assert->line);
    print_fyr("Function: %s\r\n", error_assert->name_function);
    print_fyr("File: %s\r\n", error_assert->name_file);
    print_fyr("Condition assert: %s\r\n", error_assert->condition);
    print_fyr("Description: ");
    print_fyr_v(error_assert->massage, error_assert->arguments);
}
