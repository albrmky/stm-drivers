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



#endif
