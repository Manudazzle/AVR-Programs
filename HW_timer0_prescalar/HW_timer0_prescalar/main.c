/*
 * GccApplication1.c
 *
 * Created: 23-03-2026 08:02:23 PM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	//step 1 : load 0 to TCNT0
	TCNT0 = 0;
	//step 2 : choosing normal mode: Mode0
	TCCR0A &= ~((1<< WGM01) | (1<<WGM00));
	TCCR0B &= ~(1<< WGM02);
	//step 3 : Selecting prescalar value: 1024
	TCCR0B &= ~(1<< CS01);
	TCCR0B |= (1<< CS00) | (1<<CS02);
	/*  Overflow Calculation
	
		1Fclk = 16MHZ = 16,000,000
		Prescalar = 1024
		New clock Frequency = 16000000/1024 = 15625
		1 tick = 1/15625 = 64 micro seconds
		For 256 ticks = 256*64 micro seconds = 16.384ms -> 1 overflow
		For 1s = 1/16.384ms = 61.035 -> overflow required for 1s delay	 
	*/
	for(uint16_t i=0; i<61.035; i++)
	{
		// Overflow check command
		while(!(TIFR0 & (1<<TOV0)));
		TIFR0 |= (1<<TOV0); // Clearing the bit by writing to 1
	}
}
int main(void)
{
	// Config as output
    DDRB |= (1<< DDB2);
	// Making low during starting
	PORTB &= ~(1<<PB2);
    while (1) 
    {
		PORTB ^=(1<<PB2);
		delay_1s();
    }
}

