/*
 * TIMER1_config.h
 *
 *  Created on: Sep 16, 2020
 *      Author: noureldeen albrmky
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

//----------------------------------------------------CR1--------------------------------------
// TCLK    TCLK_2    TCLK_4
#define DEAD_TIME_SAMPLING_CLOCK	TCLK
//  ON    OFF
#define PRELOAD_ARR   				OFF
// EDGE_ALIGNED	// CENTER_ALIGNED_MODE_1	// CENTER_ALIGNED_MODE_2// CENTER_ALIGNED_MODE_3
#define COUNTER_MODE 				CENTER_ALIGNED_MODE_1
//  ON    OFF
#define ONE_PULSE_MODE				OFF

//-----------------------------------------------------CR2------------------------------------------
//MM_RESET		 //MM_ENABLE        //MM_UPDATE
//MM_COMPARE_PULSE
//MM_COMPARE_OC1REF		//MM_COMPARE_OC2REF
//MM_COMPARE_OC3REF		//MM_COMPARE_OC4REF
#define MASTER_MODE_SELECTION 			MM_RESET

//CHANNEL_1		//CHANNEL_1_2_3
#define TRIGGER_INPUT_1_SELECTION		CHANNEL_1

//DMA_AT_COMPARE
//DMA_AT_UPDATE_EVENT
#define CC_DMA_SELECTION				DMA_AT_COMPARE

//COMG_ONLY			//COMG_TGI_RISING_EDGE
#define CC_CONTROL_UPDATE_SELECTION		COMG_ONLY

//  ON    OFF
#define PRELOAD_CONTROL					OFF


//----------------------------------------------------SMCR------------------------------------------
//ITR0    //ITR1    //ITR2    //ITR3
//TI1F_ED //TI1FP1  //TI2FP2  //ETRF
#define TRIGGER_SOURCE								ETRF

//SLAVE_MODE_DISABLE
//ENCODER_MODE_1       //ENCODER_MODE_2       //ENCODER_MODE_3
//RESET_MODE	       //GATED_MODE           //TIGGER_MODE
//EXTERNAL_CLOCK_MODE_1
#define SLAVE_MODE_SELECT							SLAVE_MODE_DISABLE

//  ON    OFF
#define DELAY_TRGO_FOR_SYNCHRONIZATION 				OFF

//-------------------------------------------------------------------BDTR---------------------------------------

#define OFF_STATE_SELECTION_FOR_RUN_MODE		ON

#define OFF_STATE_SELECTION_FOR_IDEAL_MODE		ON

#define AUTOMATIC_OUTPUT_ENABLE					OFF

#define DEAD_TIME_GENERATOR						0		//  0 -> 255
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//CCx_OUTPUT							//CCx_INPUT_SAME_TRIGGER_CHANNEL
//CCx_INPUT_ADJACENT_TRIGGER_CHANNEL	//CCx_MAPPED_TO_TRC
#define CAPTURE_COMPARE_1_SELECTION  CCx_OUTPUT //------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#if CAPTURE_COMPARE_1_SELECTION == CCx_OUTPUT

//CCx_FROZEN
//CCx_SET_CHANNEL_ACTIVE//CCx_SET_CHANNEL_INACTIVE
//CCx_TOGGLE
//CCx_FORCE_INACTIVE//CCx_FORCE_ACTIVE
//CCx_PWM_MODE_1    ACTIVE as long as CNT<CC1
//CCx_PWM_MODE_2	ACTIVE as long as CNT>CC1
#define CC1_OUTPUT_COMPARE_MODE				CCx_PWM_MODE_1
// ON OFF
#define CC1_OUTPUT_PRELOAD 					ON				// mandatory in PWM Modes
#define CC1_OUTPUT_CLEAR_OCxREF				OFF				// if configured GPIO I/P will be read high
#define CC1_OUTPUT_FAST_ENABLE				OFF

// HIGH  LOW
#define CC1_OUTPUT_IDEAL_STATE				HIGH
#define CC1N_OUTPUT_IDEAL_STATE				LOW

#else

//NO_PRESCALER	//EVENTS_2	//EVENTS_4	//EVENTS_8
#define INPUT_CAPTURE_1_PRESCALER  			NO_PRESCALER

//NO_FILTER
//FCENT_N_2		//FCENT_N_4		//FCENT_N_8
//FDTS_2_N_6	//FDTS_2_N_8
//FDTS_4_N_6	//FDTS_4_N_8
//FDTS_8_N_6	//FDTS_8_N_8
//FDTS_16_N_5	//FDTS_16_N_6	//FDTS_16_N_8
//FDTS_32_N_5	//FDTS_32_N_6	//FDTS_32_N_8
#define INPUT_CAPTURE_1_FILTER_SAMPLING		NO_FILTER

#define CC1_OUTPUT_IDEAL_STATE				LOW   // just to be able to configure CR2 in input mode
#define CC1N_OUTPUT_IDEAL_STATE				LOW

#endif


//CCx_OUTPUT							//CCx_INPUT_SAME_TRIGGER_CHANNEL
//CCx_INPUT_ADJACENT_TRIGGER_CHANNEL	//CCx_MAPPED_TO_TRC
#define CAPTURE_COMPARE_2_SELECTION  CCx_OUTPUT //------>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#if CAPTURE_COMPARE_2_SELECTION == CCx_OUTPUT

//CCx_FROZEN//CCx_SET_CHANNEL_ACTIVE//CCx_SET_CHANNEL_INACTIVE//CCx_TOGGLE
//CCx_FORCE_INACTIVE//CCx_FORCE_ACTIVE//CCx_PWM_MODE_1//CCx_PWM_MODE_2
#define CC2_OUTPUT_COMPARE_MODE				CCx_FROZEN
// ON OFF
#define CC2_OUTPUT_PRELOAD 					OFF			// mandatory in PWM Modes
#define CC2_OUTPUT_CLEAR_OCxREF				OFF			// if configured GPIO I/P will be read high
#define CC2_OUTPUT_FAST_ENABLE				OFF

#define CC2_OUTPUT_IDEAL_STATE				LOW
#define CC2N_OUTPUT_IDEAL_STATE				LOW

#else

//NO_PRESCALER	//EVENTS_2	//EVENTS_4	//EVENTS_8
#define INPUT_CAPTURE_2_PRESCALER  			NO_PRESCALER

//NO_FILTER
//FCENT_N_2		//FCENT_N_4		//FCENT_N_8
//FDTS_2_N_6	//FDTS_2_N_8
//FDTS_4_N_6	//FDTS_4_N_8
//FDTS_8_N_6	//FDTS_8_N_8
//FDTS_16_N_5	//FDTS_16_N_6	//FDTS_16_N_8
//FDTS_32_N_5	//FDTS_32_N_6	//FDTS_32_N_8
#define INPUT_CAPTURE_2_FILTER_SAMPLING		FDTS_32_N_8

#define CC2_OUTPUT_IDEAL_STATE				LOW // just to be able to configure CR2 in input mode
#define CC2N_OUTPUT_IDEAL_STATE				LOW

#endif


//CCx_OUTPUT							//CCx_INPUT_SAME_TRIGGER_CHANNEL
//CCx_INPUT_ADJACENT_TRIGGER_CHANNEL	//CCx_MAPPED_TO_TRC
#define CAPTURE_COMPARE_3_SELECTION  CCx_OUTPUT //-------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#if CAPTURE_COMPARE_3_SELECTION == CCx_OUTPUT

//CCx_FROZEN//CCx_SET_CHANNEL_ACTIVE//CCx_SET_CHANNEL_INACTIVE//CCx_TOGGLE
//CCx_FORCE_INACTIVE//CCx_FORCE_ACTIVE//CCx_PWM_MODE_1//CCx_PWM_MODE_2
#define CC3_OUTPUT_COMPARE_MODE				CCx_FROZEN
// ON OFF
#define CC3_OUTPUT_PRELOAD 					OFF			// mandatory in PWM Modes
#define CC3_OUTPUT_CLEAR_OCxREF				OFF			// if configured GPIO I/P will be read high
#define CC3_OUTPUT_FAST_ENABLE				OFF

#define CC3_OUTPUT_IDEAL_STATE				LOW
#define CC3N_OUTPUT_IDEAL_STATE				LOW

#else

//NO_PRESCALER	//EVENTS_2	//EVENTS_4	//EVENTS_8
#define INPUT_CAPTURE_3_PRESCALER  			NO_PRESCALER

//NO_FILTER
//FCENT_N_2		//FCENT_N_4		//FCENT_N_8
//FDTS_2_N_6	//FDTS_2_N_8
//FDTS_4_N_6	//FDTS_4_N_8
//FDTS_8_N_6	//FDTS_8_N_8
//FDTS_16_N_5	//FDTS_16_N_6	//FDTS_16_N_8
//FDTS_32_N_5	//FDTS_32_N_6	//FDTS_32_N_8
#define INPUT_CAPTURE_3_FILTER_SAMPLING		NO_FILTER

#define CC3_OUTPUT_IDEAL_STATE				LOW	// just to be able to configure CR2 in input mode
#define CC3N_OUTPUT_IDEAL_STATE				LOW

#endif


//CCx_OUTPUT							//CCx_INPUT_SAME_TRIGGER_CHANNEL
//CCx_INPUT_ADJACENT_TRIGGER_CHANNEL	//CCx_MAPPED_TO_TRC
#define CAPTURE_COMPARE_4_SELECTION  CCx_OUTPUT  // ----------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#if CAPTURE_COMPARE_4_SELECTION == CCx_OUTPUT

//CCx_FROZEN//CCx_SET_CHANNEL_ACTIVE//CCx_SET_CHANNEL_INACTIVE//CCx_TOGGLE
//CCx_FORCE_INACTIVE//CCx_FORCE_ACTIVE//CCx_PWM_MODE_1//CCx_PWM_MODE_2
#define CC4_OUTPUT_COMPARE_MODE				CCx_FROZEN
// ON OFF
#define CC4_OUTPUT_PRELOAD 					OFF				// mandatory in PWM Modes
#define CC4_OUTPUT_CLEAR_OCxREF				OFF				// if configured GPIO I/P will be read high
#define CC4_OUTPUT_FAST_ENABLE				OFF

#define CC4_OUTPUT_IDEAL_STATE				LOW

#else

//NO_PRESCALER	//EVENTS_2	//EVENTS_4	//EVENTS_8
#define INPUT_CAPTURE_4_PRESCALER  			NO_PRESCALER

//NO_FILTER
//FCENT_N_2		//FCENT_N_4		//FCENT_N_8
//FDTS_2_N_6	//FDTS_2_N_8
//FDTS_4_N_6	//FDTS_4_N_8
//FDTS_8_N_6	//FDTS_8_N_8
//FDTS_16_N_5	//FDTS_16_N_6	//FDTS_16_N_8
//FDTS_32_N_5	//FDTS_32_N_6	//FDTS_32_N_8
#define INPUT_CAPTURE_4_FILTER_SAMPLING		NO_FILTER

#define CC4_OUTPUT_IDEAL_STATE				LOW		// just to be able to configure CR2 in input mode


#endif



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ETR_ENABLE	//ETR_DISABLE
#define EXTERNAL_TRIGGER_ENABLE		ETR_DISABLE
//ETR_NON_INVERTED_ACTIVE_HIGH_RISING_EDGE	//ETR_INVERTED_ACTIVE_LOW_FALLING_EDGE
#define EXTERNAL_TRIGGER_POLARITY		ETR_NON_INVERTED_ACTIVE_HIGH_RISING_EDGE
//NO_PRESCALER		//ETR_2		//ETR_4		//ETR_8
#define EXTERNAL_TRIGGER_PRESCALER		ETR_2

//NO_FILTER
//FCENT_N_2		//FCENT_N_4		//FCENT_N_8
//FDTS_2_N_6	//FDTS_2_N_8
//FDTS_4_N_6	//FDTS_4_N_8
//FDTS_8_N_6	//FDTS_8_N_8
//FDTS_16_N_5	//FDTS_16_N_6	//FDTS_16_N_8
//FDTS_32_N_5	//FDTS_32_N_6	//FDTS_32_N_8
#define EXTERNAL_TRIGGER_FILTER		NO_FILTER

#endif /* TIMER1_CONFIG_H_ */
