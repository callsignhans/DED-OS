//
// Created by modnick on 08.11.2024.
//

#ifndef FYRFYROS_KERNEL_ALLOCATOR_H
#define FYRFYROS_KERNEL_ALLOCATOR_H

#include "_flags.h"
#include "_macroses.h"

#define KERNEL_SIZE_ADDRESS 8
#define KERNEL_COUNT_ARENAS 9

#define KERNEL_BLOCK_SIZE (2 * (1 << 10)) // 8KB

#define KERNEL_START_ALLOCATE (i32)(_kernel_end + KERNEL_BLOCK_SIZE +- 1) / KERNEL_BLOCK_SIZE * KERNEL_BLOCK_SIZE

#define KERNEL_ARENA_SIZE (0x100000 - KERNEL_START_ALLOCATE) / (KERNEL_BLOCK_SIZE * KERNEL_COUNT_ARENAS) * (KERNEL_BLOCK_SIZE * KERNEL_COUNT_ARENAS) / KERNEL_COUNT_ARENAS // 384KB

#define KERNEL_ALIGN_UP_TO_SIZE_ADDRESS(a) (((a) + KERNEL_SIZE_ADDRESS - 1) / KERNEL_SIZE_ADDRESS * KERNEL_SIZE_ADDRESS)

typedef unsigned long size_t;
typedef struct {
    void* start_memory_data;
    void* ptrs[KERNEL_COUNT_ARENAS];
    size_t lens[KERNEL_COUNT_ARENAS];
    size_t count_arenes;
} KERNEL_PullAllocator;
static KERNEL_PullAllocator KERNEL_ALLOCATOR;

void kernel_start_allocator();
void kernel_init_allocator(KERNEL_PullAllocator* allocator, size_t N);
void* kernel_malloc(size_t size);
void* kernel_calloc(size_t num, size_t size);
void* kernel_realloc(void* ptr, size_t new_size);
void kernel_free(void* ptr);
void* kernel_malloc_aligned(size_t size, size_t alignment);
void* kernel_calloc_aligned(size_t num, size_t size, size_t alignment);

size_t kernel_get_size_block(void* finish, void* start);
void kernel_print_allocator_info();

#endif //FYRFYROS_KERNEL_ALLOCATOR_H
