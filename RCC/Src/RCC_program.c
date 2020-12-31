/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 8 Aug 2020		*/
/* Version 	: V01				*/
/********************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void)
{
	
	#if (RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL)

		#if (RCC_HSE_DIVIDE_2==RCC_HSE_DIVIDER_ENABLE)
			SET_BIT(RCC_CFGR,17); //PLLXTPRE
		#elif (RCC_HSE_DIVIDE_2==RCC_HSE_DIVIDER_DISABLE)
			CLR_BIT(RCC_CFGR,17); //PLLXTPRE
		#else
			#error("wrong choice for RCC_HSE_DIVIDE_2")
		#endif

		CLR_BIT(RCC_CR,18) ;//HSEBYP
		SET_BIT(RCC_CR,16) ;//HSEON enable

		INSERT_FIELD(RCC_CFGR,0x00000003,1,0);
		while(!GET_BIT(RCC_CR,17));//HSERDY

	#elif (RCC_CLOCK_TYPE ==RCC_HSE_RC)

		#if (RCC_HSE_DIVIDE_2==RCC_HSE_DIVIDER_ENABLE)
			SET_BIT(RCC_CFGR,17); //PLLXTPRE
		#elif (RCC_HSE_DIVIDE_2==RCC_HSE_DIVIDER_DISABLE)
			CLR_BIT(RCC_CFGR,17); //PLLXTPRE
		#else
			#error("wrong choice for RCC_HSE_DIVIDE_2")
		#endif

		SET_BIT(RCC_CR,18) ;//HSEBYP
		SET_BIT(RCC_CR,16) ;//HSEON

		while(!GET_BIT(RCC_CR,17));//HSERDY
		
		INSERT_FIELD(RCC_CFGR,0x00000003,1,0);

	#elif (RCC_CLOCK_TYPE ==RCC_HSI)

		#if (RCC_CLOCK_TYPE>=-16 && RCC_CLOCK_TYPE <=15)
			//INSERT_FIELD(RCC_CR,0x000000F8,RCC_HSI_TRIM+16,3);
		#else
			#error("You chose wrong Trim value for HSI");
		#endif

		SET_BIT(RCC_CR,0);/* Enable HSI */

		while(!GET_BIT(RCC_CR,1));//HSIRDY
		
		INSERT_FIELD(RCC_CFGR,0x00000003,0,0);

	#elif (RCC_CLOCK_TYPE ==RCC_PLL)

		#if((RCC_PLL_MUL_Val<=16) && (RCC_PLL_MUL_Val>=2) )
			INSERT_FIELD(RCC_CFGR, 0x003C0000, (RCC_PLL_MUL_Val-2), 18);
		#else
			#error("You chose wrong PLL Multiplier");
		#endif


		#if (RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2)
			CLR_BIT(RCC_CFGR,16); // PLLSRC bit
		#elif (RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2)
			SET_BIT(RCC_CFGR,17) //PLLXTPRE
			SET_BIT(RCC_CFGR,16); // PLLSRC bit
		#elif (RCC_PLL_INPUT == RCC_PLL_IN_HSE)
			CLR_BIT(RCC_CFGR,17) //PLLXTPRE not divided
			SET_BIT(RCC_CFGR,16); // PLLSRC bit
		#else
			#error ("You chose wrong PLL Source");
		#endif

		SET_BIT(RCC_CR,24);/* Enable PLL ->PLLON BIT */
		INSERT_FIELD(RCC_CFGR,0x00000003,2,0);

		while(!GET_BIT(RCC_CR,25));//PLLRDY

	#else
		#error("You chose wrong clock type")
	
	#endif
	
	INSERT_FIELD(RCC_CFGR,0x000000F0,AHB_PRESCALER,4);
	INSERT_FIELD(RCC_CFGR,0x00000700,APB1_PRESCALER,8);
	INSERT_FIELD(RCC_CFGR,0x00003800,APB2_PRESCALER,11);
	INSERT_FIELD(RCC_CFGR,0x0000C000,APB2_PRESCALER,14);



	
}

void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR ,Copy_u8PerId); break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerId); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId); break;
			//default   : /* return error*/       		   break;
		}
		
	}
	
	else
	{	
		//#error("enable clock for unspecified prephiral");
	}
	
	
}


void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR ,Copy_u8PerId); break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId); break;
			//default   : /* return error*/       		   break;
		}
		
	}
	
	else
	{	
		//#error("disable clock for unspecified prephiral");
	}
	
	
}
