/*
 * lm35_sensor.c
 *
 *  Created on: Feb 19, 2024
 *  Description : LM35 Temperature Sensor header file
 *  Author: AbdElRahman Khalifa
 */


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include"standard_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LM35_PIN_ID 2
#define LM35_SENSITIVITY 0.01

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* calculate the value of temp */
uint8 LM35_getTemperature(void);


#endif /* LM35_SENSOR_H_ */
