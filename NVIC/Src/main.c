/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: noureldeen albrmky
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"

#define reg *((volatile u32*)0xE000ED14) // for software interrupt
void delay(u16 value);

void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
	delay(500);
//	MNVIC_voidSetPendingFlag(NVIC_EXTI_LINE1);
	MNVIC_voidClearPendingFlag(NVIC_EXTI_LINE0);
	MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);

}
void EXTI1_IRQHandler(void)
{
	delay(1000);
	MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);


	delay(1000);

	MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW);
	delay(1000);
}

int main(void)
{
	// initialize clock
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_PORTA);
	RCC_voidEnableClock(RCC_PORTB);
	RCC_voidEnableClock(RCC_PORTC);

	//initialize pin
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_50MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_50MHZ_PP);

	//initialize interrupt
	MNVIC_voidSetPriority(NVIC_EXTI_LINE0,0, 1, GROUP2_sub2);
	MNVIC_voidSetPriority(NVIC_EXTI_LINE1,0, 1, GROUP2_sub2);

	MNVIC_voidEnableInterrupt(NVIC_EXTI_LINE0);
	MNVIC_voidEnableInterrupt(NVIC_EXTI_LINE1);

	reg = 0x00000002; // for software interrupt
	while(1)
	{
		//MNVIC_voidSetPendingFlag(NVIC_EXTI_LINE0);
		//for (int x=0; x<12 ; x++)
		MNVIC_voidTriggerSoftwareInterrupt(6);
		delay(1000);
	}


	return 0;
}

void delay(u16 value)
{
	for(int x=0; x<value;x++)
	{
		for(int y=0; y<value;y++)
		{
			asm("nop");
		}
	}
}
