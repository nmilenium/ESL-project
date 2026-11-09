#include "button.h"

void esl_button_init()
{
    nrf_gpio_cfg_input(ESL_MAIN_BUTTON, NRF_GPIO_PIN_PULLUP);
}

bool esl_get_button_state(esl_button_t button)
{
    return nrf_gpio_pin_read(button) ? 0 : 1;
}

void esl_wait_until_button_is_holded()
{
    while(!esl_get_button_state(ESL_MAIN_BUTTON)) { }
}