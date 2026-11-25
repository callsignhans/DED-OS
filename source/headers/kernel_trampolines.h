//
// Created by modnick on 08.11.2024.
//

#ifndef FYRFYROS_TRAMPLINS_H
#define FYRFYROS_TRAMPLINS_H

#include "_macroses.h"

#define COUNT_INTERRUPT 256
#define SIZE_TRAMPOLINE_WITH_ERRORCODE ((size_t)trampoline_with_errorcode_end - (size_t)trampoline_with_errorcode_start)
#define SIZE_TRAMPOLINE_WITHOUT_ERRORCODE ((size_t)trampoline_without_errorcode_end - (size_t)trampoline_without_errorcode_start)

extern void trampoline_with_errorcode_start();
extern void trampoline_with_errorcode_end();
extern void trampoline_without_errorcode_start();
extern void trampoline_without_errorcode_end();
extern byte* vector_number;

typedef void (*trampoline_fn_t)(void);

typedef enum {
    interrupt_gate = 0xE,
    trap_gate = 0xF
} gate_type;

typedef enum {
    kernel = 0,
    device_driver_1 = 1,
    device_driver_2 = 2,
    application = 3
} descriptor_privilege_level;

#pragma pack(push, 1)
typedef struct gate_descriptor {
    u16 shift_low;
    u16 selector_segment;
    byte reserve1;
    byte gate_type : 4;
    byte reserve2 : 1;
    byte dpl : 2;
    byte reserve3 : 1;
    u16 shift_height;
} gate_descriptor;

typedef struct table_gate_descriptor {
    u16 size;
    u32 address;
} table_gate_descriptor;
#pragma pack(pop)

static gate_descriptor *generate_idt(gate_type* type_interrupt_gates);
static gate_descriptor generate_gate_descriptor(void* trampoline_ptr, gate_type type, descriptor_privilege_level level);
void create_lidt(gate_type* type_interrupt_gates);
trampoline_fn_t kernel_create_trampoline(byte number_trampoline, boolean with_dead_code);

#endif //FYRFYROS_TRAMPLINS_H
