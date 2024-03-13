/*
 * lm35_sensor.c
 *
 *  Created on: Feb 19, 2024
 *  Description : LM35 Temperature Sensor soure file
 *  Author: AbdElRahman Khalifa
 */

#include"lm35_sensor.h"
#include"adc.h"
#include<util/delay.h>

/*
 * calculate the value of temp
 * ADC_VOLTAGE_REF -> ADC_MAX_PERCISION
 * x               -> value
 *
 * x / LM35_SENSITIVITY  = C
*/
uint8 LM35_getTemperature(void){
	uint16 value=ADC_readChannel(LM35_PIN_ID);
	return (uint8)((value*ADC_VOLTAGE_REF)/(ADC_MAX_PERCISION*LM35_SENSITIVITY));
}
