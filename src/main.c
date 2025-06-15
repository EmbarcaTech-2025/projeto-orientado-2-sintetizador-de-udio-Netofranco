#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "audio.h"
#include "gpio_control.h"
#include "display.h"

#define PIN_SDA 14
#define PIN_SCL 15
#define I2C_PORT i2c1

int main() {
    stdio_init_all();

    i2c_init(I2C_PORT, 400000);
    gpio_set_function(PIN_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PIN_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(PIN_SDA);
    gpio_pull_up(PIN_SCL);

    init_display_clean();
    draw_test_line();
    display_message("Sistema pronto");

    init_gpio();
    init_adc();
    init_pwm_audio();

    while (true) {
        if (!gpio_get(RECORD_BUTTON)) {
            grava_audio();
            mostra_waveform();
            sleep_ms(500);
        }

        if (!gpio_get(PLAY_BUTTON)) {
            reproduz_audio();
            sleep_ms(500);
        }
    }
    return 0;
}
