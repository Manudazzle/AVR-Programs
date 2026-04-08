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
	DDRC |= (1<<DDC1);
    while (1) 
    {
		if (PIND & (1<<PIND4))
		{
			PORTC |= (1<<PC1); //High
		}
		else
		{
			PORTC &= ~(1<<PC1); //Low
		}
		
    }
}

