/*
 * led_blink_bitwise.c
 *
 * Created: 17-03-2026 08:10:27 PM
 * Author : Manu
 */ 

#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//config DDRD PIN3 and PIN1 as OUTPUT
    DDRD  |= ((1 << DDD3)|(1 << DDD1));
    while (1) 
    {
		//Making pins HIGH PD1 and PD3
		PORTD |= ((1 << PD3)|(1 << PD1));
		_delay_ms(1000);
		
		 //Making pins LOW PD1 and PD3
		PORTD &= ~((1<<PD3)|(1 << PD1));
		_delay_ms(1000); 
		
		// HOME WORK:
		// Making pins LOW by Toggle
		PORTD ^= ((1 << PD3)|(1 << PD1));
		_delay_ms(2000);
    }
}

