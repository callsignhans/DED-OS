#include "driver_vga.h"
#include "utility_asm_fuctions.h"
#include "utility_endless_allocator.h"
#include "kernel_trampolines.h"
#include "utility_assert.h"
#include "utility_printf.h"

int u = 0;

int experement_fault() {
    int y  = 2;
    y = y / u;
    return y;
}

void experement_trap() {
    call_int_104();
}

void experement_sti() {
    sti_api();
}

void kernel_entry() {
    ASSERT(sizeof(gate_descriptor) == 8, "size gate_descriptor must equal 8 bytes, now size is %d", sizeof(gate_descriptor))
    vga_init();
    endless_allocator_init();
    create_lidt();
    int i = experement_fault();
    print_fyr("The end %d", i);
    endless_loop();
}