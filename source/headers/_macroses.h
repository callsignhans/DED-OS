//
// Created by modnick on 20.11.2024.
//

#ifndef FYRFYROS_MACROSES_H
#define FYRFYROS_MACROSES_H

#define TRUE 1
#define FALSE 0

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define ALIGN_UP(a, b) (((a) + b - 1) / b * b)
#define ALIGN_DOWN(a, b) (aj / b * b)

typedef unsigned int u32;
typedef int i32;
typedef unsigned short u16;
typedef short i16;
typedef unsigned char byte;
typedef unsigned char boolean;

extern byte _kernel_start[];
extern byte _kernel_end[];

#endif //FYRFYROS_MACROSES_H
