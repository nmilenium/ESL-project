#include <blinky.h>


int main(void)
{
    struct BlinkyConfig config;
    blinky_init(&config);

    while (1)
    {
       serial_blinking(config);
    }
}