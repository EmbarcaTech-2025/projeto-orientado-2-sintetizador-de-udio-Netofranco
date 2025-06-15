#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

#include <stdbool.h>

#define RECORD_BUTTON 5
#define PLAY_BUTTON 6
#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12

void init_gpio();
void set_led(bool red, bool green, bool blue);

#endif
