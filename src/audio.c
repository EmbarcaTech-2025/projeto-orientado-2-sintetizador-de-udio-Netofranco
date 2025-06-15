#include "audio.h"
#include "ssd1306_i2c.h"
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "display.h"
#include "gpio_control.h"
#include <stdio.h>

uint16_t audio_buffer[TOTAL_SAMPLES];

#define ADC_PIN 28
#define PWM_PIN 10

void init_adc() {
    adc_init();
    adc_gpio_init(ADC_PIN);
    adc_select_input(2);
}

void init_pwm_audio() {
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 31.25f);

    pwm_init(slice_num, &config, true);
    pwm_set_wrap(slice_num, 99);
}

void grava_audio() {
    set_led(true, false, false);
    printf("Gravando áudio...\n");
    display_message("Gravando audio");

    for (uint32_t i = 0; i < TOTAL_SAMPLES; i++) {
        audio_buffer[i] = adc_read();
        sleep_us(1000000 / SAMPLE_RATE_HZ);
    }

    set_led(false, false, false);
    printf("Gravação concluída!\n");
    display_message("Gravacao Concluida");
}

void reproduz_audio() {
    set_led(false, true, false);
    display_message("Reproduzindo audio");

    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);

    for (uint32_t i = 0; i < TOTAL_SAMPLES; i++) {
        uint16_t pwm_val = (audio_buffer[i] * 99) / 4095;
        pwm_set_gpio_level(PWM_PIN, pwm_val);
        sleep_us(1000000 / SAMPLE_RATE_HZ);
    }

    pwm_set_gpio_level(PWM_PIN, 0);
    set_led(false, false, false);
    display_message("Reproducao Completa");
}

void mostra_waveform() {
    uint8_t display_buffer[1024] = {0};
    struct render_area area = {
        .start_column = 0,
        .end_column = 127,
        .start_page = 0,
        .end_page = 7,
    };
    calculate_render_area_buffer_length(&area);

    for (int x = 0; x < 128; x++) {
        uint32_t idx = (x * TOTAL_SAMPLES) / 128;
        uint32_t y = (audio_buffer[idx] * 64) / 4096;
        if (y >= 64) y = 63;
        ssd1306_set_pixel(display_buffer, x, 63 - y, true);
    }

    render_on_display(display_buffer, &area);
}

void test_pwm_tone(uint32_t freq) {
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f);
    pwm_init(slice_num, &config, true);

    uint32_t wrap = (125000000 / (freq * 125)) - 1;
    pwm_set_wrap(slice_num, wrap);
    pwm_set_gpio_level(PWM_PIN, wrap / 2);
}
