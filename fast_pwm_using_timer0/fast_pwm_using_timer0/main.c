/*
 * fast_pwm_using_timer0.c
 *
 * Created: 01-04-2026 03:09:48 PM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void fast_pwm_init()
{
	//Step 1: config PD6(OCR0A) as output
	DDRD |= (1<<DDD6);
	//Step 2: Selecting Fast PWM mode
	TCCR0A |= (1<<WGM00) | (1<<WGM01);
	TCCR0B &= ~(1<<WGM02);
	//Step 3: Choosing Non-inverting mode
	TCCR0A &= ~(1<<COM0A0);
	TCCR0A |= (1<<COM0A1);
	//Step 4: Selecting Prescalar: 64
	TCCR0B |= (1<<CS01) | (1<<CS00);
	TCCR0B &= ~(1<<CS02);
	/* 
	  Fast PWM mode = Fclk / (N*256)
	  N= 64
	  Fclk = 16000000
	  Fast PWM mode = 16000000/ (64*256)
					= 976.5 ~= 1KHZ
	*/
	
	//Step 5: Setting the value in OCR0A
	/*
		256* (%value / 100)
		256*(50 / 100) = 128
	*/
	// 50% Duty Cycle
	//OCR0A = 128;
	OCR0A = 0;
		
}

int main(void)
{
    fast_pwm_init();
    while (1) 
    {
		for(uint16_t i=0; i<=255; i++)
		{
			OCR0A = i;
			_delay_ms(20);
		}
	}
}