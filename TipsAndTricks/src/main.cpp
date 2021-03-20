#define LEDPIN PB5;


#include <avr/io.h>

int main()
{
    DDRD =255;
    PORTB |= LEDPIN;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    return 0;
}