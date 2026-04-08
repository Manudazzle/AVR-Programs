/*
 * GccApplication1.c
 *
 * Created: 23-03-2026 10:32:33 AM
 * Author : PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// Config as Input
    DDRD &= ~(1<<DDD2);
	
	//Enabling internal PULL UP
	PORTD |= (1<<PD2);
	
	// Config as Output
	DDRC |= (1<<DDC2);
	
   /* while (1) 
    {
		if((PIND & (1<<PIND2)))
		{
			PORTC |= (1<<PC2);
		}
		else
		{
			PORTC &= ~(1<<PC2);
		}
    } */
   
   
   // Another paths for the program
   /*while (1)
   {
	   if(!(PIND & (1<<PIND2))) // ! NOT operator to reverse the current value (1 to 0)
	   {
		   PORTC |= (1<<PC2);
	   }
	   else
	   {
		   PORTC &= ~(1<<PC2);
	   }
   } */
   
   
   // Another paths for the program - To work push button as switch or hold the state 
   while(1)
   {
	   if(!(PIND & (1<<PIND2)))
	   {
		   PORTC ^= (1<<PC2);
		   while(!(PIND & (1<<PIND2)));
	   }
	   
   }
}

