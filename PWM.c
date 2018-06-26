
#include "PWM.h"

void PWM_init(){
	
	#if (EN_TIMER0)
	
		/* PWM Mode  WGM00:1 = 1:0  | FOC0 = 0 */
		CLEARBIT(TCCR0,WGM01);
		SETBIT(TCCR0,WGM00);
		CLEARBIT(TCCR0,FOC0);

		/* Prescaling "8" CS00:1:2 = 0:1:0 */
		CLEARBIT(TCCR0,CS02);
		CLEARBIT(TCCR0,CS00);
		SETBIT(TCCR0,CS01);
	
		/*  COM00:1 = 0:1    --> Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. */
		SETBIT(TCCR0,COM01);
		CLEARBIT(TCCR0,COM00);
	
		SETBIT(DDRB,PB3); /* Set PB3/OC0 to be output */
	
	#endif
	
	#if (EN_TIMER1)
	
		/* Timer1 Config */
		
		/* PWM Mode 8bit  WGM10:1:2:3 = 1000  | FOC1A:B = 0 */
		SETBIT(TCCR1A,WGM10);
		CLEARBIT(TCCR1A,WGM11);
		CLEARBIT(TCCR1B,WGM12);
		CLEARBIT(TCCR1B,WGM13);
		
		CLEARBIT(TCCR1A,FOC1A);
		CLEARBIT(TCCR1A,FOC1B);
		
		/* Prescaling "8" CS10:1:2 = 0:1:0 */
		SETBIT(TCCR1B,CS11);
		CLEARBIT(TCCR1B,CS10);
		CLEARBIT(TCCR1B,CS12);
		
		/* COM1A0|COM1B0 = 0 | COM1A1|COM1B1 = 1   --> Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. */
		CLEARBIT(TCCR1A,COM1A0);
		CLEARBIT(TCCR1A,COM1B0);
		SETBIT(TCCR1A,COM1A1);
		SETBIT(TCCR1A,COM1B1);
		
		
		/* PIN Config */
		

		SETBIT(DDRD,PD5); /* Set PD5 to be output */
		SETBIT(DDRD,PD4); /* Set PD4 to be output */
	
	#endif
	
	#if (EN_TIMER2)
	
		/* PWM Mode  WGM00:1 = 1:0  | FOC0 = 0 */
		CLEARBIT(TCCR2,WGM21);
		SETBIT(TCCR2,WGM20);
		CLEARBIT(TCCR2,FOC2);

		/* Prescaling "8" CS00:1:2 = 0:1:0 */
		CLEARBIT(TCCR2,CS22);
		CLEARBIT(TCCR2,CS20);
		SETBIT(TCCR2,CS21);
		
		/*  COM00:1 = 0:1    --> Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. */
		SETBIT(TCCR2,COM21);
		CLEARBIT(TCCR2,COM20);
		
		SETBIT(DDRD,PD7); /* Set PB3/OC0 to be output */
	
	#endif
}

void analogWrite(uint8_t PIN , uint8_t DC){

	if( PIN == PB3 ){
		OCR0 = DC;
	}
	
	else if( PIN == PD5 ){
		OCR1A = DC;
	}
	
	else if( PIN == PD4 ){
		OCR1B = DC;
	}
	
	else if( PIN == PD7 ){
		OCR2 = DC;
	}
	
}

