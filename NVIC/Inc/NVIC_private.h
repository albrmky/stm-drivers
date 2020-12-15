/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 19 Aug 2020		*/
/* Version 	: V01				*/
/********************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS_1 0xE000E100
#define NVIC_BASE_ADDRESS_2 0xE000EF00

#define NVIC_ISER0   	*((u32*)0xE000E100 ) /* enable external interrupts from 0 to 31*/
#define NVIC_ISER1   	*((u32*)0xE000E104 ) /* enable external interrupts from 32 to 63*/

#define NVIC_ICER0   	*((u32*)0xE000E180 ) /* disable external interrupts from 0 to 31*/
#define NVIC_ICER1   	*((u32*)0xE000E184 ) /* disable external interrupts from 32 to 63*/
	
#define NVIC_ISPR0   	*((u32*)0xE000E200 )
#define NVIC_ISPR1   	*((u32*)0xE000E204 )
	
#define NVIC_ICPR0   	*((u32*)0xE000E280 )
#define NVIC_ICPR1   	*((u32*)0xE000E284 )

#define NVIC_IABR0	 	*((volatile u32*)0xE000E300 ) // read only, indicates which interrupt is active
#define NVIC_IABR1   	*((volatile u32*)0xE000E304 )

#define NVIC_IPR 		 ((volatile u8  *) 0xE000E400 )

// system control block
#define SCB_AIRCR		*((volatile u32 *) 0xE000ED0C )

#define NVIC_STIR		*((volatile u32 *) 0xE000EF00 )

//#define EXTI_IMR *((u32*)0x00 )
//#define EXTI_IMR *((u32*)0x04 )
//#define EXTI_IMR *((u32*)0x08 )
//#define EXTI_IMR *((u32*)0x0C )
//#define EXTI_IMR *((u32*)0x10 )
//#define EXTI_IMR *((u32*)0x14 )


#endif
