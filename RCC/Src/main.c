/*
 * main.c
 *
 *  Created on: Aug 11, 2020
 *      Author: noureldeen albrmky
 */

#include "RCC_interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define GPIOA_CRL	*((u32*)(0x40010800 ))
#define GPIOA_IDR	*((u32*)(0x40010808 ))

#define GPIOA_ODR	*((u32*)(0x4001080C ))
#define GPIOx_BSRR	*((u32*)(0x40010810 ))
#define GPIOx_BRR	*((u32*)(0x40010814 ))
int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_PORTA);
	GPIOA_CRL =0x00000041;
	int delay=2000;
	unsigned int x=0;
	unsigned int y=0;
	while(1)
	{

			GPIOx_BSRR=0x00000001;
			for(int x=0;x<delay;x++)
			{
				for(int x=0;x<delay;x++)
				{

				}
			}
			GPIOx_BRR =0x00000001;
			for(int x=0;x<delay;x++)
			{
				for(int x=0;x<delay;x++)
				{

				}
			}

	}

	return 0;
}
