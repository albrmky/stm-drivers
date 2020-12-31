/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 8 Aug 2020		*/
/* Version 	: V01				*/
/********************************/



#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Option 	RCC_HSE_CRYSTAL
			RCC_HSE_RC
			RCC_HSI
			RCC_PLL				*/
#define RCC_CLOCK_TYPE RCC_HSI


/* Note : Select value only if you have HSE as input clock source */
#if ( (RCC_CLOCK_TYPE == RCC_HSE_RC) || (RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL) )
/* Option RCC_HSE_DIVIDER_ENABLE
  	  	  RCC_HSE_DIVIDER_DISABLE  */
#define RCC_HSE_DIVIDE_2 RCC_HSE_DIVIDER_ENABLE
#endif

/* Note : Select value only if you have HSI as input clock source */
#if RCC_CLOCK_TYPE == RCC_HSI
/* -16 TO +15*/
#define RCC_HSI_TRIM 0
#endif

/* Note : Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL

/* Options: RCC_PLL_IN_HSI_DIV_2
			RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE		*/
#define RCC_PLL_INPUT   RCC_PLL_IN_HSI_DIV_2
/* 2 to 16 */
#define RCC_PLL_MUL_Val 12

#endif


// buses and important pripherals prescalers

/*
SYSCLK
SYSCLK_2
SYSCLK_4
SYSCLK_8
SYSCLK_16
SYSCLK_64
SYSCLK_128
SYSCLK_256
SYSCLK_512
 */

#define AHB_PRESCALER SYSCLK

/*
HCLK
HCLK_2
HCLK_4
HCLK_8
HCLK_16
 */
#define APB2_PRESCALER  HCLK
#define APB1_PRESCALER  HCLK

/*
PCLK2_2
PCLK2_4
PCLK2_6
PCLK2_8
 */
#define ADC_PRESCALER PCLK2_2

#endif
