#ifndef ESL_BUTTON_H
#define ESL_BUTTON_H

#include "nrf_gpio.h"

#define ESL_WAIT_UNTILL_BUTTON_IS_HOLDED \
    while(!esl_get_button_state(ESL_MAIN_BUTTON)) { }

typedef enum {
    ESL_MAIN_BUTTON = NRF_GPIO_PIN_MAP(1, 6)
} esl_button_t;

void esl_button_init();
bool esl_get_button_state(esl_button_t button);

#endif