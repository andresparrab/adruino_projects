#include <avr/io.h> // this give us acces to input output pins
#include <stdlib.h>
#include <util/delay.h>
//#include <Arduino.h>
#define Seg_A PD0
#define Seg_B PD1
#define Seg_C PD2
#define Seg_D PD3
#define Seg_E PD4
#define Seg_F PD5
#define Seg_G PD6
#define Seg_DP PD7

int hundreds, tenths, seconds, tenSeconds = 0;
int isCounting = 0;

void StartSequence()
{
  int waitTime = 3;
  PORTB |= (1 << PB0) | (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);
  for (int i = 0; i < waitTime; i++)
  {
    PORTD = 0B01111111;
    _delay_ms(500);
    PORTD = 0B11111111;
    _delay_ms(500);
  }
  hundreds = tenths = seconds = tenSeconds = 0;
  isCounting = 1;
}

void Increment()
{
  hundreds++;
  if (hundreds > 9)
  {
    hundreds = 0;
    tenths++;
  }
  if (tenths > 9)
  {
    tenths = 0;
    seconds++;
  }
  if (seconds > 9)
  {
    seconds = 0;
    tenSeconds++;
  }
  if (tenSeconds > 5)
  {
    tenSeconds = 0;
  }
}
void number(int nr)
{
  int segmentCombinations[] = {0B10000000,  //0
                               0B11110010,  //1
                               0B01001000,  //2
                               0B01100000,  //3
                               0B00110010,  //4
                               0B00100100,  //5
                               0B00000100,  //6
                               0B10110000,  //7
                               0B00000000,  //8
                               0B00110000}; //9
  PORTD = segmentCombinations[nr];
}
void Display(int nr)
{
  PORTB &= ~(1 << PB0) & (~1 << PB1) & (~1 << PB2) & (~1 << PB3);
  switch (nr)
  {
  case 0:
    PORTB |= (1 << PB3);
    break;
  case 1:
    PORTB |= (1 << PB2);
    break;
  case 2:
    PORTB |= (1 << PB1);
    break;
  case 3:
    PORTB |= (1 << PB0);
    break;

  default:
    break;
  }
}

int main()
{

  int i;
  int delayTime = 1000;
  int TimeCounter = 0;
  int buttonTimeCouner = 0;
  int buttonDown; // FLAG

  DDRD = 255; // DDRB are set to  DDRB= 11111111   // 1 represent output and 0 input
  DDRB = 0;
  DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);

  StartSequence();
  while (1)
  {
    number(hundreds);
    Display(0);
    _delay_us(delayTime);
    number(tenths);
    Display(1);
    _delay_us(delayTime);
    number(seconds);
    Display(2);
    _delay_us(delayTime);
    number(tenSeconds);
    Display(3);
    _delay_us(delayTime);

    if (PINB & 1 << PB5)
    {
      buttonTimeCouner++;
      if (buttonTimeCouner > 20) // this make sure you need to hold the button down 100ms before action happens
      {

        if (buttonDown == 0)
        {
          buttonDown = 1;
          if (isCounting == 0)
          {
            StartSequence();
          }
          else
          {
            isCounting = 0;
          }
        }
      }
    }
    else
    {
      buttonDown = 0;
      buttonTimeCouner = 0;
    }

    if ((PINB & (1 << PB5)) && (PINB & (1 << PB4))) // this take action if both buttons are down
    {
      Display(10);
      _delay_ms(1000);
    }

    TimeCounter++;
    if (TimeCounter >= 2)
    {
      if (isCounting == 1)
      {
        Increment();
      }

      TimeCounter = 0;
    }
  }
  return 0;
}