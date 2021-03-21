#include <avr/io.h> // this give us acces to input output pins
#include <util/delay.h>
extern "C"
{
#include "seven.h"
}

int main()
{

  // SEGMENT A,B,C,D,E,F,G,DP
  int pins[] = {1, 2, 3, 4, 5, 6, 7, 8}; // This is how i have connect my seven segments display
  //int pins[] = {Seg_A, Seg_B, Seg_C, Seg_D, Seg_E, Seg_F, Seg_G, Seg_DP}; // This is how i have connect my seven segments display
  setSegmentPins(pins);
  while (1)
  {
    for (int i = 0; i < 10; i++)
    {
      setDisplayNumber(i);
      _delay_ms(1000);
      PORTD = 255;
    }
  }

  return 0;
}