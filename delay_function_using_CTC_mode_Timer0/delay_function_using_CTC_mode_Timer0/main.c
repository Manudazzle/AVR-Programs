/*
 * delay_function_using_CTC_mode_Timer0.c
 *
 * Created: 30-03-2026 01:15:10 PM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
void delay_1s(void)
{
	//Step 1: load 0 to TCNT0
	TCNT0 = 0;
	//Step 2: Selecting CTC mode
	TCCR0A &= ~(1<<WGM00);
	TCCR0A |= (1<<WGM01);
	//Step 3: Selecting prescalar value: 64
	TCCR0B |= (1<<CS00) | (1<<CS01);
	TCCR0B &= ~(1<<CS02);
	
	/* Calculation Part
		
		// Method - 1
		1Fclk = 16MHZ = 16000000
		Prescalar value: 64
		New cloack frequency = 16000000/64 = 250000
		1 tick = 1/250000 = 4 microsecond
		1 ms = 1000 micro second 
		1000/4 = 250  // Need to be 0-255 or Take another prescalar
		250 - 1 = 249 -> Value to be loaded
		
		//  Method - 2
		OCR0A = (fclock / (prescalar*frequency)) - 1
		
		( 1 ms = 1*10^-3
		  Frequency = 1/time period = 1/1*10^-3 = 1000)
		
		OCR0A = (16000000 / (64*1000)) -1
			  = 250-1
			  = 249
	*/
	
	OCR0A = 249;
	for(uint16_t i=0; i<1000; i++)
	{
		while(!(TIFR0 & (1<<OCF0A)));
		TIFR0 |= (1<<OCF0A);
	}	
}


int main(void)
{
	//Config as output
    DDRB |= (1<<DDB5);
	// Making low during starting
	PORTB &= ~(1<<PB5);
    while (1) 
    {
		PORTB ^= (1<<PB5);
		delay_1s();
    }
}

