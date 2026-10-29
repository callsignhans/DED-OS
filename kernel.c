#include "driver_vga.h"
#include "utility_asm_fuctions.h"
#include "utility_assert.h"
#include "utility_printf.h"


void kernel_entry() {
    vga_init();
    kernel_start_allocator();
//    kernel_print_allocator_info();

/*
 *    for (int i = 0; i < 25 ; i++) {
        for (int j = 0; j < 1000000 ; j++) {
            int y = 1;
        }
        print_hex(i);
        print_str("\r\n");
    }
    */
    int i = 0;
    boolean check = 0;
    u32* test[7];
    while (1) {
        test[i] = kernel_malloc_aligned(128, 16);
        print_fyr("Result malloc: %x \r\n", test[i]);
        if (test[i] == NULL) {
            break;
        }
    }
    endless_loop();
}
