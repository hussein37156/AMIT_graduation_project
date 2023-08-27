/*
 * Servo.c
 *
 * Created: 8/25/2023 12:38:59 AM
 *  Author: husse
 */ 
#include "Servo.h"

void H_Servo_init(void){
	M_Timer_2_init(PWM);
	M_Timer_2_start(prescaler);
}

void H_Servo_angle(u8 angle){
	M_Timer_2_PWM(((angle*31)/90)+62);	
}