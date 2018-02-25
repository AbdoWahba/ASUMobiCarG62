/*
 */

#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/delay.h>
int main(void)
{

DDRA=0b00000001 ;       // Insert code

    while(1)
    {
        PORTA=0b00000001;
        _delay_ms(500);
        PORTA=0b00000001;
        _delay_ms(500);
    }
return 0 ;
}
