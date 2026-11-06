#ifndef ESL_LED_H
#define ESL_LED_H

#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "project_config.h"

#define LED_NUM 4

typedef enum {
    ESL_LED_YELLOW = NRF_GPIO_PIN_MAP(0, 6),
    ESL_LED_RED    = NRF_GPIO_PIN_MAP(0, 8),
    ESL_LED_GREEN  = NRF_GPIO_PIN_MAP(1, 9),
    ESL_LED_BLUE   = NRF_GPIO_PIN_MAP(0, 12)
} esl_led_t;

void esl_led_pin_init(esl_led_t led);
void esl_leds_init();
void els_led_blink(esl_led_t led);

#endif