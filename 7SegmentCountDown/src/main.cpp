#include <avr/io.h> // this give us acces to input output pins
#include <util/delay.h>

void nr9()
{
  PORTD = 126;
  _delay_ms(1000);
  PORTD = 0;
}

void nr8()
{
  PORTD = 254;
  _delay_ms(1000);
  PORTD = 0;
}

void nr7()
{
  PORTD = 60;
  _delay_ms(1000);
  PORTD = 0;
}

void nr6()
{
  PORTD = 238;
  _delay_ms(1000);
  PORTD = 0;
}

void nr5()
{
  PORTD = 110;
  _delay_ms(1000);
  PORTD = 0;
}

void nr4()
{
  PORTD = 54;
  _delay_ms(1000);
  PORTD = 0;
}

void nr3()
{
  PORTD = 122;
  _delay_ms(1000);
  PORTD = 0;
}

void nr2()
{
  PORTD = 218;
  _delay_ms(1000);
  PORTD = 0;
}

void nr1()
{
  PORTD = 48;
  _delay_ms(1000);
  PORTD = 0;
}

void nr0()
{
  PORTD = 252;
  _delay_ms(1000);
  PORTD = 0;
}

int main()
{

  DDRB = 255; // DDRB are set to  DDRB= 11111111   // 1 represent output and 0 input
  while (1)
  {
    nr9();
    nr8();
    nr7();
    nr6();
    nr5();
    nr4();
    nr3();
    nr2();
    nr1();
    nr0();
  }
  return 0;
}