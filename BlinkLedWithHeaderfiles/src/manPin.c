#include <avr/io.h>
#include "manPin.h"
void setPin(int pin, int mode)
{
    if (mode == HIGH)
    {
        if (pin < 14 && pin > 7)
        {
            DDRB |= (1 << (pin - 8));  // Substracs the pins on DDRD
            PORTB |= (1 << (pin - 8)); //Turn ON the port on pin
        }
        if (pin < 8 && pin > 0)
        {
            DDRD |= (1 << pin);  // pins on DDRD
            PORTD |= (1 << pin); //Turn ON the port on pin
        }
    }
    else
    {
        if (pin < 14 && pin > 7)
        {
            DDRB |= (1 << (pin - 8));   // Substracs the pins on DDRD
            PORTB &= ~(1 << (pin - 8)); //Turn OFF the port on pin
        }
        if (pin < 8 && pin > 0)
        {
            DDRD |= (1 << pin);   // pins on DDRD
            PORTD &= ~(1 << pin); //Turn OFF the port on pin
        }
    }
}