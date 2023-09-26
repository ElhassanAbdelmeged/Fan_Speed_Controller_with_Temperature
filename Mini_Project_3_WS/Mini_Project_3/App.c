
/*
 ================================================================================================
 Name        : APP.c
 Author      : Hassan Abd El Megef
 Description : mini project 3 that detect the temprature and turn on/off the fan according to the temp.
 Date        : 11/10/2022
 ================================================================================================
 */


#include<avr/io.h>
#include"motor.h"
#include"adc.h"
#include"gpio.h"
#include"lcd.h"
#include"lm35_sensor.h"


int main(void){
	uint8 Temprature=0 ,Previous_Temp=0;
ADC_ConfigType ADC_Parametars={INTERNAL,PRESCALER_8};
/*initializing the modules by calling the functions*/
	LCD_init();
	DcMotor_Init();
	ADC_init(&ADC_Parametars);

while(1)
{

	ADC_readChannel(PA2);
	Temprature= LM35_getTemperature();
if(Temprature!=Previous_Temp) /*this condition not to re generate the pwm every time*/
{
	if(Temprature<30)
	{
		DcMotor_Rotate(STOP,0);
		LCD_displayStringRowColumn(0,4,"FAN IS OFF");
		LCD_displayStringRowColumn(1,4,"Temp = ");
		LCD_intgerToString(Temprature);
		LCD_displayStringRowColumn(1,14,"C");

	}


	else if((Temprature>=30)&&(Temprature<60))
	{
		DcMotor_Rotate(CW,25);
		LCD_displayStringRowColumn(0,4,"FAN IS ON");
		LCD_displayCharacter(' ');
		LCD_displayStringRowColumn(1,4,"Temp = ");
		LCD_intgerToString(Temprature);
		LCD_displayStringRowColumn(1,14,"C");

	}

	else if((Temprature>=60)&&(Temprature<90))
	{
		DcMotor_Rotate(CW,50);
		LCD_displayStringRowColumn(0,4,"FAN IS ON");
		LCD_displayStringRowColumn(1,4,"Temp = ");
		LCD_intgerToString(Temprature);
		LCD_displayStringRowColumn(1,14,"C");

	}


	else if((Temprature>=90)&&(Temprature<120))
	{
		DcMotor_Rotate(CW,75);
		LCD_displayStringRowColumn(0,4,"FAN IS ON");
		if (Temprature>=100){
		LCD_displayStringRowColumn(1,4,"Temp = ");
		LCD_intgerToString(Temprature);
		LCD_displayStringRowColumn(1,14,"C");
		}
		else{
			LCD_displayStringRowColumn(1,4,"Temp = ");
			LCD_intgerToString(Temprature);
			LCD_displayCharacter(' '); //to overWrite on the units of 100,101,102 when reach the tens
			LCD_displayStringRowColumn(1,14,"C");

		}

	}

	else if(Temprature>=120)
		{
			DcMotor_Rotate(CW,100);
			LCD_displayStringRowColumn(0,4,"FAN IS ON");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			LCD_intgerToString(Temprature);
			LCD_displayStringRowColumn(1,14,"C");

		}


	Previous_Temp=Temprature;
}


	}



}
