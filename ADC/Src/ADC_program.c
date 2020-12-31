/*
 * ADC_program.c
 *
 *  Created on: Dec 29, 2020
 *      Author: noureldeen albrmky
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"


#define CONCBIT_10(D0,D1,D2,D3,D4,D5,D6,D7,D8,D9)	CONCBIT_HELPER10(D0,D1,D2,D3,D4,D5,D6,D7,D8,D9)
#define CONCBIT_HELPER10(D0,D1,D2,D3,D4,D5,D6,D7,D8,D9) 0b##D9##D8##D7##D6##D5##D4##D3##D2##D1##D0

void MADC1_voidInit()
{

	u32 ADC_SMPR2_value = CONCBIT_10(	SAMPLE_TIME_CH0  ,
										SAMPLE_TIME_CH1  ,
										SAMPLE_TIME_CH2  ,
										SAMPLE_TIME_CH3  ,
										SAMPLE_TIME_CH4  ,
										SAMPLE_TIME_CH5  ,
										SAMPLE_TIME_CH6  ,
										SAMPLE_TIME_CH7  ,
										SAMPLE_TIME_CH8  ,
										SAMPLE_TIME_CH9   );

	u32 ADC_SMPR1_value = CONCBIT_10(	SAMPLE_TIME_CH10  ,
										SAMPLE_TIME_CH11  ,
										SAMPLE_TIME_CH12  ,
										SAMPLE_TIME_CH13  ,
										SAMPLE_TIME_CH14  ,
										SAMPLE_TIME_CH15  ,
										SAMPLE_TIME_CH16  ,
										SAMPLE_TIME_CH17  ,
										000  ,
										000   );

	// assign valued for sample rate register for each channel
	ADC1 -> ADC_SMPR2 = ADC_SMPR2_value ;
	ADC1 -> ADC_SMPR1 = ADC_SMPR1_value ;


	// assign the offset to be subtracted
	ADC1 -> ADC_JOFR1 = INJECTED_CHANNEL_OFFSET_1 ;
	ADC1 -> ADC_JOFR2 = INJECTED_CHANNEL_OFFSET_2 ;
	ADC1 -> ADC_JOFR3 = INJECTED_CHANNEL_OFFSET_3 ;
	ADC1 -> ADC_JOFR4 = INJECTED_CHANNEL_OFFSET_4 ;

	// thresholds of AWD
	ADC1 -> ADC_HTR = AWD_HIGH_THRESHOLD;
	ADC1 -> ADC_LTR = AWD_LOW_THRESHOLD;

	// external source enable/disable and sources

	INSERT_BIT(ADC1 -> ADC_CR2 ,EXTTRIG,EXTERNAL_TRIGGER);
	INSERT_BIT(ADC1 -> ADC_CR2 ,JEXTTRIG,JEXTERNAL_TRIGGER);

	INSERT_FIELD(ADC1 -> ADC_CR2,0x000E0000,REGULAR_TRIGGER_SOURCE,17);
	INSERT_FIELD(ADC1 -> ADC_CR2,0x00007000,INJECTED_TRIGGER_SOURCE,12);

	// ALIGNMENT of DATA
	INSERT_BIT(ADC1 -> ADC_CR2 ,ALIGN,DATA_ALIGN);




}



u8 MADC1_u8GetStatus(ADC1_STATUS_FLAGS flag)
{
	return GET_BIT(ADC1 -> ADC_SR,flag) ;
}
void MADC1_voidClearStatus(ADC1_STATUS_FLAGS flag )
{
	 CLR_BIT(ADC1 -> ADC_SR,flag) ;
}


u16 MADC1_u16GetInjData(u8 index)
{
	u16 return_value = 0 ;

	if (index ==1)
		return_value = ADC1->ADC_JDR1 ;
	else if (index ==2)
		return_value = ADC1->ADC_JDR2 ;
	else if (index ==3)
		return_value = ADC1->ADC_JDR3 ;
	else if (index ==4)
		return_value = ADC1->ADC_JDR4 ;

	return return_value;

}

u16 MADC1_u16GetregularData(void)
{
	return (u16)(ADC1 -> ADC_DR) ;
}

void MADC1_voidSetRegularSqeuenceLength(u8 length)
{
	ADC1 -> ADC_SQR1 = (length-1)<< 20 ;
}

void MADC1_voidSetRegularChannelSequences(u8 sequence , u8 channel_number)
{
	if(sequence < 7 )
	{
		INSERT_FIELD(ADC1 -> ADC_SQR3,0b11111 << (sequence-1) , channel_number , (sequence-1)*5);
	}
	else if(sequence < 13 )
	{
		sequence -=6;
		INSERT_FIELD(ADC1 -> ADC_SQR2,0b11111 << (sequence-1) , channel_number , (sequence-1)*5);
	}
	if(sequence < 17 )
	{
		sequence -=12;
		INSERT_FIELD(ADC1 -> ADC_SQR1,0b11111 << (sequence-1) , channel_number , (sequence-1)*5);
	}
}


void MADC1_voidSetInjectedSqeuenceLength(u8 length)
{

	ADC1 -> ADC_JSQR = (length-1)<< 20 ;
}

void MADC1_voidSetInjectedChannelSequences(u8 sequence , u8 channel_number)
{

	INSERT_FIELD(ADC1 -> ADC_JSQR,0b11111 << (sequence-1) , channel_number , (sequence-1)*5);

}

void MADC1_voidRegChannelSWTrigger()
{
	SET_BIT(ADC1 -> ADC_CR2 , 22);
}

void MADC1_voidInjChannelSWTrigger()
{
	SET_BIT(ADC1 -> ADC_CR2 , 21);
}

void MADC1_voidTempSensor(ADC1_STATE state)
{
	INSERT_BIT(ADC1 -> ADC_CR2 , TSVREFE ,state);
}


void MADC1_voidStartCalibration()
{
	SET_BIT(ADC1 -> ADC_CR2 , CAL);
}

void MADC1_voidStart_Enable()
{
	SET_BIT(ADC1 -> ADC_CR2 , ADON);
}

void MADC1_voidDMA(ADC1_STATE state)
{
	INSERT_BIT(ADC1 -> ADC_CR2 , DMA ,state);
}


void MADC1_voidINTMasks(ADC1_INT flag , ADC1_STATE state)
{
		INSERT_BIT(ADC1 -> ADC_CR1 , flag ,state);
}
