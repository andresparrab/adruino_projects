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
  int beweenSpeed = 150;
  DDRB = 255; // DDRB are set to  DDRB= 11111111   // 1 represent output and 0 input
  DDRD=255;
  while (1)
  {
    // PORT is another register, there are 3 PORTB, PORTC, PORTD each 1 byte= 8 bits
    // turn OFF PB4
    //PORTD &= ~(1 << PD3);		// turn OFF PB2  Yellow
    // PORTB = 255; // in this microcontroller there are 3 ports PORTB,PORTC, PORTD

    PORTB = PORTB | 1 << PB3; //Turn ON red lit  PB3
    _delay_ms(400);           //wait 0.5 seconds

    PORTB = PORTB & ~1 << PB3; // turn OFF PB3
    PORTB |= 1 << PB2;         //tur ON PB2 yellow light	// this is the same as PORTB = PORB |1 << PB4;

    _delay_ms(beweenSpeed);

    PORTB &= ~(1 << PB2); // turn OFF PB2  Yellow
    PORTB |= 1 << PB1;    // Turn ON PB1 Green Light

    _delay_ms(beweenSpeed); // wait 1 s

    PORTB &= ~(1 << PB1); // turn OFF PB2  Green
    PORTD |= 1 << PD6;    // Turn ON PD6 Blue Light

    _delay_ms(beweenSpeed); // wait 1 s

    PORTD &= ~(1 << PD6); // turn OFF PD6  Blue
    PORTD |= 1 << PD5;    // Turn ON PD5 White Light

    _delay_ms(beweenSpeed); // wait 1 s

    PORTD &= ~(1 << PD5); // turn OFF PD5  White
    PORTD += 1 << PD3;    //turn ON PD3 Orange light
    _delay_ms(400);

    PORTD &= ~(1 << PD3); // turn OFF PD3  Orange
    PORTD |= 1 << PD5;    // Turn ON PD5 White Light

    _delay_ms(beweenSpeed); // wait 1 s

    PORTD &= ~(1 << PD5); // turn OFF PD5  White
    PORTD |= 1 << PD6;    // Turn ON PD6 Blue Light

    _delay_ms(beweenSpeed); // wait 1 s

    PORTD &= ~(1 << PD6); // turn OFF PD6  Blue
    PORTB |= 1 << PB1;    // Turn ON PB3 Green Light

    _delay_ms(beweenSpeed); // wait 1 s

    PORTB &= ~(1 << PB1); // turn OFF PB3  Green
    PORTB |= 1 << PB2;    // Turn ON PB2 Yellow Light

    _delay_ms(beweenSpeed); // wait 1 s

    PORTB = 0; //turn OFF Last PORTB	//turns off PORTB
  }
  return 0;
}