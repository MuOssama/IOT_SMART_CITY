/*
 * DIO_program.c
 *
 *  Created on: Oct 5, 2022
 *      Author: LENOVO
 */

#include"uitils/BIT_MATH.h"
#include"uitils/std_types.h"
#include "DIO_Interface.h"
#include "DIO_Pcfg.h"
#include "DIO_Private.h"
/*
 * set direction ->DDR
 * lw DDR=0->INPUT
 * lw DDR=1->outPUT
 *
 * set value
 * input->PORT_reg=0,
 * output->PORT=1,
 *
 * get value
 * b2ne b2ra 2l PIN_reg
 * lw 2na desa 3la pull up switch 2l PIN_reg==0 bm3na 2n 2l PIN_reg (read zero)
 * note 27na bn4t8l 3la pull up switch b2ny b5le 2l DDR_reg->input(=0) && PORT_reg==1
 */
void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)//2na m7taga 2grf 2na 48ala 3la 2nhy port mn 2l 4 & 2l pin bt3ty act as input wla output
// fk2n 2dtlo(0(porta,255)2w(1(portb,128(1000 0000)m3naha 2n pin7 output w 2l ba2y input)
//dah fe 7alet 2ny 48ala 3la port kamel
{
	switch(Copy_u8Port)
	{
	case DIO_PORTA:DIO_DDRA_REG=Copy_u8Direction;break;
	case DIO_PORTB:DIO_DDRB_REG=Copy_u8Direction;break;
	case DIO_PORTC:DIO_DDRC_REG=Copy_u8Direction;break;
	case DIO_PORTD:DIO_DDRD_REG=Copy_u8Direction;break;
	default:break;
	}

}
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)//value 2l hea high wla low 2l lmba ht2ed wla l2
{
	switch(Copy_u8Port)
	{
    case DIO_PORTA:DIO_PORTA_REG=Copy_u8Value;break;
	case DIO_PORTB:DIO_PORTB_REG=Copy_u8Value;break;
	case DIO_PORTC:DIO_PORTC_REG=Copy_u8Value;break;
	case DIO_PORTD:DIO_PORTD_REG=Copy_u8Value;break;
	default:break;
	}

}
void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)//(porta,8,output)
{
  if(Copy_u8Direction==DIO_OUTPUT)
  {
	  switch(Copy_u8Port)
	  {
    case DIO_PORTA:SET_BIT(DIO_DDRA_REG,Copy_u8Pin);break;
	case DIO_PORTB:SET_BIT(DIO_DDRB_REG,Copy_u8Pin);break;
	case DIO_PORTC:SET_BIT(DIO_DDRC_REG,Copy_u8Pin);break;
	case DIO_PORTD:SET_BIT(DIO_DDRD_REG,Copy_u8Pin);break;
	default:break;
	  }
  }
  else if(Copy_u8Direction==DIO_INPUT)
  {
	 switch(Copy_u8Port)
	 {
    case DIO_PORTA:CLR_BIT(DIO_DDRA_REG,Copy_u8Pin);break;
	case DIO_PORTB:CLR_BIT(DIO_DDRB_REG,Copy_u8Pin);break;
	case DIO_PORTC:CLR_BIT(DIO_DDRC_REG,Copy_u8Pin);break;
	case DIO_PORTD:CLR_BIT(DIO_DDRD_REG,Copy_u8Pin);break;
	default:break;
	 }
  }

}
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)//(porta ,7,PORTa=1)

{
	if(Copy_u8Value==DIO_HIGH)
	  {
		  switch(Copy_u8Port)
		  {
	    case DIO_PORTA:SET_BIT(DIO_PORTA_REG,Copy_u8Pin);break;
		case DIO_PORTB:SET_BIT(DIO_PORTB_REG,Copy_u8Pin);break;
		case DIO_PORTC:SET_BIT(DIO_PORTC_REG,Copy_u8Pin);break;
		case DIO_PORTD:SET_BIT(DIO_PORTD_REG,Copy_u8Pin);break;
		default:break;
		  }
	  }
	  else if(Copy_u8Value==DIO_LOW)
	  {
		 switch(Copy_u8Port)
		 {
	    case DIO_PORTA:CLR_BIT(DIO_PORTA_REG,Copy_u8Pin);break;
		case DIO_PORTB:CLR_BIT(DIO_PORTB_REG,Copy_u8Pin);break;
		case DIO_PORTC:CLR_BIT(DIO_PORTC_REG,Copy_u8Pin);break;
		case DIO_PORTD:CLR_BIT(DIO_PORTD_REG,Copy_u8Pin);break;
		default:break;
		 }
	  }
}
u8 DIO_u8GetPortValue(u8 Copy_u8Port)//pin act as input PORT=1 34an pull up resistance
{
	u8 Loc_u8Result=0;
	switch(Copy_u8Port)
	{
	        case DIO_PORTA:Loc_u8Result=DIO_PINA_REG;break;
			case DIO_PORTB:Loc_u8Result=DIO_PINB_REG;break;
			case DIO_PORTC:Loc_u8Result=DIO_PINC_REG;break;
			case DIO_PORTD:Loc_u8Result=DIO_PIND_REG;break;
	}
	return Loc_u8Result;

}
u8 DIO_u8GetpinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Loc_u8Result=0;
	switch(Copy_u8Port)
	{
	case DIO_PORTA:Loc_u8Result=GET_BIT(DIO_PINA_REG,Copy_u8Pin);break;
	case DIO_PORTB:Loc_u8Result=GET_BIT(DIO_PINB_REG,Copy_u8Pin);break;
	case DIO_PORTC:Loc_u8Result=GET_BIT(DIO_PINC_REG,Copy_u8Pin);break;
	case DIO_PORTD:Loc_u8Result=GET_BIT(DIO_PIND_REG,Copy_u8Pin);;break;
	}
	return Loc_u8Result;
}


