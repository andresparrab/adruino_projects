#include <avr/io.h> // this give us acces to input output pins
#include <stdlib.h>
#include <util/delay.h>
extern "C"
{
#include "manPin.h"
}

int main()
{

  // SEGMENT A,B,C,D,E,F,G,DP
  //int pins[] = {13, 12, 11, 10, 7, 6, 5, 4}; // This is how i have connect my seven segments display
  //setSegmentPins(pins);
  //number(5);
  setPin(13, HIGH);
  _delay_ms(1000);
  setPin(13, LOW);
  _delay_ms(1000);

  return 0;
}