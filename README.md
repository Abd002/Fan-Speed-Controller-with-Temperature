## Fan Controller System

This repository contains the implementation of a temperature-controlled fan system based on the following specifications:

### System Requirements

1. **Aim:** Design a temperature-controlled fan using the ATmega32 microcontroller, where the fan automatically turns ON or OFF according to the temperature. Utilizes ATmega32 Microcontroller with a frequency of 1MHz.

2. **LM35 Temperature Sensor:** Provides continuous analog output corresponding to the sensed temperature. This analog signal is fed to the ADC for conversion to digital values.

3. **ADC:** Converts analog values to digital. Configuration includes operating with an internal reference voltage of 2.56V and a prescaler of F_CPU/8.

4. **LCD Display:** Displays the temperature and fan state continuously.

5. **Fan Control Logic:**
   - Temperature-based fan speed control:
     - Less than 30°C: Fan OFF.
     - 30-59°C: Fan ON at 25% speed.
     - 60-89°C: Fan ON at 50% speed.
     - 90-119°C: Fan ON at 75% speed.
     - 120°C or higher: Fan ON at 100% speed.

6. **DC Motor Control:** The DC motor rotates clockwise or stops based on the fan state.

7. **PWM Control:** Utilizes PWM signal generated from Timer0 to control DC motor speed. PWM frequency is set to 500Hz.

8. **Layered Architecture:** Follows a layered architecture model for project design and implementation.

### ADC Driver Requirements

- Implements a full ADC driver using a polling design.
- ADC_init function modified to accept a pointer to the configuration structure (ADC_ConfigType).
- ADC_ConfigType structure:
  ```c
  typedef struct {
      ADC_ReferenceVoltage ref_volt;
      ADC_Prescaler prescaler;
  } ADC_ConfigType;
  ```
- Configures ADC to use internal reference voltage of 2.56V and prescaler F_CPU/8.

### GPIO Driver Requirements

- Utilizes the same GPIO driver implemented in the course.

### LCD Driver Requirements

- Uses the same LCD driver implemented in the course with 8-bits data mode.
- Connects LCD control pins and data bus as follows:
  - RS → PD0
  - RW → GROUND
  - E → PD2
  - Data Bus → all PORTC pins.

### Temperature Sensor Driver Requirements

- Utilizes the same temperature sensor driver implemented in the course.
- Connects the LM35 temperature sensor to ADC channel 2.

### DC-Motor Driver Requirements

- Implements a full DC-Motor driver with the following functions:
  - `void DcMotor_Init(void)`: Sets up motor direction and stops the motor initially.
  - `void DcMotor_Rotate(DcMotor_State state, uint8 speed)`: Rotates the DC motor clockwise or anti-clockwise or stops it based on input state. Sends the required duty cycle to the PWM driver for speed control.

### PWM Driver Requirements

- Utilizes the PWM Timer0 function implemented in the course for PWM signal generation.
- `void PWM_Timer0_Start(uint8 duty_cycle)`: Starts Timer0 with PWM mode, configures prescaler, sets up non-inverting PWM mode, and sets the duty cycle based on the input percentage.

### Video Reference

- Watch this video for further details: [Fan Controller System Video](https://youtu.be/RFQGjcikfK4)
