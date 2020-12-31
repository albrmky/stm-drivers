/*
 * ADC_config.h
 *
 *  Created on: Dec 29, 2020
 *      Author: noureldeen albrmky
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


////////////////////////////////////////////////////////////////////////////////////////////
// SINGLE    CONT
#define SINGLE_CONT   SINGLE


////////////////////////////////////////////////////////////////////////////////////////////
//RIGHT_ALIGN     LEFT_ALIGN
#define DATA_ALIGN 			RIGHT_ALIGN

///////////////////////////////////////////////////////////////////////////////////////////
// DISABLED  ENABLED
#define EXTERNAL_TRIGGER 	DISABLED
/////////effective if EXTERNAL_TRIGGER ENABLED
/*
Timer1_CC1		Timer1_CC2
Timer1_CC3		Timer2_CC2
Timer3_TRGO		Timer4_CC4
EXTI_11			SOFTWARESTART
*/
#define REGULAR_TRIGGER_SOURCE  SOFTWARESTART

////////////////////////////////////////////////////////////////////////////////////////////
// DISABLED  ENABLED
#define JEXTERNAL_TRIGGER 	DISABLED
/////////effective if JEXTERNAL_TRIGGER ENABLED

/*
Timer1_TRGO		Timer1_CC4
Timer2_TRGO		Timer2_CC1
Timer3_CC4		Timer4_TRGO
EXTI_15			JSOFTWARESTART
*/
#define INJECTED_TRIGGER_SOURCE  JSOFTWARESTART

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 cycles_1_5
 cycles_7_5
 cycles_13_5
 cycles_28_5
 cycles_41_5
 cycles_55_5
 cycles_71_5
 cycles_239_5
 */
#define SAMPLE_TIME_CH0		cycles_7_5
#define SAMPLE_TIME_CH1     cycles_1_5
#define SAMPLE_TIME_CH2     cycles_1_5
#define SAMPLE_TIME_CH3     cycles_13_5
#define SAMPLE_TIME_CH4     cycles_1_5
#define SAMPLE_TIME_CH5     cycles_13_5
#define SAMPLE_TIME_CH6     cycles_1_5
#define SAMPLE_TIME_CH7     cycles_13_5
#define SAMPLE_TIME_CH8     cycles_1_5
#define SAMPLE_TIME_CH9     cycles_13_5
#define SAMPLE_TIME_CH10    cycles_1_5
#define SAMPLE_TIME_CH11    cycles_13_5
#define SAMPLE_TIME_CH12    cycles_1_5
#define SAMPLE_TIME_CH13    cycles_13_5
#define SAMPLE_TIME_CH14    cycles_1_5
#define SAMPLE_TIME_CH15    cycles_13_5
#define SAMPLE_TIME_CH16    cycles_1_5
#define SAMPLE_TIME_CH17	cycles_13_5


/////////////////////////////////////////////////////////////////////////
// only 12 bit register
// subtracted from injected channel results
// independent from the alignment

#define INJECTED_CHANNEL_OFFSET_1 		15
#define INJECTED_CHANNEL_OFFSET_2	    10
#define INJECTED_CHANNEL_OFFSET_3       10
#define INJECTED_CHANNEL_OFFSET_4       8


////////////////////////////////////////////////////////////////////////
// Analog watch dog thresholds
// from 0 to 4095
#define AWD_HIGH_THRESHOLD 4095
#define AWD_LOW_THRESHOLD  0




#endif /* ADC_CONFIG_H_ */
