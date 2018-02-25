/*
 */

#include <avr/io.h>
#define F_CPU 1000000UL
#inlucde <avr/delay.h>
int main(void)
{
    DDRA    0b00001111;

    // this code makes 4 LED blink seperatly

    while(1)
    {
        PORTA 0b00000001;
        _delay_ms(500);
        PORTA 0b00000010;
        _delay_ms(500);
        PORTA 0b00000100;
        _delay_ms (500);
        PORTA 0b00001000;
        _delay_ms (500);

    }


    return 0;
}
