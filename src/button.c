#include "button.h"

void esl_button_init()
{
    nrf_gpio_cfg_input(ESL_MAIN_BUTTON, NRF_GPIO_PIN_PULLUP);
}

bool esl_get_button_state(esl_button_t button)
{
    return nrf_gpio_pin_read(button) ? 0 : 1;
}