#include "led.h"

void blinky_init(struct BlinkyConfig *config)
{
    *config = (struct BlinkyConfig) {
        .blinks = {Y_BLINKS, R_BLINKS, G_BLINKS, B_BLINKS}
    };
}

void blink_led(uint32_t led_number, uint32_t delay_ms)
{
    bsp_board_led_on(led_number);
    nrf_delay_ms(delay_ms);
    bsp_board_led_off(led_number);
    nrf_delay_ms(delay_ms);
}

void blink_led_n_times(uint32_t led_number, uint8_t n)
{
    for (uint8_t i = 0; i < n; i++)
    {
        blink_led(led_number, LED_BLINK_DELAY);
    }
}

void serial_blinking(struct BlinkyConfig config)
{
    for (uint8_t led = 0; led < LEDS_NUMBER; led++)
    {
        blink_led_n_times(led, config.blinks[led]);
        if (led < LEDS_NUMBER - 1)
        {
            nrf_delay_ms(LED_IN_CYCLE_DELAY);
        }
    }
}