#include <avr/io.h> // this give us acces to input output pins
#include <stdlib.h>

int main()
{
  int i;
  int buttonDown = 0; // FLAG
  //int numbersCathode[10] = {126, 254, 60, 238, 110, 54, 122, 218, 48, 252};
  int numbersAnod[10] = {192, 0, 194, 16, 145, 201, 133, 37, 207, 2};

  DDRB = 0;
  DDRD = 255; // DDRB are set to  DDRB= 11111111   // 1 represent output and 0 input
  PORTD = 255;
  while (1)
  {
    if (PINB & 1 << PB5)
    {
      if (buttonDown < 1)
      {
        PORTD = numbersAnod[rand() % 10];
      }
      buttonDown = 1;
    }
    else
    {
      buttonDown = 0;
    }
  }
  return 0;
}