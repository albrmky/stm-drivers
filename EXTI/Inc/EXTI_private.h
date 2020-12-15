/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 3 Sep 2020		*/
/* Version 	: V01				*/
/********************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


typedef	struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define	EXTI		(( EXTI_Type * )0X40010400)

#define ENABLE  1
#define DISABLE 0

#endif
