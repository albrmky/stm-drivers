/*
 * SPI1_interface.h
 *
 *  Created on: Sep 28, 2020
 *      Author: noureldeen albrmky
 */

#ifndef SPI1_INTERFACE_H_
#define SPI1_INTERFACE_H_
/*
 * NSS 	A4 (A15)
 * SCK 	A5 (B3)
 * MISO	A6 (B4)
 * MOSI	A7 (B5)
 */



typedef enum {
	SPI1_ERRORS=5,
	SPI1_RX_BUFFER_FULL,
	SPI1_TX_BUFFER_EMPTY
}SPI1_INTERRUPT;

typedef enum{SPI1_DISABLE,SPI1_ENABLE}		SPI1_BASIC_STATE;
typedef enum{SPI1_Rx,SPI1_Tx}	SPI1_BI_DIR;
typedef enum{
	SPI1_DATA_RECEIVED=0,
	SPI1_TRANSMISSION_COMPLETE=1,
	SPI1_UNDER_RUN=3,
	SPI1_MODE_FAULT_RUN=5,
	SPI1_OVER_RUN=6,
	SPI1_BUSY=7
}SPI1_STATUS_FLAGS;


void MSPI1_voidInit(void);
void MSPI1_voidEnableSPI(void);
void MSPI1_voidDisableSPI(void);

u8 MSPI1_u8ReadFlag(SPI1_STATUS_FLAGS flag);
void MSPI1_voidSetSSI_VALUE(u8 x);


void MSPI1_voidEnableINT(SPI1_INTERRUPT x	);
void MSPI1_voidDisableINT(SPI1_INTERRUPT x	);

void MSPI1_voidWriteData_8(u8 Data);
void MSPI1_voidWriteData_16(u16 Data);
u8 	 MSPI1_u8ReadData(void);
u16  MSPI1_u16ReadData(void);

void MSPI1_u8SetBIDirection(SPI1_BI_DIR x);




#endif /* SPI1_INTERFACE_H_ */
