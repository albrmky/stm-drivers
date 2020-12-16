/*
 * TIMER1_private.h
 *
 *  Created on: Sep 16, 2020
 *      Author: noureldeen albrmky
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

typedef unsigned long  int u32;

typedef struct
{
	volatile u32 CR1        ;
	volatile u32 CR2        ;
	volatile u32 SMCR       ;
	volatile u32 DIER       ;
	volatile u32 SR         ;
	volatile u32 EGR        ;
	volatile u32 CCMR1      ;
	volatile u32 CCMR2      ;
	volatile u32 CCER       ;
	volatile u32 CNT        ;
	volatile u32 PSC        ;
	volatile u32 ARR        ;
	volatile u32 RCR        ;
	volatile u32 CCR1       ;
	volatile u32 CCR2       ;
	volatile u32 CCR3       ;
	volatile u32 CCR4       ;
	volatile u32 BDTR       ;
	volatile u32 DCR        ;
	volatile u32 DMAR       ;

}TIMER1_t;

#define TIMER1 ((volatile TIMER1_t*)0x40012C00)

#define CEN  0
#define UDIS 1
#define URS  2
#define OPM  3
#define DIR  4
#define ARPE 7

#define OSSI	10
#define OSSR	11
#define AOE		14
#define MOE		15

//>>>>>>>>>>>>>>>>>>>>>> FOR TIMER1_CR1

//CKD
#define TCLK		0
#define TCLK_2		1
#define TCLK_4		2

//APRE
#define OFF			0
#define ON			1

//CMS -->Center aligned mode selection
#define EDGE_ALIGNED				0
#define CENTER_ALIGNED_MODE_1		1
#define CENTER_ALIGNED_MODE_2		2
#define CENTER_ALIGNED_MODE_3		3


#define CCx_OUTPUT                            00
#define CCx_INPUT_SAME_TRIGGER_CHANNEL        01
#define CCx_INPUT_ADJACENT_TRIGGER_CHANNEL    10
#define CCx_MAPPED_TO_TRC                     11

#define CCx_FROZEN                             000
#define CCx_SET_CHANNEL_ACTIVE                 001
#define CCx_SET_CHANNEL_INACTIVE               010
#define CCx_TOGGLE                             011
#define CCx_FORCE_INACTIVE                     100
#define CCx_FORCE_ACTIVE                       101
#define CCx_PWM_MODE_1                         110
#define CCx_PWM_MODE_2                         111

#define NO_FILTER                             0000
#define FCENT_N_2                             0001
#define FCENT_N_4                             0010
#define FCENT_N_8                             0011
#define FDTS_2_N_6                            0100
#define FDTS_2_N_8                            0101
#define FDTS_4_N_6                            0110
#define FDTS_4_N_8                            0111
#define FDTS_8_N_6                            1000
#define FDTS_8_N_8                            1001
#define FDTS_16_N_5                           1010
#define FDTS_16_N_6                           1011
#define FDTS_16_N_8                           1100
#define FDTS_32_N_5                           1101
#define FDTS_32_N_6                           1110
#define FDTS_32_N_8                           1111

#define NO_PRESCALER							00
#define EVENTS_2								01
#define EVENTS_4								10
#define EVENTS_8								11


#define ETR_NON_INVERTED_ACTIVE_HIGH_RISING_EDGE	0
#define ETR_INVERTED_ACTIVE_LOW_FALLING_EDGE		1

#define ETR_ENABLE									1
#define ETR_DISABLE									0

#define NO_PRESCALER							00
#define ETR_2									01
#define ETR_4									10
#define ETR_8									11

#define ITR0                                    000
#define ITR1                                    001
#define ITR2                                    010
#define ITR3                                    011
#define TI1F_ED                                 100
#define TI1FP1                                  101
#define TI2FP2                                  110
#define ETRF									111

#define SLAVE_MODE_DISABLE                      000
#define ENCODER_MODE_1                          001
#define ENCODER_MODE_2                          010
#define ENCODER_MODE_3                          011
#define RESET_MODE	                            100
#define GATED_MODE                              101
#define TIGGER_MODE                             110
#define EXTERNAL_CLOCK_MODE_1                   111

#define LOW										0
#define HIGH									1

#define CHANNEL_1								0
#define CHANNEL_1_2_3							1

#define MM_RESET		                        000
#define MM_ENABLE                               001
#define MM_UPDATE                               010
#define MM_COMPARE_PULSE                        011
#define MM_COMPARE_OC1REF                       100
#define MM_COMPARE_OC2REF                       101
#define MM_COMPARE_OC3REF                       110
#define MM_COMPARE_OC4REF                       111

#define DMA_AT_COMPARE							0
#define DMA_AT_UPDATE_EVENT						1

#define COMG_ONLY								0
#define COMG_TGI_RISING_EDGE					1



#endif /* TIMER1_PRIVATE_H_ */
