#include "gpio_control.h"
#include "pico/stdlib.h"

void init_gpio() {
    gpio_init(RECORD_BUTTON);
    gpio_set_dir(RECORD_BUTTON, GPIO_IN);
    gpio_pull_up(RECORD_BUTTON);

    gpio_init(PLAY_BUTTON);
    gpio_set_dir(PLAY_BUTTON, GPIO_IN);
    gpio_pull_up(PLAY_BUTTON);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

void set_led(bool red, bool green, bool blue) {
    gpio_put(LED_RED, red);
    gpio_put(LED_GREEN, green);
    gpio_put(LED_BLUE, blue);
}
