#include <stdbool.h>
#include <stdint.h>

#include "nrf_delay.h"
#include "boards.h"

#include "project_config.h"
#include "led.h"


int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);
    struct BlinkyConfig config;
    blinky_init(&config);

    while (true)
    {
        serial_blinking(config);
        nrf_delay_ms(LED_CYCLE_END_DELAY);
    }
}