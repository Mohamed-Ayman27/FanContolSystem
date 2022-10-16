/*
 ================================================================================================
 Name        : Application_FanCtrl.c
 Author      : Mohamed Ayman
 Description : Tempreture controlled automatic Fan
 Date        : 4/10/2022
 ================================================================================================
 */

#include "lcd.h"
#include "dc.h"
#include "lm35.h"
#include <util/delay.h>


uint8 g_temp=0;

int main(void)
{
	ADC_ConfigType config= {INTERNAL_2_56V,PRE_8};

	ADC_init(&config);
	LCD_init();
	DcMotor_Init();

	LCD_displayStringRowColumn(1, 3, "Temp =    C");



	while(1)
	{
		g_temp=LM35_getTemperature();

		LCD_moveCursor(1, 10);

		LCD_intgerToString(g_temp);

		if(g_temp<100)
		{
			LCD_moveCursor(1, 12);
			LCD_displayCharacter(' ');
		}

		if(g_temp<30)
		{
			LCD_displayStringRowColumn(0, 3, "FAN is OFF");
			DcMotor_Rotate(STOP,0);
		}

		else if(g_temp>=30 && g_temp<60)
		{
			LCD_displayStringRowColumn(0, 3, "FAN is ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,25);

		}
		else if(g_temp>=60 && g_temp<90)
		{
			LCD_displayStringRowColumn(0, 3, "FAN is ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,50);

		}
		else if(g_temp>=90 && g_temp<120)
		{
			LCD_displayStringRowColumn(0, 3, "FAN is ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);

		}
		else
		{
			LCD_displayStringRowColumn(0, 3, "FAN is ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,100);

		}


	}
}

