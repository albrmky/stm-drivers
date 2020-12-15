/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 19 Aug 2020		*/
/* Version 	: V01				*/
/********************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	
	if(Copy_u8IntNumber <32)
	{
		
		NVIC_ISER0 = (1 <<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <59)
	{
		
		NVIC_ISER1 = (1 <<(Copy_u8IntNumber-32));
	}
	else
	{
		
		/* return error*/
		
	}
		
}// end of enable fun



void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
	
	if(Copy_u8IntNumber <32)
	{
		NVIC_ICER0 = (1 <<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <59)
	{
		NVIC_ICER1 = (1 <<(Copy_u8IntNumber-32));
	}
	else
	{
		/* return error*/
	}
		
}// end of disable fun


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	
	if(Copy_u8IntNumber <32)
	{
		NVIC_ISPR0 = (1 <<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <59)
	{
		NVIC_ISPR1 = (1 <<(Copy_u8IntNumber-32));
	}
	else
	{
		/* return error*/
	}
		
}// end of enable pend

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	
	if(Copy_u8IntNumber <32)
	{
		
		NVIC_ICPR0 = (1 <<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <59)
	{
		
		NVIC_ICPR1 = (1 <<(Copy_u8IntNumber-32));
	}
	else
	{
		
		/* return error*/
		
	}
		
}// end of disable pend

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if(Copy_u8IntNumber <32)
	{
		
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <59)
	{
		
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber-32);
	}
	else
	{
		
		/* return error*/
		
	}
	
	return Local_u8Result;
		
}


void MNVIC_voidSetPriority(s8 Copy_s8IntId , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority, u32 Copy_u32BinaryPoint)
{
	/* 0x05FA0400 3 group & 1 sub priority*/
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<(Copy_u32BinaryPoint - 0x05FA0300) /256) ;
	/* core peripheral   */

	/* external peripheral  */
	if(Copy_s8IntId >= 0)
	{
		(NVIC_IPR[Copy_s8IntId]) = Local_u8Priority<<4 ; //because it is byte accessible
	}
	SCB_AIRCR = Copy_u32BinaryPoint;
	
}

void MNVIC_voidTriggerSoftwareInterrupt(s8 Copy_s8IRQ)
{
	NVIC_STIR = Copy_s8IRQ;
}
