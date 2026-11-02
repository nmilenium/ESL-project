#ifndef ESL_LED_H
#define ESL_LED_H

#ifndef BOARD_PCA10059
#define BOARD_PCA10059
#endif

#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"
#include "project_config.h"



struct BlinkyConfig {
    uint8_t blinks[LEDS_NUMBER];
};

void blinky_init(struct BlinkyConfig *config);
void blink_led(uint32_t led_number, uint32_t delay_ms);
void blink_led_n_times(uint32_t led_number, uint8_t n);
void serial_blinking(struct BlinkyConfig config);

#endif