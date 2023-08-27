/*
 * Servo.h
 *
 * Created: 8/25/2023 12:39:15 AM
 *  Author: husse
 */ 


#ifndef SERVO_H_
	#define SERVO_H_
	#include "../CPU_configuration.h"
	#include "../MCAL/Timer_2.h"
	#include "../UTIL/data_types.h"
	#define prescaler 6
	void H_Servo_init(void);
	void H_Servo_angle(u8 angle);


#endif /* SERVO_H_ */