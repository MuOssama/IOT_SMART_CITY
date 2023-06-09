/*
 * EINT_Private.h
 *
 *  Created on: Mar 21, 2023
 *      Author: LENOVO
 */

#ifndef EINT_PRIVATE_H_
#define EINT_PRIVATE_H_

#define  SREG_REG    (*(volatile u8 *)0x5f)
#define  GICR_REG    (*(volatile u8 *)0x5B)
#define  GIFR_REG    (*(volatile u8 *)0x5A)
#define  MCUCR_REG   (*(volatile u8 *)0x55)
#define  MCUCSR_REG  (*(volatile u8 *)0x54)

#define  EINT_INT2   {DIO_PORTB,DIO_PIN2}
#define  EINT_INT1   {DIO_PORTD,DIO_PIN3}
#define  EINT_INT0   {DIO_PORTD,DIO_PIN2}

#define EINT_ARRAY {EINT_INT2,\
                    EINT_INT1,\
                    EINT_INT0\
                    }


#endif /* EINT_PRIVATE_H_ */
