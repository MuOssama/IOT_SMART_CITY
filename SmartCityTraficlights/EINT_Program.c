/*
 * EINT_Program.c
 *
 *  Created on: Mar 21, 2023
 *      Author: LENOVO
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "EINT_Interface.h"
#include "EINT_Private.h"
#include "EINT_Pcfg.h"



u8 EINT_Array[3][2]= EINT_ARRAY;


void EINT_voidInt2(u8 Copy_u8Mode)
 	{
 		DIO_voidSetPinDirection(EINT_Array[0][0],EINT_Array[0][1],DIO_INPUT);
 		DIO_voidSetPinValue(EINT_Array[0][0],EINT_Array[0][1],DIO_HIGH);
 		EINT_voidMode2(Copy_u8Mode);
 		SET_BIT(GIFR_REG,5);//clear flage
 		SET_BIT(GICR_REG,5);
 		SET_BIT(SREG_REG,7);
 	}

 void EINT_voidInt1(u8 Copy_u8Mode)
	{
		DIO_voidSetPinDirection(EINT_Array[1][0],EINT_Array[1][1],DIO_INPUT);
		DIO_voidSetPinValue(EINT_Array[1][0],EINT_Array[1][1],DIO_HIGH);
		EINT_voidMode1(Copy_u8Mode);
 		SET_BIT(GIFR_REG,7);//clear flage
 		SET_BIT(GICR_REG,7);
 		SET_BIT(SREG_REG,7);
	}

void EINT_voidInt0(u8 Copy_u8Mode)
 	{
		DIO_voidSetPinDirection(EINT_Array[2][0],EINT_Array[2][1],DIO_INPUT);
		DIO_voidSetPinValue(EINT_Array[2][0],EINT_Array[2][1],DIO_HIGH);
 		EINT_voidMode0(Copy_u8Mode);
		SET_BIT(GIFR_REG,6);//clear flage
 		SET_BIT(GICR_REG,6);
 		SET_BIT(SREG_REG,7);
	}





	void EINT_voidMode0(u8 Copy_u8Modee)
{
	switch(Copy_u8Modee)
	{
	case FALLING_EDGE:
		CLR_BIT(MCUCR_REG,0);
		SET_BIT(MCUCR_REG,1);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR_REG,0);
		SET_BIT(MCUCR_REG,1);
		break;
	case LOGICAL_CHANGE:SET_BIT(MCUCR_REG,0);;break;
	case LOW_LEVEL:
		CLR_BIT(MCUCR_REG,0);
		CLR_BIT(MCUCR_REG,1);
		break;
	default:break;
	}
}



void EINT_voidMode1(u8 Copy_u8Modee)
{
	switch(Copy_u8Modee)
	{
	case FALLING_EDGE:
		CLR_BIT(MCUCR_REG,0);
		SET_BIT(MCUCR_REG,1);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCR_REG,0);
		SET_BIT(MCUCR_REG,1);
		break;
	case LOGICAL_CHANGE:SET_BIT(MCUCR_REG,0);;break;
	case LOW_LEVEL:
		CLR_BIT(MCUCR_REG,0);
		CLR_BIT(MCUCR_REG,1);
		break;
	default:break;
	}
}



void EINT_voidMode2(u8 Copy_u8Modee)
{
	switch(Copy_u8Modee)
	{
	case FALLING_EDGE:
		CLR_BIT(MCUCSR_REG,6);
				break;
	case RISING_EDGE:
		SET_BIT(MCUCSR_REG,6);
				break;
		default:break;
	}
}

/*
#if SELECTED_EINT==EINT_INT2
{
	void(*ptr2)(void);
	void __vector_3(void)__attribute__((signal));
	void __vector_3(void)
	{
		_delay_ms(500);
		ptr2();
		SET_BIT(GIFR_REG,5);
	}
	void SetCallBack(void(*copy)void)
	{
		ptr2=copy;
	}
}
#endif


#if SELECTED_EINT==EINT_INT1
{
	void(*ptr1)(void);
	void __vector_2(void)__attribute__((signal));
	void __vector_2(void)
	{
		_delay_ms(500);
		ptr1();
		SET_BIT(GIFR_REG,7);
	}
	void SetCallBack(void(*copy)void)
		{
			ptr1=copy;
		}
}
#endif


#if SELECTED_EINT==EINT_INT0
{
	void(*ptr0)(void);
	void __vector_1(void)__attribute__((signal));
	void __vector_1(void)
	{
		_delay_ms(500);
		ptr0();
		SET_BIT(GIFR_REG,6);//clear flage
	}
	void SetCallBack(void(*copy)void)
		{
			ptr0=copy;
		}
}
#endif

*/
