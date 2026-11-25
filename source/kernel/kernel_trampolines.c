#include "kernel_trampolines.h"

#include "utility_asm_fuctions.h"
#include "utility_endless_allocator.h"

static gate_descriptor* generate_idt(gate_type* type_interrupt_gates){
    gate_descriptor* ans = endless_malloc(COUNT_INTERRUPT * sizeof(gate_descriptor), 32);
    for (i32 i = 0; i < COUNT_INTERRUPT; ++i) {
        trampoline_fn_t tramplin_ptr = NULL;
        if (i == 0x08 || (i >= 0x0A && i <= 0xE) || i == 0x11 || i == 0x15 || i == 0x1D || i == 0x1E) {
            tramplin_ptr = kernel_create_trampoline(i,FALSE);
        } else {
            tramplin_ptr = kernel_create_trampoline(i,TRUE);
        }
        ans[i] = generate_gate_descriptor(tramplin_ptr,  type_interrupt_gates[i], kernel);
    }
    return ans;
}

static gate_descriptor generate_gate_descriptor(void* trampoline_ptr, gate_type type, descriptor_privilege_level level) {
    gate_descriptor gate;
    gate.shift_low = (u16)trampoline_ptr;
    gate.selector_segment = get_cs_api();
    gate.reserve1 = 0;
    gate.gate_type = type;
    gate.reserve2 = 0;
    gate.dpl = level;
    gate.reserve3 = 1;
    gate.shift_height = (u16)((i32)trampoline_ptr >> 16);
    return gate;
}

void create_lidt(gate_type* type_interrupt_gates) {
    gate_descriptor* descriptor = generate_idt(type_interrupt_gates);
    table_gate_descriptor table;
    table.size = COUNT_INTERRUPT * sizeof(gate_descriptor) - 1;
    table.address = (u32)descriptor;
    lidt_api(&table);
}


trampoline_fn_t kernel_create_trampoline(const byte number_trampoline, const boolean with_dead_code) {
    const byte mov_command[10] = {0xC7, 0x05, ((u32)(&vector_number)), ((u32)(&vector_number) >> 8),
        ((u32)(&vector_number) >> 16), ((u32)(&vector_number) >> 24), number_trampoline, 0x00, 0x00, 0x00};
    size_t now_size = 0;
    if (with_dead_code) {
        now_size = SIZE_TRAMPOLINE_WITHOUT_ERRORCODE + 10;
    } else {
        now_size = SIZE_TRAMPOLINE_WITH_ERRORCODE + 10;
    }
    byte* new_trampoline  = endless_calloc(now_size, 1, 8);
    for (int i = 0; i < now_size; i++) {
        if (i < 10) {
            new_trampoline[i] = mov_command[i];
        } else {
            if (with_dead_code) {
                new_trampoline[i] = ((byte*)trampoline_without_errorcode_start)[i - 10];
            } else {
                new_trampoline[i] = ((byte*)trampoline_with_errorcode_start)[i - 10];
            }
        }
    }
    return (void*)new_trampoline;
}
