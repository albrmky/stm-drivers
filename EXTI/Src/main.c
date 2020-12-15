/*
 * main.c
 *
 *  Created on: Sep 3, 2020
 *      Author: noureldeen albrmky
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"


void ISR0 (void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN3, !(MGPIO_u8GetPinValue(GPIOA, PIN3)));
	MSTK_voidSetBusyWait(100);
}

void ISR1 (void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN4, !(MGPIO_u8GetPinValue(GPIOA, PIN4)));
	MSTK_voidSetBusyWait(100);
}
int main(void)
{
	//RCC
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_PORTA);

	//GPIO

	//MGPIO_voidSetPinDirection(GPIOA, PIN0, INPUT_PUPD);
	//MGPIO_voidSetPinDirection(GPIOA, PIN1, INPUT_PUPD);
	MGPIO_voidSetPinDirection(GPIOA, PIN8, INPUT_PUPD);
	//MGPIO_voidSetPinDirection(GPIOA, PIN9, INPUT_PUPD);

	MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_HIGH);
	//MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);

	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);


	//EXTI0
	MEXTI5_9_voidSetCallBack(ISR0);
	//MEXTI0_voidSetCallBack(ISR0);
	//MEXTI1_voidSetCallBack(ISR1);
	MEXTI_voidSetSignalLatch(MEXTI_LINE8, EXTI_FALLING_EDGE);
	//MEXTI_voidSetSignalLatch(MEXTI_LINE1, EXTI_FALLING_EDGE);
	MEXTI_voidInit();

	//NVIC
	MNVIC_voidEnableInterrupt(NVIC_EXTI_LINE5_9);
	//MNVIC_voidEnableInterrupt(NVIC_EXTI_LINE8);

	//STK
	MSTK_voidInit();

	while(1)
	{

	}



	return 0;
}
