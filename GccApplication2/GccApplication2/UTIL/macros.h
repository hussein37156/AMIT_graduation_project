/*
 * macros.h
 *
 * Created: 4/11/2023 3:14:38 PM
 *  Author: husse
 */ 


#ifndef MACROS_H_
	#define MACROS_H_
	
	//bit operations
	#define set_bit(reg,bit_num)		reg=reg|(1<<bit_num)
	#define toggle_bit(reg,bit_num)		reg=reg^(1<<bit_num)
	#define clear_bit(reg,bit_num)		reg=reg&~(1<<bit_num)
	#define read_bit(reg,bit_num)		(1&(reg>>bit_num))
	
	//register operations
	#define set_reg_value(reg,val)		reg=val
	#define set_reg(reg)				reg=255  //0b11111111
	#define toggle_reg(reg)				reg=~reg
	#define clear_reg(reg)				reg=0
	
	//mask
	#define  set_reg_mask(reg,mask)		reg=reg|mask		// 0b00000101
	#define  clear_reg_mask(reg,mask)	reg=reg&~mask		// 0b00000101
		
	
	





#endif /* MACROS_H_ */