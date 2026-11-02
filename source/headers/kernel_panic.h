//
// Created by adminguns on 25.10.2026.
//

#ifndef MBRBOOTLOADER_KERNEL_PANIC_H
#define MBRBOOTLOADER_KERNEL_PANIC_H

#include "utility_assert.h"

void kernel_panic(const char* str, ...);
void kernel_panic_v(const char* str, va_list args);

#endif //MBRBOOTLOADER_KERNEL_PANIC_H
