/*
 * ultrasonic.h
 *
 * Created: 8/27/2023 6:38:07 PM
 *  Author: husse
 */ 


#ifndef ULTRASONIC_H_
	#define ULTRASONIC_H_
	#include "../MCAL/Timer_1.h"
	#include "../MCAL/M_DIO.h"
	#include "../CPU_configuration.h"
	#include <util/delay.h>
	typedef struct MyStruct
	{
		DIO_port_name port;
		int triger;
	}ultrasonic_object;

	void H_ultrasonic_init(ultrasonic_object UTS);
	u8 H_ultrasonic_measure(ultrasonic_object UTS);

#endif /* UTRASONIC_H_ */