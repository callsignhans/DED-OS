//
// Created by adminguns on 02.11.2026.
//

#ifndef MBRBOOTLOADER_UTILLITY_ENDLESS_ALLOCATOR_H
#define MBRBOOTLOADER_UTILLITY_ENDLESS_ALLOCATOR_H

#include <stddef.h>

#include "_macroses.h"

#define START_ALLOCATOR_ADDRESS ((u32)_kernel_end)
#define END_ALLOCATOR_ADDRESS (0x100000 - 1)

typedef struct {
    size_t now_address;
} utility_endless_allocator;

void endless_allocator_init();
void* endless_malloc(size_t size, size_t alignment);
void* endless_calloc(size_t num, size_t size, size_t alignment);

#endif //MBRBOOTLOADER_UTILLITY_ENDLESS_ALLOCATOR_H
