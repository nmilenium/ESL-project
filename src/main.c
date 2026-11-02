#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"
#include "led.h"
#include "project_config.h"

int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);
    struct BlinkyConfig config;
    blinky_init(&config);

    while (true)
    {
        serial_blinking(config);
        nrf_delay_ms(5000);
    }
}