/*
 * USART_program.c
 *
 *  Created on: Sep 26, 2020
 *      Author: noureldeen albrmky
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

void MUSART1_voidInit(void)
{
#if USART1_DATA_BITS == BITS_8
	CLR_BIT(USART1 -> CR1 , M);
#elif USART1_DATA_BITS == BITS_9
	SET_BIT(USART1 -> CR1 , M);
#else
	#error ("Wrong Choice For USART1_DATA_BITS")
#endif

#if USART1_PARITY == ENABLE
	SET_BIT(USART1 -> CR1 , PCE);

	#if USART1_PARITY_TYPE == EVEN_PARITY
		CLR_BIT(USART1 -> CR1 , PS);
	#elif USART1_PARITY_TYPE == ODD_PARITY
		SET_BIT(USART1 -> CR1 , PS);
	#else
		#error ("Wrong Choice For USART1_PARITY_TYPE")
	#endif
#elif USART1_PARITY == DISABLE
	CLR_BIT(USART1 -> CR1 , PCE);
#else
	#error ("Wrong Choice For USART1_PARITY")
#endif


#if USART1_STOP_BITS == STOP_1_2
	INSERT_FIELD(USART1-> CR2,0x03FF,1,12);
#elif USART1_STOP_BITS == STOP_1
	INSERT_FIELD(USART1-> CR2,0x03FF,0,12);
#elif USART1_STOP_BITS == STOP_3_2
	INSERT_FIELD(USART1-> CR2,0x03FF,3,12);
#elif USART1_STOP_BITS == STOP_2
	INSERT_FIELD(USART1-> CR2,0x03FF,2,12);
#else
	#error ("Wrong Choice For USART1_STOP_BITS")
#endif

USART1 ->BRR = USART1_BAUD_RATE;


SET_BIT(USART1->CR1,RE);// ENABLE RX
SET_BIT(USART1->CR1,TE);// ENABLE TX
SET_BIT(USART1->CR1,UE);// ENABLE USART

//Set BaudRate


USART1 -> SR = 0;


}

u8 MUSART1_u8CheckDataAvailable()
{
	return GET_BIT(USART1 -> SR, 5) ;
}

u8 MUSART1_u8ReadData()
{
	return USART1 ->DR;
}

void MUSART1_voidTransmitChar(u8 Copy_u8Data)
{
	USART1 ->DR = Copy_u8Data;
	while(GET_BIT(USART1 -> SR,6) == 0);
}

void MUSART1_voidTransmitString(c8 arr[])
{
	u8 i=0;
	while(arr[i] != '\0')
	{
		USART1 ->DR = arr[i];
		// wait till transmission complete
		while(GET_BIT(USART1 -> SR,6) == 0);
		i++;
	}
}

void MUSART1_voidEnableINT(USART1_INT_FLAGS flag)
{
	SET_BIT(USART1->CR1,flag);
}

void MUSART1_voidDisableINT(USART1_INT_FLAGS flag)
{
	CLR_BIT(USART1->CR1,flag);
}
