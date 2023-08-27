/*
 * DIO.c
 *
 * Created: 4/11/2023 7:50:24 PM
 *  Author: husse
 */ 

#include "M_DIO.h"

//pin operations
void M_DIO_set_pin_direction(DIO_port_name port ,int pin_num,DIO_pin_direction direction){
	switch(port){
		case A:
			if (direction==input){clear_bit(DDRA,pin_num);}
			else if(direction==output){set_bit(DDRA,pin_num);}
		break;
		
		case B:
			if (direction==input){clear_bit(DDRB,pin_num);}
			else if(direction==output){set_bit(DDRB,pin_num);}
		break;
		
		case C:
			if (direction==input){clear_bit(DDRC,pin_num);}
			else if(direction==output){set_bit(DDRC,pin_num);}
		break;
		
		case D:
			if (direction==input){clear_bit(DDRD,pin_num);}
			else if(direction==output){set_bit(DDRD,pin_num);}
		break;
	}
}
void M_DIO_set_pin_value(DIO_port_name port ,int pin_num,DIO_pin_state state){
	switch(port){
		case A:
			if (state==high){set_bit(PORTA,pin_num);} 
			else if(state==low){clear_bit(PORTA,pin_num);}
		break;
		
		case B:
		if (state==high){set_bit(PORTB,pin_num);}
		else if(state==low){clear_bit(PORTB,pin_num);}
		break;
		
		case C:
		if (state==high){set_bit(PORTC,pin_num);}
		else if(state==low){clear_bit(PORTC,pin_num);}
		break;
		
		case D:
		if (state==high){set_bit(PORTD,pin_num);}
		else if(state==low){clear_bit(PORTD,pin_num);}
		break;
	}
}
void M_DIO_toggle_pin(DIO_port_name port ,int pin_num){
	switch(port){
		case A:
			toggle_bit(PORTA,pin_num);
		break;
		
		case B:
			toggle_bit(PORTB,pin_num);
		break;
		
		case C:
			toggle_bit(PORTC,pin_num);
		break;
		
		case D:
			toggle_bit(PORTD,pin_num);
		break;
	}
}
DIO_pin_state M_DIO_read_pin_state(DIO_port_name port ,int pin_num){
	DIO_pin_state state=low;
	switch(port){
		case A:
			state=read_bit(PINA,pin_num);
		break;
		
		case B:
			state=read_bit(PINB,pin_num);
		break;
		
		case C:
			state=read_bit(PINC,pin_num);
		break;
		
		case D:
			state=read_bit(PIND,pin_num);
		break;
	}
	return state;
}


//port operations
void M_DIO_clear_port(DIO_port_name port){
	switch(port){
		case A:
			clear_reg(PORTA);
		break;
		
		case B:
			clear_reg(PORTB);
		break;
		
		case C:
			clear_reg(PORTC);
		break;
		
		case D:
			clear_reg(PORTD);
		break;
	}
}
void M_DIO_set_port_direction(DIO_port_name port ,DIO_pin_direction direction){
	switch(port){
		case A:
			if (direction==output){set_reg(DDRA);} 
			else if(direction==input){clear_reg(DDRA);}
		break;
		
		case B:
			if (direction==output){set_reg(DDRB);}
			else if(direction==input){clear_reg(DDRB);}
		break;
		
		case C:
			if (direction==output){set_reg(DDRC);}
			else if(direction==input){clear_reg(DDRC);}
		break;
		
		case D:
			if (direction==output){set_reg(DDRD);}
			else if(direction==input){clear_reg(DDRD);}
		break;
		}
}
void M_DIO_set_port_value(DIO_port_name port,u8 val){
	switch(port){
		case A:
			set_reg_value(PORTA,val);
		break;
		
		case B:
			set_reg_value(PORTB,val);
		break;
		
		case C:
			set_reg_value(PORTC,val);
		break;
		
		case D:
			set_reg_value(PORTD,val);
		break;
	}
}
void M_DIO_set_port_direction_mask(DIO_port_name port,DIO_pin_direction direction,u8 mask){
	switch(port){
		case A:
			if (direction==output){set_reg_mask(DDRA,mask);} 
			else if(direction==input){clear_reg_mask(DDRA,mask);}
		break;
		
		case B:
			if (direction==output){set_reg_mask(DDRB,mask);}
			else if(direction==input){clear_reg_mask(DDRB,mask);}
		break;
		
		case C:
			if (direction==output){set_reg_mask(DDRC,mask);}
			else if(direction==input){clear_reg_mask(DDRC,mask);}
		break;
		
		case D:
			if (direction==output){set_reg_mask(DDRD,mask);}
			else if(direction==input){clear_reg_mask(DDRD,mask);}
		break;
	}
}
void M_DIO_set_port_value_mask(DIO_port_name port,u8 mask){
	switch(port){
		case A:
			set_reg_mask(PORTA,mask);
		break;
		
		case B:
			set_reg_mask(PORTB,mask);
		break;
		
		case C:
			set_reg_mask(PORTC,mask);
		break;
		
		case D:
			set_reg_mask(PORTD,mask);
		break;
	}
}
void M_DIO_clear_port_mask(DIO_port_name port,u8 mask){
	switch(port){
		case A:
			clear_reg_mask(PORTA,mask);
		break;
		
		case B:
			clear_reg_mask(PORTB,mask);
		break;
		
		case C:
			clear_reg_mask(PORTC,mask);
		break;
		
		case D:
			clear_reg_mask(PORTD,mask);
		break;
	}
}