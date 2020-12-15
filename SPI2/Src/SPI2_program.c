/*
 * SPI2_program.c
 *
 *  Created on: Sep 29, 2020
 *      Author: noureldeen albrmky
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SPI2_private.h"
#include "SPI2_config.h"
#include "SPI2_interface.h"



#define CONCBIT(D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13)	CONCBIT_HELPER(D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13)
#define CONCBIT_HELPER(D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13) 0b##D13##D12##D11##D10##D9##D8##D7##D6##D5##D4##D3##D2##D1


void MSPI2_voidInit(void)
{

#if	PERIPHERALS_AS_ == SPI
	CLR_BIT(SPI2->I2SPR,11);
#elif PERIPHERALS_AS_ == I2S
	SET_BIT(SPI2->I2SPR,11);
#else
	#error	("Wrong Choice AT PERIPHERALS_AS_ ");

#endif

SPI2->CR1 =  CONCBIT(		CLOCK_PHASE,//CPHA
							CLOCK_POLARITY,//CPOL
							SPI_WORK_IN,//MSTR
							SPI_BAUD_RATE,//BR
							0,//SPE
							FIRST_BIT_OUT,//LSB FIRST
							0,//SSI
							NSS_CONTROL,//SSM
							0,//RX ONLY
							DATA_FRAME_FORMAT,//DFF
							00,//CRC
							00,//BIDIMODE &BIDIOE
							);

#if (SPI_WORK_IN == MASTER_MODE)

	#if NSS_CONTROL == SOFTWARE_INTERNALLY
		SET_BIT(SPI2->CR1,SSI);
	#elif	NSS_CONTROL == HARDWARE_EXTERNALLY
		SET_BIT(SPI2->CR2,SSOE);
	#endif

#elif (SPI_WORK_IN == SLAVE_MODE)

	#if NSS_CONTROL == SOFTWARE_INTERNALLY
		CLR_BIT(SPI2->CR1,SSI);
	#elif	NSS_CONTROL == HARDWARE_EXTERNALLY
		CLR_BIT(SPI2->CR2,SSOE);
	#endif
#endif

#if SPI_CONFIGURATION_MODE == UNIDIRECTIONAL_FULL_DUPLEX
	CLR_BIT(SPI2->CR1,BIDIMODE);
	CLR_BIT(SPI2->CR1,RXONLY);
#elif SPI_CONFIGURATION_MODE == UNIDIRECTIONAL_RECEIVE_ONLY
	CLR_BIT(SPI2->CR1,BIDIMODE);
	SET_BIT(SPI2->CR1,RXONLY);
#elif SPI_CONFIGURATION_MODE == BIDIRECTIONAL_RECEIVE_ONLY
	SET_BIT(SPI2->CR1,BIDIMODE);
	CLR_BIT(SPI2->CR1,BIDION);
#elif SPI_CONFIGURATION_MODE == BIDIRECTIONAL_TRANSMIT_ONLY
	SET_BIT(SPI2->CR1,BIDIMODE);
	SET_BIT(SPI2->CR1,BIDION);
#else
	#error ("Wrong choice for SPI_CONFIGURATION_MODE")

#endif

}

void MSPI2_voidEnableSPI(void)
{
	SET_BIT(SPI2->CR1,SPE);
}

void MSPI2_voidDisableSPI(void)
{
	CLR_BIT(SPI2->CR1,SPE);
}

u8 MSPI2_u8ReadFlag(SPI2_STATUS_FLAGS flag)
{
	return GET_BIT(SPI2->SR,flag);
}

void MSPI2_voidSetSSI(u8 x)
{
	INSERT_BIT(SPI2->CR1,SSI,x);
}

void MSPI2_voidEnableINT(SPI2_INTERRUPT x	)
{
	SET_BIT(SPI2 -> CR2 , x);
}

void MSPI2_voidDisableINT(SPI2_INTERRUPT x	)
{
	CLR_BIT(SPI2 -> CR2 , x);
}

void MSPI2_voidWriteData_8(u8 Data)
{
	while(GET_BIT(SPI2->SR,TXE)==0);
	SPI2 ->DR = Data;
}

void MSPI2_voidWriteData_16(u16 Data)
{
	while(GET_BIT(SPI2->SR,TXE)==0);
	SPI2 ->DR = Data;
}

u8 MSPI2_u8ReadData(void)
{
	while(GET_BIT(SPI2->SR,RXNE)==0);
	return (0xFF & SPI2->DR);
}

u16 MSPI2_u16ReadData(void)
{
	while(GET_BIT(SPI2->SR,RXNE)==0);
	return (0xFFFF & SPI2->DR);
}

