/*
 * SW_Program.c
 *
 *  Created on: Oct 5, 2022
 *      Author: LENOVO
 */
#include"uitils/std_types.h"
#include"uitils/BIT_MATH.h"
#include"DIO_Interface.h"
#include"DIO_Pcfg.h"
#include"SW_Interface.h"
#include"SW_Pcfg.h"
#include"SW_Private.h"
//obj sw0
void SW_voidSetConfig(sw_types Copy_strSwConfig)//3,1,1
{
	DIO_voidSetPinDirection(Copy_strSwConfig.SW_Port,Copy_strSwConfig.SW_Pin,DIO_INPUT);//3,1,input->ddrd=0
	if(Copy_strSwConfig.SW_State==SW_PULLUP)
	{
		DIO_voidSetPinValue(Copy_strSwConfig.SW_Port,Copy_strSwConfig.SW_Pin,DIO_HIGH);//portd pin2 =1
	}
	//	else if(Copy_strButtonConfig.SW_State==SW_Floating)
	//	{
	//		DIO_voidSetPinValue(Copy_strButtonConfig.SW_Port,Copy_strButtonConfig.SW_Pin,DIO_LOW);
	//	}m4 m7taga 2gml kda 34an by deffult 2l port=0


}
u8 SW_u8GetButtonState(sw_types Copy_strSwConfig)
{

	u8 Loc_u8ButtonState=0;
	Loc_u8ButtonState=DIO_u8GetpinValue(Copy_strSwConfig.SW_Port,Copy_strSwConfig.SW_Pin);
	return Loc_u8ButtonState;
}
