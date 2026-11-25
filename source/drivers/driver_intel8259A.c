//
// Created by modnick on 20.11.2024.
//
#include "_macroses.h"
#include "driver_intel8259A.h"

#include <stdarg.h>
#include <stddef.h>

#include "utility_asm_fuctions.h"
#include "utility_assert.h"

static void (*intel8259_interrupts[16])(context* ctx);
void intel8259_configure(const u16 command_port, const u16 data_port, const byte icw1, const byte icw2,
        const byte icw3, const byte icw4) {
    outb_api(command_port, icw1);
    configure_intel8259A_waiting();

    outb_api(data_port, icw2);
    configure_intel8259A_waiting();

    outb_api(data_port, icw3);
    configure_intel8259A_waiting();

    outb_api(data_port, icw4);
    configure_intel8259A_waiting();
}

void intel8259_configure_master(const boolean exist_slave, const boolean auto_eoi, const byte devices_mask) {
    const byte icw1 = 0b00010001 + ((exist_slave == FALSE) << 1);
    const byte icw2 = START_VECTOR_MASTER;
    const byte icw3 = 0b00000100;
    const byte icw4 = 0b00000001 + ((auto_eoi != FALSE) << 1);
    if (exist_slave) {
        intel8259_configure(COMMAND_PORT_MASTER, DATA_PORT_MASTER, icw1, icw2, icw3, icw4);
        outb_api(DATA_PORT_MASTER, devices_mask);
    } else {
        intel8259_configure(COMMAND_PORT_MASTER, DATA_PORT_SLAVE, icw1, icw2, icw3, devices_mask);
    }
    configure_intel8259A_waiting();
}

void intel8259_configure_slave(const boolean auto_eoi, const byte devices_mask) {
    const byte icw1 = 0b00010001;
    const byte icw2 = START_VECTOR_SLAVE;
    const byte icw3 = 0x2;
    const byte icw4 = 0b00000001 + ((auto_eoi != FALSE) << 1);
    intel8259_configure(COMMAND_PORT_SLAVE, DATA_PORT_SLAVE, icw1, icw2, icw3, icw4);
    outb_api(DATA_PORT_SLAVE, devices_mask);
}

void intel8258A_configure_all(const boolean exist_slave, const boolean auto_eoi) {
    byte mask_slave = -1, mask_master = -1;
    intel8259_configure_master(exist_slave, auto_eoi, mask_master);
    intel8259_configure_slave(auto_eoi, mask_slave);
    for (int i = 0; i < 16; ++i) {
        intel8259_interrupts[i] = NULL;
    }
}

void intel8259_enable_device(const intel5289_devices device, void(*handler_interrupt)(context* ctx)) {
    if (device <= 0x0F) {
        byte now_mask = inb_api(DATA_PORT_MASTER);
        now_mask &= -1 ^ (0b1 << device);
        intel8259_interrupts[device] = handler_interrupt;
        outb_api(DATA_PORT_MASTER, now_mask);
    } else {
        byte now_mask = inb_api(DATA_PORT_SLAVE);
        now_mask &= -1 ^ (0b1 << (device >> 8));
        intel8259_interrupts[8 + (device >> 8)] = handler_interrupt;
        outb_api(DATA_PORT_MASTER, now_mask);
    }
}

void intel8259_disable_device(intel5289_devices device) {
    if (device <= 0x0F) {
        byte now_mask = inb_api(DATA_PORT_MASTER);
        now_mask |= 0b1 << device;
        intel8259_interrupts[device] = NULL;
        outb_api(DATA_PORT_MASTER, now_mask);
    } else {
        byte now_mask = inb_api(DATA_PORT_SLAVE);
        now_mask &= -1 ^ (0b1 << (device >> 8));
        intel8259_interrupts[8 + (device >> 8)] = NULL;
        outb_api(DATA_PORT_MASTER, now_mask);
    }
}

void intel8259_start_interrupt(const size_t number_interrupt, const context* ctx) {
    ASSERT((number_interrupt >= START_VECTOR_MASTER && number_interrupt < END_VECTOR_MASTER) ||
        (number_interrupt >= START_VECTOR_SLAVE && number_interrupt < END_VECTOR_SLAVE),
    "Interrupts %x not match interval intel8259's vectors interrupt", number_interrupt);
        if (number_interrupt >= START_VECTOR_MASTER && number_interrupt < END_VECTOR_MASTER) {
            ASSERT(intel8259_interrupts[number_interrupt - START_VECTOR_MASTER] != NULL,
                "Interrupt %x not define handler", number_interrupt);
            intel8259_interrupts[number_interrupt - START_VECTOR_MASTER](ctx);
        } else if (number_interrupt >= START_VECTOR_SLAVE && number_interrupt < END_VECTOR_SLAVE) {
            ASSERT(intel8259_interrupts[number_interrupt - START_VECTOR_SLAVE + 8] != NULL,
                "Interrupt %x not define handler", number_interrupt);
            intel8259_interrupts[number_interrupt - START_VECTOR_SLAVE + 8](ctx);
        }
    }

void intel8259_eoi(const intel8259_type cont) {
    outb_api(cont == master ? COMMAND_PORT_MASTER : COMMAND_PORT_SLAVE, 0x20);
}

void configure_intel8259A_waiting() {
    for (int i = 0; i < 100; ++i) {
        outb_api(DIAGNOSTIC_PORT_BIOS, MAGIC_CONST);
    }
}
