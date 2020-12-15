/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 3 Sep 2020		*/
/* Version 	: V01				*/
/********************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine);

void MEXTI0_voidSetCallBack(void (*ptr) (void));
void MEXTI1_voidSetCallBack(void (*ptr) (void));
void MEXTI2_voidSetCallBack(void (*ptr) (void));
void MEXTI3_voidSetCallBack(void (*ptr) (void));
void MEXTI4_voidSetCallBack(void (*ptr) (void));
void MEXTI5_9_voidSetCallBack(void (*ptr) (void));
void MEXTI10_15_voidSetCallBack(void (*ptr) (void));




#define		 EXTI_FALLING_EDGE		1
#define		 EXTI_RISING_EDGE		3
#define		 EXTI_ON_CHANGE			5

#define		 MEXTI_LINE0 			0
#define		 MEXTI_LINE1 			1
#define		 MEXTI_LINE2 			2
#define		 MEXTI_LINE3 			3
#define		 MEXTI_LINE4 			4
#define		 MEXTI_LINE5 			5
#define		 MEXTI_LINE6 			6
#define		 MEXTI_LINE7 			7
#define		 MEXTI_LINE8 			8
#define		 MEXTI_LINE9 			9
#define		 MEXTI_LINE10			10
#define		 MEXTI_LINE11			11
#define		 MEXTI_LINE12			12
#define		 MEXTI_LINE13			13
#define		 MEXTI_LINE14			14
#define		 MEXTI_LINE15			15
#endif
