/*
 * mai.c
 *
 *  Created on: Sep 2, 2020
 *      Author: noureldeen albrmky
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"


void ISR(void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN0, !(MGPIO_u8GetPinValue(GPIOA, PIN0)));
}

int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_PORTA);

	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_50MHZ_PP);

	MSTK_voidInit();
	//MSTK_voidSetIntervalPeriodic(700000, ISR);
	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN0, !(MGPIO_u8GetPinValue(GPIOA, PIN0)));
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPinValue(GPIOA, PIN0, !(MGPIO_u8GetPinValue(GPIOA, PIN0)));
		MSTK_voidSetBusyWait(1000000);
	}


	return 0;
}
