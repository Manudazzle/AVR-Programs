/*
 * pull_down_resistor.c
 *
 * Created: 21-03-2026 03:46:44 PM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	// Config as Input
    DDRD &= ~(1<<DDD4);
	// Config as Output
	DDRC |= (1<<DDC1) | (1<<DDC2) | (1<<DDC3);
    while (1) 
    {
		if ((PIND & (1<<PIND4)))
		{
			// RED LED
			PORTC = (1<<PC1); //High
			_delay_ms(2000);
		}
		
		if ((PIND & (1<<PIND4)))
		{
			// YELLOW LED
			PORTC = (1<<PC2); //High
			_delay_ms(2000);
			
		}
		
		if ((PIND & (1<<PIND4)))
		{
			// GREEN LED
			PORTC = (1<<PC3); //High
			_delay_ms(2000);
		}
		
		else
		{
			PORTC &= ~((1<<PC1) | (1<<PC2) | (1<<PC3)); //Low
		}
		
	}
}

