/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 2 Sep 2020		*/
/* Version 	: V01				*/
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"


void(*callback) (void);
u8 flag=0;

void MSTK_voidInit(void)
{
	#if 	(CLOCK_SOURCE == AHB)
		SET_BIT(STK_CTRL,2);
	#elif 	(CLOCK_SOURCE == AHB_8)
		CLR_BIT(STK_CTRL,2);
	#else
		#error ("wrong SYSTICK source ")
	#endif

	#if     (FLAG_INT == STK_ENABLE)
		SET_BIT(STK_CTRL,1);
	#elif   (FLAG_INT == STK_DISABLE)
		CLR_BIT(STK_CTRL,1);
	#else
		#error ("wrong STATE for FLAG_INT ")
	#endif

	#if     (SYS_TICK == STK_ENABLE)
		SET_BIT(STK_CTRL,0);
	#elif   (SYS_TICK == STK_DISABLE)
		CLR_BIT(STK_CTRL,0);
	#else
		#error ("wrong STATE for SYS_TICK ")
	#endif
		MSTK_voidStopInterval();
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK_LOAD = Copy_u32Ticks;
	STK_VAL=0;

	SET_BIT(STK_CTRL,0); //enable systick
	//CLR_BIT(STK_CTRL,16);
	flag=0;
	/*enable systick*/
	while(GET_BIT(STK_CTRL,16)==0);

}

void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks, void(*ptr)(void) )
{
	callback = ptr;
	STK_VAL=0;
	STK_LOAD = Copy_u32Ticks;
	flag=0;
	SET_BIT(STK_CTRL,0); //enable systick

}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void(*ptr)(void) )
{
	callback = ptr;
	STK_LOAD = Copy_u32Ticks-1;
	flag=1;
	SET_BIT(STK_CTRL,0); //enable systick
}

void MSTK_voidStopInterval(void)
{
	CLR_BIT(STK_CTRL,0); //Disable systick
}
u32  MSTK_u32GetElapsedTime(void)
{
	return (STK_LOAD - STK_VAL);
}
u32  MSTK_u32GetRemainingTime(void)
{
	return STK_VAL;
}

void SysTick_Handler(void)
{
	callback();
	if(flag==0) CLR_BIT(STK_CTRL,0); //Disable systick
}
