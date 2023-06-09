/*
 * LED_interface.h
 *
 *  Created on: Oct 5, 2022
 *      Author: LENOVO
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
typedef struct{
	u8 LED_Port;
	u8 LED_Pin;
	u8 LED_Connection;
}LED_Type;

#define LED_FORWARD 1
#define LED_BACKWARD 0


#define LED_PortA DIO_PORTA
#define LED_PortB DIO_PORTB
#define LED_PortC DIO_PORTC
#define LED_PortD DIO_PORTD



void LED_voidSetConfig(LED_Type Copy_strLedConfig);
void LED_voidOn(LED_Type Copy_strLedConfig);
void LED_voidOff(LED_Type Copy_strLedConfig);

void LED_voidLedTogglee(LED_Type Copy_strLedConfig);




#endif /* HAL_LED_LED_INTERFACE_H_ */
