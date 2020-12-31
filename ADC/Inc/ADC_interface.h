/*
 * ADC_interface.h
 *
 *  Created on: Dec 29, 2020
 *      Author: noureldeen albrmky
 */

// ADC has a prescaler on RCC driver

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


typedef enum {  ADC1_AWD ,
				ADC1_EOC ,
				ADC1_JEOC ,
				ADC1_JSTART ,
				ADC1_START
}ADC1_STATUS_FLAGS;

typedef enum { ADC1_DIABLE,ADC1_ENABLE }ADC1_STATE;

typedef enum { 	ADC1_EOCIE = 5 ,
				ADC1_AWDIE,
				ADC1_JEOCIE
}ADC1_INT;


void MADC1_voidInit(void);  // for initialization
void MADC1_voidStartCalibration(void); // start calibration
void MADC1_voidStart_Enable(void);// start conversion

//interrupts flags / enable / clear
u8 MADC1_u8GetStatus(ADC1_STATUS_FLAGS flag);
void MADC1_voidINTMasks(ADC1_INT flag , ADC1_STATE state);
void MADC1_voidClearStatus(ADC1_STATUS_FLAGS flag );

// get data
u16 MADC1_u16GetInjData(u8 index);
u16 MADC1_u16GetregularData(void);

// regular sequence and length
void MADC1_voidSetRegularSqeuenceLength(u8 length);
void MADC1_voidSetRegularChannelSequences(u8 sequence , u8 channel_number);

// injected sequence and length
void MADC1_voidSetInjectedSqeuenceLength(u8 length);
void MADC1_voidSetInjectedChannelSequences(u8 sequence , u8 channel_number);


// Software trigger in case of triggered conversion
void MADC1_voidRegChannelSWTrigger(void);
void MADC1_voidInjChannelSWTrigger(void);


void MADC1_voidTempSensor(ADC1_STATE state);  	// enable temperature sensor
void MADC1_voidDMA(ADC1_STATE state);   		// enable DMA



#endif /* ADC_INTERFACE_H_ */
