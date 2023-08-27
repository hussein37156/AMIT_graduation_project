/*
 * Timer_2.c
 *
 * Created: 8/25/2023 6:49:24 PM
 *  Author: husse
 */ 

#include "Timer_0.h"

void M_Timer_2_init(wave_form_generator_mode mode){
	if (mode==PWM)
	{
		set_reg_mask(TCCR2,0b01101000);
		set_bit(DDRD,7);
	}
}

void M_Timer_2_start(u8 prescaler){
	set_reg_mask(TCCR2,prescaler);
}

void M_Timer_2_PWM(u8 PWM_value){
	set_reg_value(OCR2,PWM_value);	
}