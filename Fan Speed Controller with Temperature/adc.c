/*
 * adc.c
 *
 *  Created on: Feb 16, 2024
 *  Description : Analog to digital header file
 *  Author: AbdElRahman Khalifa
 */

#include"adc.h"
#include"common_macros.h"
#include<avr/io.h>
#include<avr/interrupt.h>

volatile int g_adcResult;

/* setup ADC module */
void ADC_init(const ADC_ConfigType *configuration){
	/* Reference Selection Bits */
	ADMUX=(ADMUX&0x3f)|(configuration->ref_volt<<6);

	/* ADC Enable */
	SET_BIT(ADCSRA, ADEN);

	/* Interrupt disable */
	CLEAR_BIT(ADCSRA,ADIE);

	/* ADC Prescaler 50 - 300 KHz & our MC is 16 MHz */
	ADCSRA=(ADCSRA&0xf8)|configuration->prescaler;
}

/* read analog signal from specific pin 10 bits using polling method */
uint16 ADC_readChannel(uint8 ch_num){
	/* Analog Channel Selection Bits */
	ADMUX&=0xe0;
	ADMUX|=(ch_num&0x1f);

	/* ADC Start Conversion */
	SET_BIT(ADCSRA, ADSC);

	/* waiting the conversion using polling */
	while(!GET_BIT(ADCSRA,ADIF));

	SET_BIT(ADCSRA,ADIF); 	/* clear flag by set it  */

	return ADC;
}

