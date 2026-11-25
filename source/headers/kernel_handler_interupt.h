//
// Created by modnick on 23.11.2024.
//

#ifndef FYRFYROS_HANDLER_INTERUPT_H
#define FYRFYROS_HANDLER_INTERUPT_H

#include "driver_intel8259A.h"

void timer(context* ctx);

void interrupt_handler(context* ctx);

void trap_handler(context* ctx);

void fault_handler(context* ctx);

void abort_handler(context* ctx);


#endif //FYRFYROS_HANDLER_INTERUPT_H
