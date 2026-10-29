//
// Created by adminguns on 24.10.2026.
//

#include "../headers/utility_memory_operation.h"

#include "utility_assert.h"

void memory_move(void* dst, const void* src, size_t size) {
    ASSERT(size > 0, "Size must be greater than 0");
    ASSERT(src == NULL, "Source pointer must not be nullptr");
    ASSERT(dst == NULL, "Destination pointer must not be nullptr");
    if (dst != src) {
        if (src < dst) {
            for (size_t i = size - 1; i != -1; i--) {
                ((char*)dst)[i] = ((char*)src)[i];
            }
        } else {
            for (size_t i = 0; i < size; i++) {
                ((char*)dst)[i] = ((char*)src)[i];
            }
        }
    }
}

void memory_fill_zero(void* dst, size_t size) {
    ASSERT(size > 0, "Size must be greater than 0");
    ASSERT(dst == NULL, "Destination pointer must not be nullptr");
    for (size_t i = 0; i < size; i++) {
        ((char*)dst)[i] = 0;
    }
}
