# Fan Controller System

This mini project implements a temperature-controlled fan system using the ATmega32 microcontroller, operating at a frequency of 1MHz. The system is designed to automatically turn the fan ON or OFF based on the temperature sensed by an LM35 temperature sensor. Here are the key specifications:

1. **Objective:** Design a temperature-controlled fan system using an ATmega32 microcontroller.

2. **Temperature Sensing:** The LM35 temperature sensor provides continuous analog output corresponding to the temperature. This analog signal is converted to digital values using the onboard ADC (Analog-to-Digital Converter).

3. **Temperature Display:** The microcontroller calculates the temperature and displays it on an LCD.

4. **Fan Control:** The fan operates based on the following temperature thresholds:
   - If the temperature is less than 30°C, the fan is turned off.
   - If the temperature is 30°C or higher, the fan runs at 25% of its maximum speed.
   - At 60°C or higher, the fan runs at 50% of its maximum speed.
   - At 90°C or higher, the fan operates at 75% of its maximum speed.
   - At 120°C or higher, the fan runs at 100% of its maximum speed.

5. **DC-Motor Control:** The fan's state is controlled by switching the DC motor on or off. The DC motor rotates in a clockwise direction or is stopped based on the fan state.

6. **LCD Display:** The LCD continuously displays the current temperature and fan state.

7. **PWM Control:** The DC motor speed is controlled using PWM (Pulse Width Modulation) signals generated from Timer0.

8. **Layered Architecture:** The project follows a layered architecture model, including drivers for ADC, GPIO, LCD, Temperature Sensor, DC-Motor, and PWM.

**Drivers:**
- GPIO
- ADC
- PWM (using Timer0)
- LM35 Temperature Sensor
- LCD (8-bit data mode)

**Microcontroller:**
- ATmega32 (1MHz frequency)

**schematic:**
![image](https://github.com/ElhassanAbdelmeged/Fan_Speed_Controller_with_Temperature/assets/88130561/638872d9-f335-4264-9c54-211e5f502916)
