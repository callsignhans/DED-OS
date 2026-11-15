//
// Created by adminguns on 25.10.2026.
//

#ifndef MBRBOOTLOADER_UTILITY_ASM_FUCTIONS_H
#define MBRBOOTLOADER_UTILITY_ASM_FUCTIONS_H

#include "kernel_trampolines.h"

extern void cli_api();
extern void sti_api();
extern void endless_loop();
extern u16 get_cs_api();
extern void lidt_api(table_gate_descriptor* table);
extern void call_int_104();

#endif //MBRBOOTLOADER_UTILITY_ASM_FUCTIONS_H
