/*
 * USART_interface.h
 *
 *  Created on: Sep 26, 2020
 *      Author: noureldeen albrmky
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_
/*
 *   Tx	PA9(PB6)	////////////////////////////-------------->>>>>>>>>>>>>>>>>>>>>>
 *   Rx	PA10(PB7)	////////////////////////////-------------->>>>>>>>>>>>>>>>>>>>>>
*/

typedef enum { 	USART1_RDR_FULL =5,
				USART1_TRANSMISSION_COMPLETE ,
				USART1_TDR_EMPTY
}USART1_INT_FLAGS;



void MUSART1_voidInit(void);
void MUSART1_voidEnableINT(USART1_INT_FLAGS flag);
void MUSART1_voidDisableINT(USART1_INT_FLAGS flag);


u8 	 MUSART1_u8CheckDataAvailable();
u8 	 MUSART1_u8ReadData();
void MUSART1_voidTransmitString(c8 arr[]);
void MUSART1_voidTransmitChar(u8 Copy_u8Data);





#endif /* USART_INTERFACE_H_ */
