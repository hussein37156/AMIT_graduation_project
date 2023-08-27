/*
 * M_external_interrupt.c
 *
 * Created: 4/27/2023 7:10:15 PM
 *  Author: husse
 */ 
#include "M_external_interrupt.h"
void M_external_interrupt_enable(external_interrupt_pin interrupt_pin,external_interrupt_trigger_edge triggered_edge){
	switch(interrupt_pin){
		case INT0_pin:
			clear_bit(DDRD,2);
			clear_reg_mask(MCUCR,0b00000011);
			set_reg_mask(MCUCR,triggered_edge);
			set_bit(GICR,6);//enable is the last step
		break;
		
		case INT1_pin:
			clear_bit(DDRD,3);
			clear_reg_mask(MCUCR,0b00001100);
			set_reg_mask(MCUCR,triggered_edge<<2);
			set_bit(GICR,7);//enable is the last step
		break;
		
		case INT2_pin:
			clear_bit(DDRB,2);
			if (triggered_edge==rinsing_edge)
			{
				set_bit(MCUCSR,6);
			} 
			else if(triggered_edge==falling_edge)
			{
				clear_bit(MCUCSR,6);
			}
			set_bit(GICR,5);//enable is the last step
		break;
	}
	sei();
}
void M_external_interrupt_disable(external_interrupt_pin interrupt_pin){
	switch(interrupt_pin){
		case INT0_pin:
			clear_bit(GICR,6);
		break;
		
		case INT1_pin:
			clear_bit(GICR,7);
		break;
		
		case INT2_pin:
			clear_bit(GICR,5);
		break;
	}
}


