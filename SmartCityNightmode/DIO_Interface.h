/*
 * DIO_interface.h
 *
 *  Created on: Oct 5, 2022
 *      Author: LENOVO
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_OUTPUT 1
#define DIO_INPUT  0


#define DIO_HIGH 1
#define DIO_LOW  0



//
//
//void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);
//void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
//void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);
////void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);
//void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
////lw direction input m7taga 2d5l 2l port
//u8 DIO_u8GetPortValue(u8 Copy_u8Port);
//u8 DIO_u8GetpinValue(u8 Copy_u8Port,u8 Copy_u8Pin);
//
//
void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
u8 DIO_u8GetPortValue(u8 Copy_u8Port);
u8 DIO_u8GetpinValue(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
