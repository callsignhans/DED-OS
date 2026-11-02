//
// Created by adminguns on 02.11.2026.
//

#include "utility_memory_operation.h"
#include "utility_endless_allocator.h"
#include "kernel_panic.h"

static utility_endless_allocator endless_allocator;

void endless_allocator_init() {
    endless_allocator.now_address = START_ALLOCATOR_ADDRESS;
}

void* endless_malloc(size_t size, size_t alignment) {
    size_t address_align = ALIGN_UP(endless_allocator.now_address, alignment);
    if (address_align + size >= END_ALLOCATOR_ADDRESS) {
        kernel_panic("endless_malloc: overflow endless_allocator, can't allocate %x byte with %x alignment to"
                     " %x address", size, alignment, endless_allocator.now_address);
    }
    void* ptr = (void*)address_align;
    endless_allocator.now_address = address_align + size;
    return ptr;
}

void * endless_calloc(size_t num, size_t size, size_t alignment) {
    void* ptr =endless_malloc(num * size, alignment);
    memory_fill_zero(ptr, num * size);
    return ptr;
}

