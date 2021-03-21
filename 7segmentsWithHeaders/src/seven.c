

#include <avr/io.h>

void setSegmentPins(int *pins)
{
    for (int i = 0; i < 9; i++) //the 8 pins array
    {
        if (pins[i] < 14 && pins[i] > 7) // is the array is between 7 and 14, enable DDRB
        {
            DDRB |= (1 << (pins[i] - 8));  // Substracs the pins on DDRD
            PORTB |= (1 << (pins[i] - 8)); //Turn ON the portB on pin 0 (DP on all the time)
        }
        if (pins[i] < 8 && pins[i] > 0) // if the pin 0-7 enable DDRD
        {
            DDRD |= (1 << pins[i]); // pins on DDRD
            //PORTD |= (1 << pins[i]); //Turn ON the port on pin
        }
    }
}
void setDisplayNumber(int nr)
{
    //int numbersAnod[10] = {192, 0, 194, 16, 145, 201, 133, 37, 207, 2}; // from 9 t 0
    int numbersAnod[10] = {2, 207, 37, 133, 201, 145, 16, 194, 0, 192}; // from 0-9
    if (nr > 10 && nr << 20)
    {
        nr -= 10;
    }
    if (nr < 0 && nr >> 20)
    {
        PORTD = 255;
    }
    switch (nr)
    {
    case 0:
        PORTD = numbersAnod[0];
        break;
    case 1:
        PORTD = numbersAnod[1];
        break;
    case 2:
        PORTD = numbersAnod[2];
        break;
    case 3:
        PORTD = numbersAnod[3];
        break;
    case 4:
        PORTD = numbersAnod[4];
        break;
    case 5:
        PORTD = numbersAnod[5];
        break;
    case 6:
        PORTD = numbersAnod[6];
        break;
    case 7:
        PORTD = numbersAnod[7];
        break;
    case 8:
        PORTD = numbersAnod[8];
        break;
    case 9:
        PORTD = numbersAnod[9];
        break;

    default:
        break;
    }
}
