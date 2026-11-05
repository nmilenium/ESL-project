#ifndef ESL_BLINKY_H
#define ESL_BLINKY_H

#include <stdint.h>
#include "led.h"

struct BlinkyConfig
{
    uint8_t blinks[LED_NUM];
    esl_led_t leds[LED_NUM];
};

void blinky_init(struct BlinkyConfig *config);
void blink_led_n_times(esl_led_t led, uint8_t n);
void serial_blinking(struct BlinkyConfig config);

#endif