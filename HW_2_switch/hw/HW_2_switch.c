/*
 * hw.c
 *
 * Created: 23-03-2026 03:02:50 PM
 * Author : PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//config PIND1 and PIND2 as Input 1 and 2
	DDRD |= ((1 << DDD2) | (1 << DDD3));
	
	//confi PINC2 as input
	DDRC &= ~((1<<DDC2) | (1<<DDC1));
	
	//Enable internal pull up
	PORTC |= ((1<<DDC2) | (1<<DDC1));
	
	while (1)
	{
		if (!(PINC & (1<<PINC2)))
		{
			//Motor ON
			PORTD |= (1 << PD2); // high
			PORTD &= ~(1 << PD3); //low
			
		}
		else
		{
			//Motor OFF
			PORTD &= ~(1 << PD3); //high
			PORTD &= ~(1 << PD2); // low
			
		}
		if (!(PINC & (1<<PINC1)))
		{
			// clockwise direction
			PORTD |= (1<<PD2);
			PORTD &= ~(1<<PD3);
			_delay_ms(1000);
			
			//Anti clockwise direction
			PORTD |= (1<<PD3);
			PORTD &= ~(1<<PD2);
			_delay_ms(1000);
			
		}
	}
}
