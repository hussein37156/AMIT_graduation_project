/*
 * DC_motor.c
 *
 * Created: 8/27/2023 2:02:54 PM
 *  Author: husse
 */ 
#include "DC_motor.h"


void H_DC_motor_init(DC_motor_object DC_motor){
	M_DIO_set_pin_direction(DC_motor.port,DC_motor.pin_1,output);
	M_DIO_set_pin_direction(DC_motor.port,DC_motor.pin_2,output);	
}

void H_DC_motor_forward(DC_motor_object	DC_motor){
	M_DIO_set_pin_value(DC_motor.port,DC_motor.pin_1,high);
	M_DIO_set_pin_value(DC_motor.port,DC_motor.pin_2,low);
}

void H_DC_motor_backward(DC_motor_object DC_motor){
	M_DIO_set_pin_value(DC_motor.port,DC_motor.pin_1,low);
	M_DIO_set_pin_value(DC_motor.port,DC_motor.pin_2,high);
}

void H_DC_motor_stop(DC_motor_object DC_motor){
	M_DIO_set_pin_value(DC_motor.port,DC_motor.pin_1,low);
	M_DIO_set_pin_value(DC_motor.port,DC_motor.pin_2,low);
}
