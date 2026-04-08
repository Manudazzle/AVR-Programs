/*
 * led_blink_test.c
 *
 * Created: 17-03-2026 11:57:53 AM
 * Author : PC
 */ 
#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// PORTD pin config - PIN 1,3,5,7 - Set as OUTPUT
    DDRD = 0b10101010;
	
    while (1) // true
    {
		PORTD = 0b00000010; //Turn ON PIN1
		_delay_ms(1000); 
		PORTD = 0b0000000; //Turn OFF PIN1
		_delay_ms(1000);
		
		PORTD = 0b00001000; //Turn ON PIN3
		_delay_ms(1000);
		PORTD = 0b0000000; //Turn OFF PIN3
		_delay_ms(1000);
		
		PORTD = 0b00100000; //Turn ON PIN5
		_delay_ms(1000);
		PORTD = 0b0000000; //Turn OFF PIN5
		_delay_ms(1000);
		
		PORTD = 0b10000000; //Turn ON PIN7
		_delay_ms(1000);
		PORTD = 0b0000000; //Turn OFF PIN7
		_delay_ms(1000);
    }
}

