/*
 * USART_private.h
 *
 *  Created on: Sep 26, 2020
 *      Author: noureldeen albrmky
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

typedef struct
{
	volatile u32 SR      ;
	volatile u32 DR      ;
	volatile u32 BRR     ;
	volatile u32 CR1     ;
	volatile u32 CR2     ;
	volatile u32 CR3     ;
	volatile u32 GTPR    ;
}USART_t;

#define USART1 ((volatile USART_t*)0x40013800)

//USART_SR  BITS
#define 	PE			0
#define 	FE			1
#define 	NE			2
#define 	ORE			3
#define 	IDLE		4
#define 	RXNE		5
#define 	TC			6
#define 	TXE			7
#define 	LBD			8
#define 	CTS			9


// UART_CR1 BITS
#define 	SBK			0
#define 	RWU			1
#define 	RE			2
#define 	TE			3
#define 	IDLEIE		4
#define 	RXNEIE		5
#define 	TCIE		6
#define 	TXEIE		7
#define 	PEIE		8
#define 	PS			9
#define 	PCE			10
#define 	WAKE		11
#define 	M			12
#define 	UE			13



#define ASYNC	0


#define BITS_8			0
#define BITS_9			1
#define ENABLE			2
#define DISABLE			3
#define EVEN_PARITY		4
#define ODD_PARITY		5
#define STOP_1_2        6
#define STOP_1          7
#define STOP_3_2        8
#define STOP_2          9

#define BR_9600			0x341

#endif /* USART_PRIVATE_H_ */
