/*
 * main.c
 *
 *  Created on: Sep 16, 2020
 *      Author: noureldeen albrmky
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "TIMER1_interface.h"

void delay(u16 x);

#define debug *((volatile u32*)0xE0042004)

u32 value=0x10;
u8 flag=0;
u32 ARR_value = 10000;

void TIM1_CC_IRQHandler(void)
{
	//MGPIO_voidSetPinValue(GPIOA, PIN8, !(MGPIO_u8GetPinValue(GPIOA, PIN8)));

	MTIMER1_voidWriteCCRx(value, TIMER1_CCR1);
	if(flag == 0)
		value+=0x10;
	else
		value-=0x10;

	if(value>ARR_value)
		flag=1;
	if(value<=0x10)
		flag=0;
	MTIMER1_voidClearFlag(MTIMER1_FLAG_CC1);
}

int main(void)
{
	//RCC
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_TIMER1);
	RCC_voidEnableClock(RCC_PORTA);
	RCC_voidEnableClock(RCC_PORTB);
	RCC_voidEnableClock(RCC_AF);



	//GPIO
	MGPIO_voidSetPinDirection(GPIOA, PIN8 , OUTPUT_SPEED_50MHZ_AFPP);//CH1
	MGPIO_voidSetPinDirection(GPIOA, PIN9 , OUTPUT_SPEED_50MHZ_PP);//CH2
	MGPIO_voidSetPinDirection(GPIOA, PIN10, OUTPUT_SPEED_50MHZ_PP);//CH3
	MGPIO_voidSetPinDirection(GPIOA, PIN11, OUTPUT_SPEED_50MHZ_PP);//CH4

	MGPIO_voidSetPinDirection(GPIOB, PIN13, OUTPUT_SPEED_50MHZ_AFPP);//CH1N
	MGPIO_voidSetPinDirection(GPIOB, PIN14, OUTPUT_SPEED_50MHZ_PP);//CH2N
	MGPIO_voidSetPinDirection(GPIOB, PIN15, OUTPUT_SPEED_50MHZ_PP);//CH3N

	MGPIO_voidSetPinDirection(GPIOA, PIN12, OUTPUT_SPEED_10MHZ_PP);//ETR
	MGPIO_voidSetPinValue(GPIOA, PIN12, GPIO_LOW);
	MGPIO_voidSetPinDirection(GPIOB, PIN12, INPUT_PUPD);//BKIN

	//NVIC
	MNVIC_voidEnableInterrupt(NVIC_TIMER1_CC);


	//TIMER1

	SET_BIT(debug,10);// to hult the timer in debug mode
	MTIMER1_voidInit();
	MTIMER1_voidWriteARR(ARR_value);
	MTIMER1_voidWritePSC(0x5);
	MTIMER1_voidWriteCCRx(value, TIMER1_CCR1);
	// to update prescaler register value
	MTIMER1_voidGenerateEvent(MTIMER1_UPDATE_G);
	MTIMER1_voidClearFlag(MTIMER1_FLAG_UPDATE);


	MTIMER1_voidSetCCPinsEnable_POLARITY(MTIMER1_CC1_POLARITY, MTIMER1_CCx_ACTIVE_HIGH);
	MTIMER1_voidSetCCPinsEnable_POLARITY(MTIMER1_CC1N_POLARITY, MTIMER1_CCx_ACTIVE_LOW);
	MTIMER1_voidSetCCPinsEnable_POLARITY(MTIMER1_CC1_ENABLE, MTIMER1_CCx_PIN_ACTIVE);
	MTIMER1_voidSetCCPinsEnable_POLARITY(MTIMER1_CC1N_ENABLE, MTIMER1_CCx_PIN_ACTIVE);
	//MTIMER1_voidINTEnable(MTIMER1_INTERRUPT_CC1, MTIMER1_ENABLE);


	//MTIMER1_voidEnableMainOutput(MTIMER1_ENABLE);
	MTIMER1_voidEnableTimer(MTIMER1_ENABLE);

	MTIMER1_voidSetCCPinsEnable_POLARITY(MTIMER1_CC1_ENABLE, MTIMER1_CCx_PIN_NOT_ACTIVE);
	MTIMER1_voidSetCCPinsEnable_POLARITY(MTIMER1_CC1N_ENABLE, MTIMER1_CCx_PIN_NOT_ACTIVE);

	MTIMER1_voidGenerateEvent(MTIMER1_COM_G);
	MTIMER1_voidClearFlag(MTIMER1_FLAG_COM);


	u32 x=0;
	while(x<=0)
	{
		//MTIMER1_voidEnableTimer(MTIMER1_DISABLE);
		asm("NOP");
	}

	return 0;
}

void delay(u16 x)
{
	for(u16 i=0; i<x;i++)
	{
		for(u16 j=0; j<x;j++)
		{

		}
	}
}
