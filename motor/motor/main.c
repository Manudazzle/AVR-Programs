/*
 * motor.c
 *
 * Created: 19-03-2026 08:23:56 PM
 * Author : PC
 */ 

//dc motor control
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//config PIND1 and PIND2 as Input 1 and 2
	DDRD |= ((1 << DDD1) | (1 << DDD2));
	
	while (1)
	{
		//clockwise direction
		PORTD |= (1 << PD1); // high
		PORTD &= ~(1 << PD2); //low
		_delay_ms(2000);
		//anti-clockwise direction
		PORTD |= (1 << PD2); //high
		PORTD &= ~(1 << PD1); // low
		_delay_ms(2000);
	}
}