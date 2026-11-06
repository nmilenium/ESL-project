#include "blinky.h"

void blinky_init(struct BlinkyConfig *config)
{
    esl_button_init();
    esl_leds_init();
    *config = (struct BlinkyConfig) {
        .blinks = {Y_BLINKS, R_BLINKS, G_BLINKS, B_BLINKS},
        .leds = {ESL_LED_YELLOW, ESL_LED_RED, ESL_LED_GREEN, ESL_LED_BLUE}
    };
    
}

void blink_led_n_times(esl_led_t led, uint8_t n)
{
    for (uint8_t i = 0; i < n; i++)
    {
        ESL_WAIT_UNTILL_BUTTON_IS_HOLDED;
        els_led_blink(led);
    }
}

void serial_blinking(struct BlinkyConfig *config)
{
    ESL_WAIT_UNTILL_BUTTON_IS_HOLDED;
    for (uint32_t led = 0; led < LED_NUM; led++)
    {
        ESL_WAIT_UNTILL_BUTTON_IS_HOLDED;
        blink_led_n_times(config->leds[led], config->blinks[led]);
        ESL_WAIT_UNTILL_BUTTON_IS_HOLDED;
        if (led < LED_NUM - 1)
        {
            nrf_delay_ms(LED_IN_CYCLE_DELAY);
        } else {
            nrf_delay_ms(LED_CYCLE_END_DELAY);
        }
    }
}