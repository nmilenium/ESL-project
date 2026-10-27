#ifndef LED_H
#define LED_H

#include "nrf_delay.h"
#include "boards.h"
#include <stdbool.h>
#include <stdint.h>
#include "project_config.h"

struct BlinkyConfig {
    uint8_t blinks[LEDS_NUMBER];
};

void blinky_init(struct BlinkyConfig *config);
void blink_led(uint32_t led_number, uint32_t delay_ms);
void blink_led_n_times(uint32_t led_number, uint8_t n);
void serial_blinking(struct BlinkyConfig config);

#endif