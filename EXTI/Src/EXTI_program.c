/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 3 Sep 2020		*/
/* Version 	: V01				*/
/********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#define NULL		(void * )0

void (* EXTI0_CallBack) (void) = NULL ;
void (* EXTI1_CallBack) (void) = NULL ;
void (* EXTI2_CallBack) (void) = NULL ;
void (* EXTI3_CallBack) (void) = NULL ;
void (* EXTI4_CallBack) (void) = NULL ;
void (* EXTI5_9_CallBack) (void) = NULL ;
void (* EXTI10_15_CallBack) (void) = NULL ;

#define  EXTI_STATE CONCBIT(	EXTI_LINE0 ,\
								EXTI_LINE1 ,\
								EXTI_LINE2 ,\
								EXTI_LINE3 ,\
								EXTI_LINE4 ,\
								EXTI_LINE5 ,\
								EXTI_LINE6 ,\
								EXTI_LINE7 ,\
								EXTI_LINE8 ,\
								EXTI_LINE9 ,\
								EXTI_LINE10,\
								EXTI_LINE11,\
								EXTI_LINE12,\
								EXTI_LINE13,\
								EXTI_LINE14,\
								EXTI_LINE15      )


#define CONCBIT(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)	CONCBIT_HELPER(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define CONCBIT_HELPER(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) 0b##p##o##n##m##l##k##j##i##h##g##f##e##d##c##b##a


void MEXTI_voidInit(void)
{

	EXTI -> IMR = EXTI_STATE;
	EXTI -> EMR = EXTI_STATE;
	
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode)
{	
	switch(Copy_u8EXTISenseMode)
	{
		case	EXTI_RISING_EDGE	:	SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);
										CLR_BIT(EXTI -> FTSR , Copy_u8EXTILine);	break;

		case	EXTI_FALLING_EDGE	:	SET_BIT(EXTI -> FTSR , Copy_u8EXTILine);
										CLR_BIT(EXTI -> RTSR , Copy_u8EXTILine);	break;

		case	EXTI_ON_CHANGE		:	SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);
										SET_BIT(EXTI -> FTSR , Copy_u8EXTILine);	break;
	}
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI -> IMR , Copy_u8EXTILine);
	
}
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> SWIER ,  Copy_u8EXTILine);
}


////////////////////////////////////////////////////////////////////////////////////////
void MEXTI0_voidSetCallBack(void (*ptr) (void))
{
		EXTI0_CallBack = ptr ;
}

void MEXTI1_voidSetCallBack(void (*ptr) (void))
{
		EXTI1_CallBack = ptr ;
}

void MEXTI2_voidSetCallBack(void (*ptr) (void))
{
		EXTI2_CallBack = ptr ;
}

void MEXTI3_voidSetCallBack(void (*ptr) (void))
{
		EXTI3_CallBack = ptr ;
}

void MEXTI4_voidSetCallBack(void (*ptr) (void))
{
		EXTI4_CallBack = ptr ;
}

void MEXTI5_9_voidSetCallBack(void (*ptr) (void))
{
		EXTI5_9_CallBack = ptr ;
}

void MEXTI10_15_voidSetCallBack(void (*ptr) (void))
{
		EXTI10_15_CallBack = ptr ;
}

/////////////////////////////////////////////////////////////////////////////////////
void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();

	SET_BIT(EXTI -> PR , 0);//clear pending bit
}

void	EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();

	SET_BIT(EXTI -> PR , 1);//clear pending bit
}

void	EXTI2_IRQHandler(void)
{
	EXTI2_CallBack();

	SET_BIT(EXTI -> PR , 2);//clear pending bit
}

void	EXTI3_IRQHandler(void)
{
	EXTI3_CallBack();

	SET_BIT(EXTI -> PR , 3);//clear pending bit
}

void	EXTI4_IRQHandler(void)
{
	EXTI4_CallBack();

	SET_BIT(EXTI -> PR , 4);//clear pending bit
}


void 	EXTI9_5_IRQHandler(void)
{
	EXTI5_9_CallBack();
	INSERT_FIELD(EXTI -> PR ,0x000003E0,0b11111,5);
}

void 	EXTI15_10_IRQHandler(void)
{
	EXTI10_15_CallBack();
	INSERT_FIELD(EXTI -> PR ,0x0000FC00,0b11111,10);
}
