/*
 * SSEG_Interface.h
 *
 *  Created on: Oct 6, 2022
 *      Author: LENOVO
 */

#ifndef SSEG_INTERFACE_H_
#define SSEG_INTERFACE_H_
#include"DIO_Interface.h"
#include"SSEG_Pcfg.h"
typedef struct {
	u8 SSEG_Port;
	u8 SSEG_Type;
#if SELECTION_COMM==CONNECTION_COM_PIN//lw mwsala 2l comman bl pin
	u8 SSEG_EnablePort;
	u8 SSEG_EnablePin;
#endif
}SSEG_Types;
#define SSEG_ComanCathode 0
#define SSEG_ComanAnode   1

#define SSEG_PORTA DIO_PORTA
#define SSEG_PORTB DIO_PORTB
#define SSEG_PORTC DIO_PORTC
#define SSEG_PORTD DIO_PORTD

#define SSEG_EPIN0 DIO_PIN0
#define SSEG_EPIN1 DIO_PIN1
#define SSEG_EPIN2 DIO_PIN2
#define SSEG_EPIN3 DIO_PIN3
#define SSEG_EPIN4 DIO_PIN4
#define SSEG_EPIN5 DIO_PIN5
#define SSEG_EPIN6 DIO_PIN6
#define SSEG_EPIN7 DIO_PIN7


void SSEG_voidSetConfig(SSEG_Types Copy_strSetConfig);
void SSEG_voidSendNumber(SSEG_Types Copy_strSetConfig,u8 Copy_u8Number);
#if SELECTION_COMM==CONNECTION_COM_PIN
void SSEG_voidEnable(SSEG_Types Copy_strSetConfig);
void SSEG_voidDisable(SSEG_Types Copy_strSetConfig);
#endif


#endif /* HAL_SSEG_SSEG_INTERFACE_H_ */
