#include "driver_vga.h"
#include "utility_assert.h"
#include "utility_printf.h"

extern void assembler_while();
extern byte _kernel_start[];
extern byte _kernel_end[];
void kernel_entry() {
    vga_init();
    int y  = 1;
    const char* test = "test";
    size_t kernel_size_bytes = (size_t)(_kernel_end - _kernel_start);
    print_int(kernel_size_bytes / 512);
//    ASSERT(0, "not implemented %d", 12);
    assembler_while();
}
