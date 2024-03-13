/*
 * 	main.c
 *
 *  Created on: Feb 19, 2024
 *  Author: AbdElRahman Khalifa
 */

#include"lm35_sensor.h"
#include"lcd.h"
#include"motor.h"
#include"adc.h"


DcMotor_State g_motorState=CW;

int main(){
	/* struct contains the configuration of ADC Driver */
	ADC_ConfigType  adcConfiguration={INTERNAL_VOLTAGE_REFERENCE, ADC_FRQ8};

	/* initialization for ADC, LCD and Motor driver */
	ADC_init(&adcConfiguration);
	LCD_init();
	DcMotor_Init();

	LCD_displayString("    Fan is");// 13
	while(1){
		uint8 temperature=LM35_getTemperature();

		LCD_moveCursor(1, 4);
		LCD_displayString("Temp = ");
		LCD_intgerToString(temperature);
		LCD_displayString(" C ");

		if(temperature<30){

			LCD_moveCursor(0, 11);
			LCD_displayString("OFF");

			DcMotor_Rotate(g_motorState, 0);
		}else if(temperature<60){

			LCD_moveCursor(0, 11);
			LCD_displayString("ON ");

			DcMotor_Rotate(g_motorState, 25);
		}else if(temperature<90){

			DcMotor_Rotate(g_motorState, 50);
		}else if(temperature<120){

			DcMotor_Rotate(g_motorState, 75);
		}else {

			DcMotor_Rotate(g_motorState, 100);
		}
	}
}
