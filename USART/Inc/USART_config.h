/*
 * USART_config.h
 *
 *  Created on: Sep 26, 2020
 *      Author: noureldeen albrmky
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

//ASYNC
#define USART1_MODE				ASYNC

//BITS_8	//BITS_9
#define USART1_DATA_BITS		BITS_8

//ENABLE	//DISABLE
#define USART1_PARITY			DISABLE

//EVEN_PARITY	//ODD_PARITY
#define USART1_PARITY_TYPE		EVEN_PARITY

//STOP_1_2	//STOP_1
//STOP_3_2	//STOP_2
#define USART1_STOP_BITS		STOP_1

// assuming 8MHz SYSCLOCK
#define USART1_BAUD_RATE		BR_9600




#endif /* USART_CONFIG_H_ */
