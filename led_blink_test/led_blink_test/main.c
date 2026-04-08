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
	// PORTD pin config - PIN2 - OUTPUT
    DDRD = 0b00000100; 
    while (1) // true
    {
		//PORT PIN2 HIGH
		PORTD = 0b00000100; //Turn ON all LED
		_delay_ms(1000);
		PORTD = 0b0000000; //Turn OFF all LED
		_delay_ms(1000);
    }
}

