/*
 * LED_program.c
 *
 *  Created on: Oct 5, 2022
 *      Author: LENOVO
 */
//lazem include math&std 2bl include 2l interface
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "LED_Interface.h"
#include "LED_Pcfg.h"
#include "LED_Private.h"


void LED_voidSetConfig(LED_Type Copy_strLedConfig)
{
	DIO_voidSetPinDirection(Copy_strLedConfig.LED_Port,Copy_strLedConfig.LED_Pin,DIO_OUTPUT);

}
void LED_voidOn(LED_Type Copy_strLedConfig)
{
	if(Copy_strLedConfig.LED_Connection==LED_FORWARD)
	{
		DIO_voidSetPinValue(Copy_strLedConfig.LED_Port,Copy_strLedConfig.LED_Pin,DIO_HIGH);
	}
	else if(Copy_strLedConfig.LED_Connection==LED_BACKWARD)
	{
		DIO_voidSetPinValue(Copy_strLedConfig.LED_Port,Copy_strLedConfig.LED_Pin,DIO_LOW);
	}
}
void LED_voidOff(LED_Type Copy_strLedConfig)
{
	if(Copy_strLedConfig.LED_Connection==LED_FORWARD)
	{
		DIO_voidSetPinValue(Copy_strLedConfig.LED_Port,Copy_strLedConfig.LED_Pin,DIO_LOW);
	}
	else if(Copy_strLedConfig.LED_Connection==LED_BACKWARD)
	{
		DIO_voidSetPinValue(Copy_strLedConfig.LED_Port,Copy_strLedConfig.LED_Pin,DIO_HIGH);
	}
}

void LED_voidLedTogglee(LED_Type Copy_strLedConfig)
{
	LED_voidOn( Copy_strLedConfig);
	_delay_ms(500);
	LED_voidOff( Copy_strLedConfig);
	_delay_ms(500);
}







