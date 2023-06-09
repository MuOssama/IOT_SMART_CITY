/*
 * SW_Interface.h
 *
 *  Created on: Oct 5, 2022
 *      Author: LENOVO
 */

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_
typedef struct{
	u8 SW_Port;
	u8 SW_Pin;
	u8 SW_State;

}sw_types;

#define SW_PORTA DIO_PORTA
#define SW_PORTB DIO_PORTB
#define SW_PORTC DIO_PORTC
#define SW_PORTD DIO_PORTD



#define  SW_PIN0  DIO_PIN0
#define  SW_PIN1  DIO_PIN1
#define  SW_PIN2  DIO_PIN2
#define  SW_PIN3  DIO_PIN3
#define  SW_PIN4  DIO_PIN4
#define  SW_PIN5  DIO_PIN5
#define  SW_PIN6  DIO_PIN6
#define  SW_PIN7  DIO_PIN7


#define SW_PRESSED_PULLUP    0
#define SW_NOTPRESSED_PULLUP 1



#define SW_PRESSED_PULLDOWN    1
#define SW_NOTPRESSED_PULLDOWN 0



#define SW_PULLUP   1
#define SW_FlOATING 0

//#define SW_HIGH DIO_HIGH
//#define SW_LOW  DIO_LOW

void SW_voidSetConfig(sw_types Copy_strButtonConfig);
u8 SW_u8GetButtonState(sw_types Copy_strButtonConfig);


#endif /* HAL_SW_SW_INTERFACE_H_ */
