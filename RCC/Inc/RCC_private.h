/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 8 Aug 2020		*/
/* Version 	: V01				*/
/********************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definition*/
#define RCC_CR 			*((u32*)(0x40021000))
#define RCC_CFGR 		*((u32*)(0x40021004))
#define RCC_CIR 		*((u32*)(0x40021008))
#define RCC_APB2RSTR 	*((u32*)(0x4002100C))
#define RCC_APB1RSTR 	*((u32*)(0x40021010))
#define RCC_AHBENR 		*((u32*)(0x40021014))
#define RCC_APB2ENR	 	*((u32*)(0x40021018))
#define RCC_APB1ENR 	*((u32*)(0x4002101C))
#define RCC_BDCR 		*((u32*)(0x40021020))
#define RCC_CSR 		*((u32*)(0x40021024))

/* clock Types*/
#define RCC_HSE_CRYSTAL 	0
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_PLL				3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE_DIV_2	1
#define RCC_PLL_IN_HSE			2

#define RCC_HSE_DIVIDER_ENABLE	1
#define RCC_HSE_DIVIDER_DISABLE	0

// for AHB bus
#define  SYSCLK         0000
#define  SYSCLK_2       1000
#define  SYSCLK_4       1001
#define  SYSCLK_8       1010
#define  SYSCLK_16      1011
#define  SYSCLK_64      1100
#define  SYSCLK_128     1101
#define  SYSCLK_256     1110
#define  SYSCLK_512     1111


// for APB1 and APB2
#define  HCLK      000
#define  HCLK_2    100
#define  HCLK_4    101
#define  HCLK_8    110
#define  HCLK_16   111

// for ADC
#define  PCLK2_2    00
#define  PCLK2_4    01
#define  PCLK2_6    10
#define  PCLK2_8    11

#endif
