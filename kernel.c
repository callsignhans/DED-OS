#include "driver_vga.h"
#include "utility_asm_fuctions.h"
#include "utility_assert.h"
#include "utility_printf.h"


void kernel_entry() {
    vga_init();
    kernel_start_allocator();
    int i = 0;
    boolean check = 0;
    u32* test[7];
    while (1) {
        test[i] = kernel_malloc_aligned(63, 24);
        print_fyr("Result malloc: %x \r\n", test[i]);
        if (test[i] == NULL) {
            break;
        }
    }
    endless_loop();
}
