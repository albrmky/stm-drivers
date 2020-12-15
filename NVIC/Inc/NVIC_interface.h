/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 19 Aug 2020		*/
/* Version 	: V01				*/
/********************************/



#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);

u8   MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);

void MNVIC_voidSetPriority( s8 Copy_s8IntId 		,
							u8 Copy_u8GroupPriority ,
							u8 Copy_u8SubPriority	,
							u32 Copy_u32BinaryPoint);

void MNVIC_voidTriggerSoftwareInterrupt(s8 Copy_s8IRQ);

#define GROUP4_sub0 0x05FA0300// 4 bits for Group (IPR)=> group
#define GROUP3_sub1 0x05FA0400// 3 bits for Group & 1bit for sub
#define GROUP2_sub2 0x05FA0400// 2 bits for Group & 2bit for sub
#define GROUP1_sub3 0x05FA0600// 1 bits for Group & 3bit for sub
#define GROUP0_sub4 0x05FA0700// 0 bits for Group & 4bit for sub

// bit number of interrupts
#define NVIC_EXTI_LINE0 		           6
#define NVIC_EXTI_LINE1 		           7
#define NVIC_EXTI_LINE2 		           8
#define NVIC_EXTI_LINE3 		           9
#define NVIC_EXTI_LINE4 		           10
#define NVIC_EXTI_LINE5_9 		           23
#define NVIC_EXTI_LINE10_15		           40



#define NVIC_TIMER1_BREAK		           24
#define NVIC_TIMER1_UPDATE		           25
#define NVIC_TIMER1_TRIGGER_COM            26
#define NVIC_TIMER1_CC			           27

#define NVIC_USART1				           37

#define NVIC_SPI1				           35
#define NVIC_SPI2				           36

#endif
