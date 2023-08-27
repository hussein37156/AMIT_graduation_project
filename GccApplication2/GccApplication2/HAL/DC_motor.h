/*
 * DC_motor.h
 *
 * Created: 8/27/2023 2:03:12 PM
 *  Author: husse
 */ 


#ifndef DC_MOTOR_H_
	#define DC_MOTOR_H_
	#include "../MCAL/M_DIO.h"
	typedef struct 
	{
		DIO_port_name port;
		int pin_1;
		int pin_2;
	}DC_motor_object;
	
	void H_DC_motor_init(DC_motor_object DC_motor);
	void H_DC_motor_forward(DC_motor_object	DC_motor);
	void H_DC_motor_backward(DC_motor_object DC_motor);
	void H_DC_motor_stop(DC_motor_object DC_motor);




#endif /* DC_MOTOR_H_ */