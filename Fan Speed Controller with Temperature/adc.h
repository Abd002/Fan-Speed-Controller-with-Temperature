/*
 * adc.h
 *
 *  Created on: Feb 16, 2024
 *  Description : Analog to digital source file
 *  Author: AbdElRahman Khalifa
 */

#ifndef ADC_H_
#define ADC_H_

#include"standard_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_VOLTAGE_REF 2.56
#define ADC_MAX_PERCISION 1023


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum {
	EXTERNAL_VOLTAGE_REFERENCE, AVCC_WITH_AREF, INTERNAL_VOLTAGE_REFERENCE = 3
} ADC_ReferenceVolatge;

typedef enum {
	ADC_FRQ2 = 1,
	ADC_FRQ4,
	ADC_FRQ8,
	ADC_FRQ16,
	ADC_FRQ32,
	ADC_FRQ64,
	ADC_FRQ128
} ADC_Prescaler;

typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                               Functions Prototypes                          *
 *******************************************************************************/

/* setup ADC module */
void ADC_init(const ADC_ConfigType *configuration);

/* read analog signal from specific pin */
uint16 ADC_readChannel(uint8 ch_num);

/* read analog signal from specific pin 10 bits using interrupt method */
void ADC_readChannelAsync(uint8 ch_num);

#endif /* ADC_H_ */
