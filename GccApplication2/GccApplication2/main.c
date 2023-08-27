/*
 * EEPROM.c
 *
 * Created: 7/14/2023 6:49:50 PM
 * Author : Hussein
 */ 
#include "CPU_configuration.h"
#include "UTIL/macros.h"
#include <util/delay.h>
#include "HAL/ultrasonic.h"
#include "HAL/DC_motor.h"
#include "HAL/Servo.h"

DC_motor_object DC_motor_right={A,4,5};
DC_motor_object DC_motor_left={A,7,6};


void car_farward(void){
	H_DC_motor_forward(DC_motor_right);
	H_DC_motor_forward(DC_motor_left);
}	

void car_backward(void){
	H_DC_motor_backward(DC_motor_right);
	H_DC_motor_backward(DC_motor_left);
}

void car_right(void){
	H_DC_motor_backward(DC_motor_right);
	H_DC_motor_forward(DC_motor_left);
}

void car_left(void){
	H_DC_motor_forward(DC_motor_right);
	H_DC_motor_backward(DC_motor_left);
}
	
void car_stop(void){
	H_DC_motor_stop(DC_motor_right);
	H_DC_motor_stop(DC_motor_left);
}

int main(void){
	ultrasonic_object UTS_1={A,0};
	H_Servo_init();
	H_ultrasonic_init(UTS_1);
	H_Servo_angle(90);	
	int angle;
	
	while (1)
	{
		
		if (H_ultrasonic_measure(UTS_1)>5){car_farward();}
		else{
			car_stop();
			H_Servo_angle(0);
			for (angle=0;angle<180;angle++){
				H_Servo_angle(angle);
				if (H_ultrasonic_measure(UTS_1)>5){
					H_Servo_angle(90);
					return angle;
				}
			}
			if (angle>=0 && angle<=90){car_right();}
			else{car_left();}
		}
		
	}
}
