//
// Created by adminguns on 24.10.2026.
//

#ifndef MBRBOOTLOADER_MEMORY_OPERATION_H
#define MBRBOOTLOADER_MEMORY_OPERATION_H
#include "_macroses.h"

void memory_move(void* dst, const void* src, size_t size);
void memory_copy(void* dst, const void* src, size_t size);
void memory_fill_zero(void* dst, size_t size);

#endif //MBRBOOTLOADER_MEMORY_OPERATION_H
