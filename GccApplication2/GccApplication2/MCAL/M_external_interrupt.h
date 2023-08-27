/*
 * M_external_interrupt.h
 *
 * Created: 4/27/2023 7:10:48 PM
 *  Author: husse
 */ 


#ifndef M_EXTERNAL_INTERRUPT_H_
	#define M_EXTERNAL_INTERRUPT_H_
	#include <avr/io.h>
	#include "../UTIL/macros.h"
	#include "../UTIL/data_types.h"
	#include <AVR/interrupt.h>
	typedef enum{
		INT0_pin,
		INT1_pin,
		INT2_pin	
	}external_interrupt_pin;

	typedef enum 
	{
		low_level,
		logic_change,
		falling_edge,
		rinsing_edge
	}external_interrupt_trigger_edge;

	void M_external_interrupt_enable(external_interrupt_pin interrupt_pin,external_interrupt_trigger_edge triggered_edge);
	void M_external_interrupt_disable(external_interrupt_pin interrupt_pin);

#endif /* M_EXTERNAL_INTERRUPT_H_ */