#include "display.h"
#include "ssd1306_i2c.h"
#include "ssd1306.h"
#include <string.h>

#define BUFFER_SIZE 1024
static uint8_t display_buffer[BUFFER_SIZE];

void clear_display_buffer() {
    memset(display_buffer, 0x00, BUFFER_SIZE);
}

void init_display_clean() {
    ssd1306_init();
    clear_display_buffer();
    ssd1306_send_buffer(display_buffer, BUFFER_SIZE);
}

void ssd1306_draw_text(uint8_t *buffer, int x, int y, const char *text) {
    while (*text) {
        ssd1306_draw_char(buffer, x, y, *text++);
        x += 6;
    }
}

void display_message(const char *msg) {
    clear_display_buffer();
    ssd1306_draw_text(display_buffer, 0, 0, msg);
    ssd1306_send_buffer(display_buffer, BUFFER_SIZE);
}

void draw_test_line() {
    clear_display_buffer();
    for (int x = 0; x < 128; x++) {
        ssd1306_set_pixel(display_buffer, x, 32, true);
    }
    ssd1306_send_buffer(display_buffer, BUFFER_SIZE);
}
