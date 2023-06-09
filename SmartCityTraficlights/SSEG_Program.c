/*
 * SSEG_Program.c
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include "DIO_Interface.h"
#include"SSEG_Interface.h"
#include"SSEG_Pcfg.h"
void SSEG_voidSetConfig(SSEG_Types Copy_strSetConfig)
{
	DIO_voidSetPortDirection(Copy_strSetConfig.SSEG_Port,255);//DDR=1
}
void SSEG_voidSendNumber(SSEG_Types Copy_strSetConfig,u8 Copy_u8Number)
{
	u8 SSEG_u8Number[10]=
			{  ~0b00111111, /* 0 */
			  ~0b00000110, /* 1 */
			  ~0b01011011, /* 2 */
			  ~0b01001111, /* 3 */
			  ~0b01100110, /* 4 */
			  ~0b01101101, /* 5 */
			  ~0b01111101, /* 6 */
			  ~0b00000111, /* 7 */
			  ~0b01111111, /* 8 */
			  ~0b01101111 /* 9 */
			};
	if(Copy_strSetConfig.SSEG_Type==SSEG_ComanCathode)
	{
		DIO_voidSetPortValue(Copy_strSetConfig.SSEG_Port,SSEG_u8Number[Copy_u8Number]);//PORT=1 tnwar
	}
	else if(Copy_strSetConfig.SSEG_Type==SSEG_ComanAnode)
	{
		DIO_voidSetPortValue(Copy_strSetConfig.SSEG_Port,~(SSEG_u8Number[Copy_u8Number]));//PORT=0 tnwar
	}
}
#if SELECTION_COMM==CONNECTION_COM_PIN
void SSEG_voidEnable(SSEG_Types Copy_strSetConfig)
{
	DIO_voidSetPinDirection(Copy_strSetConfig.SSEG_EnablePort,Copy_strSetConfig.SSEG_EnablePin,DIO_OUTPUT);
	if(Copy_strSetConfig.SSEG_Type==SSEG_ComanCathode)
	{
		DIO_voidSetPinValue(Copy_strSetConfig.SSEG_EnablePort,Copy_strSetConfig.SSEG_EnablePin,DIO_LOW);
	}
	else if(Copy_strSetConfig.SSEG_Type==SSEG_ComanAnode)
	{
		DIO_voidSetPinValue(Copy_strSetConfig.SSEG_EnablePort,Copy_strSetConfig.SSEG_EnablePin,DIO_HIGH);
	}
}
void SSEG_voidDisable(SSEG_Types Copy_strSetConfig)
{
	DIO_voidSetPinDirection(Copy_strSetConfig.SSEG_EnablePort,Copy_strSetConfig.SSEG_EnablePin,DIO_OUTPUT);
		if(Copy_strSetConfig.SSEG_Type==SSEG_ComanCathode)
		{
			DIO_voidSetPinValue(Copy_strSetConfig.SSEG_EnablePort,Copy_strSetConfig.SSEG_EnablePin,DIO_HIGH);
		}
		else if(Copy_strSetConfig.SSEG_Type==SSEG_ComanAnode)
		{
			DIO_voidSetPinValue(Copy_strSetConfig.SSEG_EnablePort,Copy_strSetConfig.SSEG_EnablePin,DIO_LOW);
		}
}
#endif




