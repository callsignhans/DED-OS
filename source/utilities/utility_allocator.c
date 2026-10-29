#include "utility_allocator.h"

#include "utility_printf.h"
#include "utility_memory_operation.h"
#include "kernel_ipmlementation_interrupts.h"

void kernel_start_allocator() {
    kernel_init_allocator(&KERNEL_ALLOCATOR, KERNEL_COUNT_ARENAS - 1);
}

void kernel_init_allocator(KERNEL_PullAllocator* allocator, size_t N) {
    allocator->start_memory_data = (void*)(KERNEL_START_ALLOCATE);
    for (u32 i = 0; i < KERNEL_COUNT_ARENAS; ++i) {
        allocator->ptrs[i] = NULL;
        allocator->lens[i] = 0;
    }
    allocator->count_arenes = N;
}

void* kernel_malloc(size_t size) {
    size = KERNEL_ALIGN_UP_TO_SIZE_ADDRESS(size);
    if (!size || size > KERNEL_BLOCK_SIZE) {
        kernel_panic("Can't allocate memory for kernel, block size is %d bytes", size);
        return NULL;
    }

    size_t data_ind = size / KERNEL_SIZE_ADDRESS - 1;
    if (data_ind >= KERNEL_ALLOCATOR.count_arenes) {
        size = KERNEL_BLOCK_SIZE;
        data_ind = KERNEL_ALLOCATOR.count_arenes;
    }

    if (KERNEL_ALLOCATOR.ptrs[data_ind] == NULL) {
        if (KERNEL_ALLOCATOR.lens[data_ind] != KERNEL_ARENA_SIZE / size) {
            size_t offset = data_ind * KERNEL_ARENA_SIZE + size * KERNEL_ALLOCATOR.lens[data_ind]++;
            return &((byte*) KERNEL_ALLOCATOR.start_memory_data)[offset];
        }
        kernel_panic("Can't allocate memory for kernel, block size is %d bytes", size);
        return NULL;
    }
    void* res = KERNEL_ALLOCATOR.ptrs[data_ind];
    KERNEL_ALLOCATOR.ptrs[data_ind] = *((void**) res);
    return res;
}

void* kernel_calloc(size_t num, size_t size) {
    void* ptr = kernel_malloc(num * size);
    if (ptr == NULL) {
        return NULL;
    }
    memory_fill_zero(ptr, num * size);
    return ptr;
}

void* kernel_realloc(void* ptr, size_t new_size) {
    if (ptr == NULL)
        return kernel_malloc(new_size);

    new_size = KERNEL_ALIGN_UP_TO_SIZE_ADDRESS(new_size);
    size_t old_size = kernel_get_size_block(ptr, KERNEL_ALLOCATOR.start_memory_data) * KERNEL_SIZE_ADDRESS + KERNEL_SIZE_ADDRESS;

    if (new_size > KERNEL_ALLOCATOR.count_arenes * KERNEL_SIZE_ADDRESS)
        new_size = KERNEL_BLOCK_SIZE;
    if (old_size > KERNEL_ALLOCATOR.count_arenes * KERNEL_SIZE_ADDRESS)
        old_size = KERNEL_BLOCK_SIZE;

    if (new_size == old_size)
        return ptr;

    void* res = kernel_malloc(new_size);
    if (res == NULL)
        return NULL;

    memory_move(res, ptr, MIN(old_size, new_size));
    kernel_free(ptr);
    return res;
}

void kernel_free(void* ptr) {
    if (ptr == NULL)
        return;

    size_t data_ind = kernel_get_size_block(ptr, KERNEL_ALLOCATOR.start_memory_data);
    *((void**) ptr) = KERNEL_ALLOCATOR.ptrs[data_ind];
    KERNEL_ALLOCATOR.ptrs[data_ind] = ptr;
}

void *kernel_malloc_aligned(size_t size, size_t alignment) {
    for (u32 i = 0; i < KERNEL_ALLOCATOR.count_arenes; ++i) {
        size_t now_size = KERNEL_SIZE_ADDRESS * (i + 1);
        if (size <= now_size && now_size % alignment == 0) {
            return kernel_malloc(now_size);
        }
    }
    return kernel_malloc(MIN(KERNEL_BLOCK_SIZE, size));
}

void * kernel_calloc_aligned(size_t num, size_t size, size_t alignment) {
    void* ptr = kernel_malloc_aligned(num * size, alignment);
    if (ptr == NULL) {
        return NULL;
    }
    memory_fill_zero(ptr, num * size);
    return ptr;
}

size_t kernel_get_size_block(void* finish, void* start) {
    return (size_t) ((byte*) finish - (byte*) start) / KERNEL_ARENA_SIZE;
}

void kernel_print_allocator_info() {
    print_fyr("Alloc allocator info:\r\n");
    print_fyr("  end_data_kernel: %x \r\n", _kernel_end);
    print_fyr("  start_memory_data: %x\r\n", KERNEL_START_ALLOCATE);
    print_fyr("  count_arenes: %d\r\n", KERNEL_COUNT_ARENAS);
    print_fyr("  lens: %x\r\n", KERNEL_ARENA_SIZE);
    for (u32 i = 0; i < KERNEL_ALLOCATOR.count_arenes + 1; ++i) {
        print_fyr("  arene %d start address from %x to %x\r\n ", i, KERNEL_START_ALLOCATE + KERNEL_ARENA_SIZE * i, KERNEL_START_ALLOCATE + KERNEL_ARENA_SIZE * (i + 1));
    }
}
