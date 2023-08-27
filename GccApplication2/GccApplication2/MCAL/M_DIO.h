/*
 * DIO.h
 *
 * Created: 4/11/2023 7:50:11 PM
 *  Author: husse
 */ 


#ifndef DIO_H_
	#define DIO_H_
	#include <avr/io.h>
	#include "../UTIL/data_types.h"
	#include "../UTIL/macros.h"
	
	
	typedef enum{
		A,
		B,
		C,
		D
	}DIO_port_name;
	
	typedef enum{
		input,
		output
	}DIO_pin_direction;
	
	typedef enum{
		low,
		high
	}DIO_pin_state;
	
	void M_DIO_set_pin_direction(DIO_port_name port ,int pin_num,DIO_pin_direction direction);
	void M_DIO_set_pin_value(DIO_port_name port ,int pin_num,DIO_pin_state state);
	void M_DIO_toggle_pin(DIO_port_name port ,int pin_num);
	DIO_pin_state M_DIO_read_pin_state(DIO_port_name port ,int pin_num);
	void M_DIO_clear_port(DIO_port_name port);
	void M_DIO_set_port_direction(DIO_port_name port ,DIO_pin_direction direction);
	void M_DIO_set_port_value(DIO_port_name port,u8 val);
	void M_DIO_set_port_direction_mask(DIO_port_name port,DIO_pin_direction direction,u8 mask);
	void M_DIO_set_port_value_mask(DIO_port_name port,u8 mask);
	void M_DIO_clear_port_mask(DIO_port_name port,u8 mask);


#endif /* DIO_H_ */