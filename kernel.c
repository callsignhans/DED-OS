#include "driver_vga.h"
#include "driver_intel8259A.h"
#include "kernel_handler_interupt.h"
#include "utility_asm_fuctions.h"
#include "utility_endless_allocator.h"
#include "kernel_trampolines.h"
#include "utility_assert.h"
#include "utility_printf.h"


int timer_count = 0;
int fake = 0;

void experement1() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    sti_api();
    endless_loop();
}

void experement2() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, trap_handler);
    sti_api();
    endless_loop();
}

void experement3() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_intel_8042_keyboard, trap_handler);
    sti_api();
    endless_loop();
}


void timer_increment_print(context* ctx) {
    print_fyr("%d ",timer_count++);
}
void experement4() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_increment_print);
    sti_api();
    endless_loop();
}


void timer_zero(context* ctx) {
    timer_count = 0;
}
void experement5() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_zero);
    sti_api();
    while (fake != 10) {
        print_fyr("%d ", timer_count++);
    }
}


void experement6() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_increment_print);
    sti_api();
    while (fake != 10) {
        print_fyr("%d ", timer_count++);
    }
}


void experement7() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, timer_increment_print);
    sti_api();
    endless_loop();
}


void timer_incriment_print_eoi(context* ctx) {
    print_fyr("%d ",timer_count++);
    intel8259_eoi(master);
}
void experement8() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, timer_incriment_print_eoi);
    sti_api();
    endless_loop();
}


void timer_incriment_print_eoi_sti_endless(context* ctx) {
    print_fyr("%d ",timer_count++);
    intel8259_eoi(master);
    sti_api();
    endless_loop();
}
void experement9() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, timer_incriment_print_eoi_sti_endless);
    sti_api();
    endless_loop();
}


void timer_experement10(context* ctx) {
    print_fyr("%d ",timer_count++);
    if (timer_count < 16) {
        intel8259_eoi(master);
        sti_api();
    }
    endless_loop();
}
void experement10() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, timer_experement10);
    sti_api();
    endless_loop();
}


void timer_experement11(context* ctx) {
    print_fyr("%d ",timer_count++);
    if (timer_count < 16) {
        intel8259_eoi(master);
    }
    endless_loop();
}
void experement11() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = trap_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, timer_experement11);
    sti_api();
    endless_loop();
}


void timer_experement12(context* ctx) {
    print_fyr("%d ",timer_count++);
    if (timer_count < 16) {
        sti_api();
    }
    endless_loop();
}
void experement12() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_experement12);
    sti_api();
    endless_loop();
}


void keyboard_print_keycode(context* ctx) {
    print_fyr("%d ", (u32)inb_api(0x60));
}
void experement13() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode);
    sti_api();
    endless_loop();
}


void experement14() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode);
    intel8259_enable_device(device8259_timer, timer_increment_print);
    sti_api();
    endless_loop();
}


void timer_increment_print_endless(context* ctx) {
    print_fyr("%d ",timer_count++);
    endless_loop();
}
void experement15() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_increment_print_endless);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode);
    sti_api();
    endless_loop();
}


void keyboard_print_keycode_endless(context* ctx) {
    print_fyr("%d ", (u32)inb_api(0x60));
    endless_loop();
}
void experement16() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_increment_print);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode_endless);
    sti_api();
    endless_loop();
}


void keyboard_print_keycode_sti_endless(context* ctx) {
    print_fyr("%d ", (u32)inb_api(0x60));
    sti_api();
    endless_loop();
}
void experement17() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_increment_print);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode_sti_endless);
    sti_api();
    endless_loop();
}


void keyboard_print_keycode_eoi(context* ctx) {
    print_fyr("%d ", (u32)inb_api(0x60));
    intel8259_eoi(master);
}
void experement18() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = trap_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, timer_increment_print_endless);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode_eoi);
    sti_api();
    endless_loop();
}


void experement19() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = trap_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, FALSE);
    intel8259_enable_device(device8259_timer, timer_incriment_print_eoi);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode_endless);
    sti_api();
    endless_loop();
}

static void delay() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50000; j++) {
            outb_api(0x80, 0x80);
        }
        print_fyr("%d ", i);
    }
    print_fyr("\n");
}
void timer_experemnt20(context* ctx) {
    intel8259_disable_device(device8259_timer);
    delay();
    sti_api();
    delay();
}
void experement20() {
    gate_type* gates = endless_calloc(256, sizeof(gate_type), 1);
    for (int i = 0; i < 256; ++i) {
        gates[i] = interrupt_gate;
    }
    create_lidt(gates);
    intel8258A_configure_all(TRUE, TRUE);
    intel8259_enable_device(device8259_timer, timer_experemnt20);
    intel8259_enable_device(device8259_intel_8042_keyboard, keyboard_print_keycode_endless);
    sti_api();
    endless_loop();
}


void kernel_entry() {
    ASSERT(sizeof(gate_descriptor) == 8, "size gate_descriptor must equal 8 bytes, now size is %d", sizeof(gate_descriptor))
    vga_init();
    endless_allocator_init();
    experement20();
}