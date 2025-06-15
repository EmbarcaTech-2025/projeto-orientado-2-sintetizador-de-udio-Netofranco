#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>    // ✅ ESSENCIAL

void clear_display_buffer();
void init_display_clean();
void display_message(const char *msg);
void ssd1306_draw_text(uint8_t *buffer, int x, int y, const char *text);
void draw_test_line();

#endif
