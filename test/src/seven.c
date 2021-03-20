#include <avr/io.h>

//int segment_pins[] = {13, 12, 11, 10, 7, 6, 5, 4};

void setPin(int pin, int mode)
{
    if (pin < 14 && pin > 7)
    {
        //turn pin on
        if (mode > 0)
        {
            PORTB |= (1 << PB5);
        }
    }
}
