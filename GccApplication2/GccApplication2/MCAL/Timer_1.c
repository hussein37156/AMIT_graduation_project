/*
 * Timer_1.c
 *
 * Created: 8/27/2023 5:29:50 PM
 *  Author: husse
 */ 

#include "Timer_1.h"

u16 array[2];
static volatile int x=0;

void M_Timer_1_input_capture_unit_init(void){
	clear_bit(DDRD,6);
	set_reg_mask(TCCR1B,1);
	set_bit(TIMSK,5);
	sei();
}

u16 M_Timer_1_pulseIn(interruption_edge edge){
		
	if (edge==rinsing_edge)
	{
		set_bit(TCCR1B,6);
	}
	else if (edge==falling_edge)
	{
		clear_bit(TCCR1B,6);
	}
	return (array[1]-array[0]);
	
}

ISR(TIMER1_CAPT_vect){

	x++;
	if (read_bit(TCCR1B,6)==1)
	{
		array[0]=ICR1L;
	}
	else if (read_bit(TCCR1B,6)==0)
	{
		array[1]=ICR1;
	}
	toggle_bit(TCCR1B,6);
	toggle_bit(PORTC,2);
	
	
}