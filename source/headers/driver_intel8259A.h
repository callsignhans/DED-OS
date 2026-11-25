//
// Created by modnick on 20.11.2024.
//

#ifndef FYRFYROS_INTEL8259A_H
#define FYRFYROS_INTEL8259A_H

#include <stddef.h>

#include "_macroses.h"
#include "_structs.h"

#define MAGIC_CONST 0xAD

#define DATA_PORT_SLAVE 0xA1
#define DATA_PORT_MASTER 0x21
#define COMMAND_PORT_SLAVE 0xA0
#define COMMAND_PORT_MASTER 0x20
#define DIAGNOSTIC_PORT_BIOS 0x80

#define START_VECTOR_SLAVE 0x28
#define END_VECTOR_SLAVE (START_VECTOR_SLAVE + 8)
#define START_VECTOR_MASTER 0x20
#define END_VECTOR_MASTER (START_VECTOR_MASTER + 8)

typedef enum {
    slave,
    master
}intel8259_type;

typedef enum {
//master devices
    device8259_timer = 0x00,
    device8259_intel_8042_keyboard = 0x01,
    device8259_slave_intel_8259A = 0x02,
    device8259_intel_82072A = 0x06, //Дисковод гибких дисков
    device8259_spurious = 0x07,
//slave devices
    device8259_intel_8042_mouse = 0x40
} intel5289_devices;


void intel8259_configure(u16 command_port, u16 data_port, byte icw1, byte icw2, byte icw3, byte icw4);
void intel8259_configure_master(boolean exist_slave, boolean auto_eoi, byte devices_mask);
void intel8259_configure_slave(boolean auto_eoi, byte devices_mask);
void intel8258A_configure_all(boolean exist_slave, boolean auto_eoi);
void intel8259_enable_device(intel5289_devices device, void (*handler_interrupt)(context* ctx));
void intel8259_disable_device(intel5289_devices device);
void intel8259_start_interrupt(size_t number_interrupt, const context* ctx);
void intel8259_eoi(intel8259_type cont);
void configure_intel8259A_waiting();
#define FYRFYROS_INTEL8259A_H

#endif //FYRFYROS_INTEL8259A_H
