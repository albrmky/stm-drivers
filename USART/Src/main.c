/*
 * main.c
 *
 *  Created on: Sep 26, 2020
 *      Author: noureldeen albrmky
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "USART_interface.h"
#include "STK_interface.h"

u8 x=0;

void USART1_IRQHandler(void)
{
	x= MUSART1_u8ReadData();
}

void fun(void)
{

	//MGPIO_voidSetPinValue(GPIOA, PIN8, !(MGPIO_u8GetPinValue(GPIOA, PIN8)));
	MUSART1_voidTransmitString("nour");
}


int main(void)
{

	//RCC
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_PORTA);
	RCC_voidEnableClock(RCC_USART1);

	//GPIO
	MGPIO_voidSetPinDirection(GPIOA, PIN8, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_AFPP);
	MGPIO_voidSetPinDirection(GPIOA, PIN10,INPUT_FLOAT);
	//NVIC
	MNVIC_voidEnableInterrupt(NVIC_USART1);

	//STK

	MSTK_voidSetIntervalPeriodic(1000000, fun);
	MSTK_voidInit();


	//USART
	MUSART1_voidEnableINT(USART1_RDR_FULL);
	MUSART1_voidInit();



	while(1)
	{
		if(x=='o')
			MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_HIGH);
		else
			MGPIO_voidSetPinValue(GPIOA, PIN8, GPIO_LOW);





		//(1000000);


	}

	return 0;
}
