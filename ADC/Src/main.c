/*
 * main.c
 *
 *  Created on: Dec 29, 2020
 *      Author: noureldeen albrmky
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "ADC_interface.h"
#include "USART_interface.h"


void ADC1_2_IRQHandler(void)
{
	u16 value = MADC1_u16GetregularData();
	MUSART1_voidTransmitChar((u8)(value/16));
	MADC1_voidClearStatus(ADC1_EOC);

}


int main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_PORTA);
	RCC_voidEnableClock(RCC_ADC1);
	RCC_voidEnableClock(RCC_USART1);

	MGPIO_voidSetPinDirection(GPIOA, PIN0, INPUT_ANALOG);
	MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_AFPP);//TX
	MGPIO_voidSetPinDirection(GPIOA, PIN10,INPUT_FLOAT);//RX


	MUSART1_voidInit();
	MNVIC_voidEnableInterrupt(NVIC_ADC1_2);

	MADC1_voidINTMasks(ADC1_EOCIE, ADC1_ENABLE);
	MADC1_voidInit();
	MADC1_voidSetRegularSqeuenceLength(1);
	MADC1_voidSetRegularChannelSequences(1 , 0);
	MADC1_voidStart_Enable();

	for(int i =0 ; i<10;i++);

	MADC1_voidStartCalibration();


	while(1)
	{

		MADC1_voidStart_Enable();

		for(int i =0 ; i<1000;i++);


	}
	return 0;
}
