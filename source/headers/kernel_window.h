//
// Created by adminguns on 24.10.2026.
//

#ifndef MBRBOOTLOADER_WINDOW_H
#define MBRBOOTLOADER_WINDOW_H

#include "driver_vga.h"

typedef struct {
    u16 x;
    u16 y;
    u16 size_x;
    u16 size_y;
    carriage carriage_window;
    frame frame_window;
    byte open;
    u16* display; // [80*25];
} window;

window* window_create();

void window_carriage_inc(window* wind);                         // сдвигает каретку вправо
void window_carriage_shift(window* wind, i32 shift);            // сдвигает каретку на shift вправо
void window_carriage_dec(window* wind);                         // сдвигает каретку влево
void window_carriage_start_line(window* wind);                  // сдвигает каретку в начало строки
void window_carriage_new_line(window* wind);                    // переводит каретку на новую строку
void window_carriage_set_position(window* wind, u16 x, u16 y);  // задаёт позицию каретки
u32 window_carriage_get_position(window* wind);                 // выдаёт координаты каретки (старшие 16 бит координаты по х, младшие 16 -- по у).

void window_carriage_shift_down_line(window* wind);             //
void window_carriage_shift_up_line(window* wind);


void window_vga_init(window* wind);
void window_clear_screen(window* wind);
void window_vga_clear_screen(window* wind);
void window_vga_print_char(window* wind, byte sym, color_front, color_back, u16, u16);
void window_vga_print_char_carriage(window* wind, byte sym, color_front, color_back);
void window_vga_scroll_line(window* wind, byte flag_down);


u32 window_get_position(window* wind);
void window_set_position(window* wind, u16 pos_y, u16 pos_x);
void window_show(window* wind);
void window_open(window* wind);
void window_close(window* wind);
void window_resize_x(window* wind, u16 resize);
void window_resize_y(window* wind, u16 resize);
void window_draw_frame(window* wind);
void window_close_frame(window* wind);
void window_delete_frame(window* wind);

#endif //MBRBOOTLOADER_WINDOW_H
