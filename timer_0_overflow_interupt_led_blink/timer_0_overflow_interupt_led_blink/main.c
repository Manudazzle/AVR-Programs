/*
 * timer_0_overflow_interupt_led_blink.c
 *
 * Created: 07-04-2026 09:04:09 PM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h> //Header required when using interrupts
volatile uint16_t count = 0;


/*
		Fclk = 16MHZ
		Prescalar: 64
		New clock frequency = 16000000/64 = 250000
		1 Tick = 1/250000 = 4 microseconds
		For 256 ticks = 256 * 4 microseconds = 1.024ms
		For 1s = 1/1.024ms = 976
		
	*/
	
ISR(TIMER0_OVF_vect)
{
	if(count >= 976)
	{
		PORTB ^= (1<<PB2);
		count = 0;
	}
	else
	{
		count++;
	}
	
}
void timer0_interrupt_init()
{
	//Step1: Enabling Global Interrupt
	sei();
	
	//step 2 : Configuring Timer0 in normal mode: Mode0
	TCCR0A &= ~((1<< WGM00) | (1<<WGM01));
		
	//Step 3: Selecting Prescalar: 64
	TCCR0B |= (1<<CS01) | (1<<CS00);
	TCCR0B &= ~(1<<CS02);
		
	//Step4: Timer0 overflow interrupt
	TIMSK0 |= (1<<TOIE0);
}

int main(void)
{
	timer0_interrupt_init();
	DDRB |= (1<<DDB1) | (1<<DDB2);
	PORTB &= ~((1<<PB1) | (1<<PB2));
	
    while (1) 
    {
		PORTB |= (1<<PB1);
	}
}

