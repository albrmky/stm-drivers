/*
 * main.c
 *
 *  Created on: Aug 12, 2020
 *      Author: noureldeen albrmky
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

void delay(u16 value);

int main(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_PORTA);
	RCC_voidEnableClock(RCC_PORTB);
	RCC_voidEnableClock(RCC_PORTC);

	int delay_v=1000;

	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);
	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA, PIN1,GPIO_HIGH);
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
