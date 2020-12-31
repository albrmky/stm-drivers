/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 8 Aug 2020		*/
/* Version 	: V01				*/
/********************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);


#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

#define RCC_PORTA 2,2
#define RCC_PORTB 2,3
#define RCC_PORTC 2,4

#define RCC_TIMER1 2,11

#define RCC_AF	2,0

#define RCC_USART1 2,14

#define RCC_SPI1 	2,12
#define RCC_SPI2 	1,14

#define RCC_ADC1    2,9

#endif
