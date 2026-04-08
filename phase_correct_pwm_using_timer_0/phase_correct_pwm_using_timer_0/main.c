/*
 * phase_correct_pwm_using_timer_0.c
 *
 * Created: 07-04-2026 12:57:38 PM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void phase_pwm_init()
{
	//Step 1: config PD6(OCR0A) as output
	DDRD |= (1<<DDD6);
	
	// Motor direction
	DDRD |= (1<<DDD2) | (1<<DDD3); //config PD2 & PD3 as output
	PORTD |= (1<<PD2);  //Forward
	PORTD &= ~(1<<PD3);
	
	//Step 2: Selecting phase correct PWM mode
	TCCR0A |= (1<<WGM00);
	TCCR0A &= ~(1<<WGM01);
	TCCR0B &= ~(1<<WGM02);
	
	//Step 3: Choosing Non-inverting mode
	TCCR0A &= ~(1<<COM0A0);
	TCCR0A |= (1<<COM0A1);
	
	//Step 4: Selecting Prescalar: 8  (~= 3.9 KHZ)
	TCCR0B &= ~((1<<CS00) | (1<<CS02));
	TCCR0B |= (1<<CS01);
	/* 
	  Phase correct PWM mode = Fclk / (2*N*256)
	  N= 8
	  Fclk = 16000000
	  Phase correct PWM mode = 16000000/ (8*2*256)
							 = 3906.25 ~= 3.9KHZ
	*/
	
	//Step 5: Setting the value in OCR0A
	/*
	//  50% Duty Cycle - Motor need to be rotate at 50% speed as per question
		256* (%value / 100)
		256*(50 / 100) = 128
	*/
	
	OCR0A =128;
}

/*void motor_directon()
{
	// Motor direction
	DDRD |= (1<<DDD2) | (1<<DDD3);
	PORTD |= (1<<PD2);  //Forward
	PORTD &= ~(1<<PD3);
} */
int main(void)
{
    phase_pwm_init();
	//motor_directon();
	
    while (1) 
    {
		//0 to 128
		for(uint16_t i=0; i<=128; i++)
		{
			OCR0A = i;
			_delay_ms(10);
		}
		
		//128 to 0
		for(uint16_t i=128; i>0; i--)
		{
			OCR0A = i;
			_delay_ms(10);
		}
     }
}

