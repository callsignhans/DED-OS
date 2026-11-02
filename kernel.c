#include "driver_vga.h"
#include "utility_asm_fuctions.h"
#include "utility_assert.h"
#include "utility_printf.h"
#include "utility_endless_allocator.h"

void kernel_entry() {
    vga_init();
    endless_allocator_init();
    for (int i = 0; i < 10000; ++i) {
        print_fyr("malloc: %x \r\n", endless_malloc(12, 0x1001));
    }
    ASSERT(FALSE, "kernel_entry in test %d", 1);
    endless_loop();
}
