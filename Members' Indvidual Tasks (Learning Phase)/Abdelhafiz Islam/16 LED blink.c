/*
 */

#include <avr/io.h>
#define F_CPU 1000000UL
#inlucde <avr/delay.h>
int main(void)
{

    // this code makes 16 LED blink 8 each a time
    DDRA 0b11111111;
    DDRB 0b11111111;
    while(1)
    {
        PORTA 0b11111111;
        _delay_ms(500);
        PORTA 0b00000000;
        _delay_ms(500)
        PORTB 0b11111111;
        _delay_ms (500);
        PORTB 0b00000000;
        _delay_ms(500);
    }

    return 0;
}
