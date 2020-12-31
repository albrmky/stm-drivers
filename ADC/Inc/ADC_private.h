/*
 * ADC_private.h
 *
 *  Created on: Dec 29, 2020
 *      Author: noureldeen albrmky
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

typedef struct
{
    volatile u32 ADC_SR        ;
    volatile u32 ADC_CR1       ;
    volatile u32 ADC_CR2       ;
    volatile u32 ADC_SMPR1     ;
    volatile u32 ADC_SMPR2     ;
    volatile u32 ADC_JOFR1     ;
    volatile u32 ADC_JOFR2     ;
    volatile u32 ADC_JOFR3     ;
    volatile u32 ADC_JOFR4     ;
    volatile u32 ADC_HTR       ;
    volatile u32 ADC_LTR       ;
    volatile u32 ADC_SQR1      ;
    volatile u32 ADC_SQR2      ;
    volatile u32 ADC_SQR3      ;
    volatile u32 ADC_JSQR      ;
    volatile u32 ADC_JDR1      ;
    volatile u32 ADC_JDR2      ;
    volatile u32 ADC_JDR3      ;
    volatile u32 ADC_JDR4      ;
    volatile u32 ADC_DR        ;
}ADC_t;

#define ADC1 ((volatile ADC_t*)0x40012400)

 #define cycles_1_5    000
 #define cycles_7_5    001
 #define cycles_13_5   010
 #define cycles_28_5   011
 #define cycles_41_5   100
 #define cycles_55_5   101
 #define cycles_71_5   110
 #define cycles_239_5  111

// special bits in ADC_CR1
#define AWDEN   23
#define JAWDEN  22
#define JDISCEN 12
#define DISCEN  11
#define JAUTO   10
#define AWDSGL  9
#define SCAN	8
#define JEOCIE	7
#define AWDIE	6
#define EOCIE	5

// special bits in ADC_CR_2
#define TSVREFE  23
#define SWSTART  22
#define JSWSTART 21
#define EXTTRIG  20
#define JEXTTRIG 15
#define ALIGN	 11
#define DMA		 8
#define RSTCAL	 3
#define CAL		 2
#define CONT	 1
#define ADON	 0


#define DISABLED 0
#define ENABLED  1
//(TIM8_TRGO is available only in high-density and XLdensity)

//for regular group external trigger
#define Timer1_CC1             0b000
#define Timer1_CC2             0b001
#define Timer1_CC3             0b010
#define Timer2_CC2             0b011
#define Timer3_TRGO            0b100
#define Timer4_CC4             0b101
#define EXTI_11                0b110  //(TIM8_TRGO is available only in high-density and XLdensity)
#define SOFTWARESTART          0b111

//(TIM8_CC4 is available only in high-density and XLdensity devices)
#define Timer1_TRGO              0b000
#define Timer1_CC4            	 0b001
#define Timer2_TRGO              0b010
#define Timer2_CC1            	 0b011
#define Timer3_CC4            	 0b100
#define Timer4_TRGO              0b101
#define EXTI_15     		 	 0b110
#define JSOFTWARESTART           0b111


#define RIGHT_ALIGN				0
#define LEFT_ALIGN 				1

#define SINGLE  0
#define CONT    1

#endif /* ADC_PRIVATE_H_ */
