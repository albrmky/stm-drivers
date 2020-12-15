/*
 * SPI2_interface.h
 *
 *  Created on: Sep 29, 2020
 *      Author: noureldeen albrmky
 */

#ifndef SPI2_INTERFACE_H_
#define SPI2_INTERFACE_H_
/*
 * NSS 	B12
 * SCK 	B13
 * MISO	B14
 * MOSI	B15
 */



typedef enum {
	SPI2_ERRORS=5,
	SPI2_RX_BUFFER_FULL,
	SPI2_TX_BUFFER_EMPTY
}SPI2_INTERRUPT;

typedef enum{SPI2_DISABLE,SPI2_ENABLE}		SPI2_BASIC_STATE;
typedef enum{
	SPI2_DATA_RECEIVED=0,
	SPI2_TRANSMISSION_COMPLETE=1,
	SPI2_UNDER_RUN=3,
	SPI2_MODE_FAULT_RUN=5,
	SPI2_OVER_RUN=6,
	SPI2_BUSY=7
}SPI2_STATUS_FLAGS;


void MSPI2_voidInit(void);
void MSPI2_voidEnableSPI(void);
void MSPI2_voidDisableSPI(void);


u8 MSPI2_u8ReadFlag(SPI2_STATUS_FLAGS flag);
void MSPI2_voidSetSSI(u8 x);


void MSPI2_voidEnableINT(SPI2_INTERRUPT x	);
void MSPI2_voidDisableINT(SPI2_INTERRUPT x	);

void MSPI2_voidWriteData_8(u8 Data);
void MSPI2_voidWriteData_16(u16 Data);
u8 	 MSPI2_u8ReadData(void);
u16  MSPI2_u16ReadData(void);





#endif /* SPI2_INTERFACE_H_ */
