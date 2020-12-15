/*
 * SPI1_private.h
 *
 *  Created on: Sep 28, 2020
 *      Author: noureldeen albrmky
 */

#ifndef SPI1_PRIVATE_H_
#define SPI1_PRIVATE_H_


typedef struct {
	volatile u32 CR1        ;
	volatile u32 CR2        ;
	volatile u32 SR         ;
	volatile u32 DR         ;
	volatile u32 CRCPR       ;
	volatile u32 RXCRCR      ;
	volatile u32 TXCRCR      ;
	volatile u32 I2SCFGR     ;
	volatile u32 I2SPR      ;

}SPI1_t;


#define SPI1    ((volatile SPI1_t * )0x40013000)

//SPI1_CR1
#define 	CPHA			            0
#define 	CPOL			            1
#define 	MSTR			            2
#define 	SPE 			            6
#define 	LSB_FIRST		            7
#define 	SSI 			            8
#define 	SSM 			            9
#define 	RXONLY			            10
#define 	DFF 			            11
#define 	CRC_NEXT		            12
#define 	CRC_EN  		            13
#define 	BIDIOE			            14
#define 	BIDIMODE		            15

//SPI1_CR2
#define 	RXDMAEN			            0
#define 	TXDMAEN			            1
#define 	SSOE			            2
#define 	ERRIE			            5
#define 	RXNEIE			            6
#define 	TXEIE			            7

//SPI1_SR
#define 	RXNE			            0
#define 	TXE				            1
#define 	CHSIDE			            2
#define 	UDR				            3
#define 	CRC_ERR			            4
#define 	MODF			            5
#define 	OVR				            6
#define 	BSY				            7
/////////////////////////////////////////////////////////

//PERIPHERALS_AS_
#define		SPI 			            0
#define 	I2S				            1

//SPI_WORK_IN
#define 	SLAVE_MODE		            0
#define 	MASTER_MODE		            1

//SPI_CONFIGURATION_MODE.
#define 	UNIDIRECTIONAL_FULL_DUPLEX		0
#define 	UNIDIRECTIONAL_RECEIVE_ONLY		1
#define 	BIDIRECTIONAL_RECEIVE_ONLY		0
#define 	BIDIRECTIONAL_TRANSMIT_ONLY		1

//BIDIRECTIONAL_MODE
#define 	RX_MODE			            0
#define 	TX_MODE			            1

//DATA_FRAME_FORMAT
#define 	DATA_FRAME_8	            0
#define 	DATA_FRAME_16	            1


//FIRST_BIT_OUT
#define 	MSB				            0
#define 	LSB				            1

//SPI_BAUD_RATE
#define 	CLK_2			            000
#define 	CLK_4			            001
#define 	CLK_8			            010
#define 	CLK_16			            011
#define 	CLK_32			            100
#define 	CLK_64			            101
#define 	CLK_128			            110
#define 	CLK_256			            111

//CLOCK_POLARITY
#define 	IDEAL_LOW		            0
#define 	IDEAL_HIGH		            1

//CLOCK_PHASE
#define 	CAPTURE_WITH_LEADING_EDGE	0
#define 	CAPTURE_WITH_TRAILING_EDGE	1

//NSS_CONTROL
#define 	HARDWARE_EXTERNALLY		            0
#define 	SOFTWARE_INTERNALLY		            1

#endif /* SPI1_PRIVATE_H_ */
