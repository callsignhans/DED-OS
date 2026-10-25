//
// Created by adminguns on 25.10.2026.
//

#ifndef MBRBOOTLOADER_KERNEL_IPLEMENTATION_INTERRUPTS_H
#define MBRBOOTLOADER_KERNEL_IPLEMENTATION_INTERRUPTS_H

#include "../headers/utility_assert.h"

void assert_enable(assert *error_assert);
void kernel_panic(const char* str, ...);
void kernel_panic_v(const char* str, va_list args);

#endif //MBRBOOTLOADER_KERNEL_IPLEMENTATION_INTERRUPTS_H
