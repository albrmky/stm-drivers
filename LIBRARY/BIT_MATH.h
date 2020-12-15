/********************************/
/* Author 	: Noureldeen	*/
/* Date 	: 29 Jul 2020	*/
/* Version 	: V01		*/
/********************************/


#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)		VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)		VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)		((VAR >> (BIT)) & 1)
#define TOG_BIT(VAR,BIT)		VAR ^=  (1 << (BIT))

#define INSERT_BIT(VAR,BIT,VAL)	VAR = (VAR & ~(1<<BIT)) + (VAL<<BIT)

#define INSERT_FIELD(REG, MASK, FIELD_VALUE, FIELD_START_BIT) REG = ( (REG & (~MASK) ) + (FIELD_VALUE<<FIELD_START_BIT) )


#endif
