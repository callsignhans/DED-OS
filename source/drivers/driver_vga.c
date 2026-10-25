//
// Created by modnick on 25.10.2024.
// Update by RostyanYandexLyceumCheeeeck on 01.11.2024.
//

#include "../headers/driver_vga.h"
#include "../headers/utility_allocator.h"

carriage carriage_kernel;

void carriage_inc() {
    carriage_kernel.x++;
    carriage_kernel.y += carriage_kernel.x / SIZE_X_DISPLAY;
    carriage_kernel.x %= SIZE_X_DISPLAY;

    while (carriage_kernel.y >= SIZE_Y_DISPLAY) {
        carriage_kernel.y--;
        carriage_shift_down_line();
    }
}

void carriage_shift(i32 shift) {
    if ( shift < 0) {
        i32 x_temp = (i32) carriage_kernel.x + shift % SIZE_X_DISPLAY;
        i32 y_temp = (i32) carriage_kernel.y + shift / SIZE_X_DISPLAY - (i32)(x_temp < 0);

        carriage_kernel.y = (u16)(y_temp < 0 ? 0 : y_temp);
        carriage_kernel.x = (u16)(x_temp < 0 ? SIZE_X_DISPLAY + x_temp : x_temp);
        carriage_kernel.x = (u16)(y_temp < 0 ? 0 : carriage_kernel.x);
    } else {
        carriage_kernel.x += shift - 1;
        carriage_inc();
    }
}

void carriage_dec() {
    if (!carriage_kernel.x && !carriage_kernel.y) {
        return;
    }
    carriage_kernel.y -= (carriage_kernel.x == 0 && carriage_kernel.y);
    carriage_kernel.x = (carriage_kernel.x ? carriage_kernel.x : SIZE_X_DISPLAY) - 1;
}

void carriage_start_line() {
    carriage_kernel.x = 0;
}

void carriage_new_line() {
    carriage_kernel.x--;
    carriage_kernel.y++;
    carriage_inc();
}

void carriage_set_position(u16 x, u16 y) {
    if ((x >= SIZE_X_DISPLAY) || (y >= SIZE_Y_DISPLAY)) {
        vga_error();
        return;
    }
    carriage_kernel.x = x;
    carriage_kernel.y = y;
}

u32 carriage_get_position() {
    return (((u32) carriage_kernel.x) << 16 ) | carriage_kernel.y;
}

void carriage_shift_up_line() {
    vga_scroll_line(0);
}

void carriage_shift_down_line() {
    vga_scroll_line(1);
}

void vga_init() {
    vga_clear_screen();
}

void vga_clear_screen() {
    for (unsigned long i = START_DISPLAY_ADDRESS; i < END_DISPLAY_ADDRESS; i += 2) {
        *((u16*) i) = black_f + black_b;
    }
    carriage_kernel.x = 0;
    carriage_kernel.y = 0;
    carriage_kernel.now_char = 0;
}

void vga_print_char(char sym, color_front front, color_back back, u16 x, u16 y) {
    carriage_set_position(x, y);
    vga_print_char_carriage(sym, front, back);
}

void vga_print_char_carriage(char sym, color_front front, color_back back) {
    unsigned long pos = START_DISPLAY_ADDRESS + 2*(SIZE_X_DISPLAY * carriage_kernel.y + carriage_kernel.x);
    switch (sym) {
        case '\t': {
            do {
                vga_print_char_carriage(' ', front, back);
            } while (carriage_kernel.x % 8);
            break;
        }
        case '\r': {
            carriage_start_line();
            break;
        }
        case '\n': {
            carriage_new_line();
            break;
        }
        case '\0': {
            break;
        }
        default: {
            *((u16*) pos) = (front + back + (u16)sym);
            carriage_inc();
        }
    }
}

void vga_scroll_line(byte flag_down) {
    i16 step = (flag_down ? SIZE_X_DISPLAY : -SIZE_X_DISPLAY);
    u16 start_coord = (flag_down ? 0 : SIZE_X_DISPLAY * (SIZE_Y_DISPLAY - 1));
    u16 end_coord = (flag_down ? SIZE_X_DISPLAY * (SIZE_Y_DISPLAY - 1) : 0);

    for (i32 j = 0; j < SIZE_X_DISPLAY; ++j) {
        u16* input_address = (u16*)(START_DISPLAY_ADDRESS + 2 * (start_coord + j));
        u16* output_address = input_address + step;
        for (i32 i = 0; i < SIZE_Y_DISPLAY - 1; ++i) {
            *input_address = *output_address;
            input_address = output_address;
            output_address += step; // !!!
        }
    }

    for (i32 j = 0; j < SIZE_X_DISPLAY; ++j) {
        *(u16*)(START_DISPLAY_ADDRESS + 2 * (end_coord + j)) = black_f + black_f;
    }
    carriage_set_position(0, SIZE_Y_DISPLAY - 1);
}

void vga_error() {
    *((i16*) 0xB8000) = 0x4F00 + (i32) 'E';
    *((i16*) 0xB8002) = 0x4F00 + (i32) 'R';
    *((i16*) 0xB8004) = 0x4F00 + (i32) 'R';
    *((i16*) 0xB8006) = 0x4F00 + (i32) 'O';
    *((i16*) 0xB8008) = 0x4F00 + (i32) 'R';
}

