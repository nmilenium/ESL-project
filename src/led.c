#include "led.h"

void esl_led_pin_init(esl_led_t led)
{
    nrf_gpio_cfg_output((uint32_t)led);
    nrf_gpio_pin_set((uint32_t)led);
}

void esl_leds_init()
{
    esl_led_pin_init(ESL_LED_YELLOW);
    esl_led_pin_init(ESL_LED_RED);
    esl_led_pin_init(ESL_LED_GREEN);
    esl_led_pin_init(ESL_LED_BLUE);
}

void els_led_blink(esl_led_t led)
{
    nrf_gpio_pin_clear((uint32_t)led);
    nrf_delay_ms(LED_BLINK_DELAY);
    nrf_gpio_pin_set((uint32_t)led);
    nrf_delay_ms(LED_BLINK_DELAY);
}