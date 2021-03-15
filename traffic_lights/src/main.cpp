#include <avr/io.h> // this give us acces to input output pins
#include <util/delay.h>

int main()
{
  // DDR = Data direction registry
  // There are 3 in this micro controller
  // DDRB,DDRC,DDRD
  // IMPORTANT every DDR is one byte = 8bits = 11111111 // Also DDRB is direct conected to PORTB
  //DDRB = 11111111/0000000
  //Set DDRB as output

  DDRB = 255; // DDRB are set to  DDRB= 11111111   // 1 represent output and 0 input
  while (1)
  {
    // PORT is another register, there are 3 PORTB, PORTC, PORTD each 1 byte= 8 bits
    // turn OFF PB4
    PORTB &= ~(1 << PB4);
    //PORTB = 255; // in this microcontroller there are 3 ports PORTB,PORTC, PORTD
    //start lit  PB5
    PORTB = PORTB | 1 << PB5;
    //wait 0.5 seconds
    _delay_ms(3000);

    // turn OFF PB5
    PORTB = PORTB & ~1 << PB5;
    //tur ON PB4
    PORTB |= 1 << PB4; // this is the same as PORTB = PORB |1 << PB4;
    _delay_ms(2000);
    // Turn on PB0 Green Light
    PORTB |= 1 << PB0;
    // turn OFF PB4  Yellow
    PORTB &= ~(1 << PB4);
    // wait 1 s
    _delay_ms(5000);

    PORTB &= ~(1 << PB0);
    PORTB += 1 << PB4;
    PORTB += 1 << PB5;
    _delay_ms(2000);

    //turn OFF PB4
    PORTB = 0; //turns off PORTB
  }
  return 0;
}