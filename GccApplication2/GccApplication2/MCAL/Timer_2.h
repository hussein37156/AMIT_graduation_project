/*
 * Timer_2.h
 *
 * Created: 8/25/2023 6:49:45 PM
 *  Author: husse
 */ 


#ifndef TIMER_2_H_
	#define TIMER_2_H_
	#include "../UTIL/macros.h"
	#include "../UTIL/data_types.h"
	#include "../CPU_configuration.h"
	#include <avr/interrupt.h>


	typedef enum
	{
		normal,
		CTC,
		PWM
	}wave_form_generator_mode;
	
	void M_Timer_2_init(wave_form_generator_mode mode);
	void M_Timer_2_start(u8 prescaler);
	void M_Timer_2_PWM(u8 PWM_value);




#endif /* TIMER_2_H_ */