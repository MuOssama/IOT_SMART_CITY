/*
 * traggic_light.c
 *
 *  Created on: Apr 10, 2023
 *      Author: LENOVO
 */

#include<util/delay.h>
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"SW_Interface.h"
#include"SW_Pcfg.h"
#include"EINT_Interface.h"
#include"EINT_Pcfg.h"
#include"SSEG_Interface.h"
#include"SSEG_Pcfg.h"
#include"LED_Interface.h"
#include"LED_Pcfg.h"
#include"LCD.h"
#include"DIO.h"

u8 volatile flage=0;
int main(void)
{
	LCD_Vinit();
	LCD_Clear();
sw_types SW0={SW_PORTD,SW_PIN2,SW_PULLUP};
SW_voidSetConfig(SW0);
EINT_voidInt0(FALLING_EDGE);
	SSEG_Types sseg1={SSEG_PORTC,SSEG_ComanCathode};
	SSEG_Types sseg2={SSEG_PORTA,SSEG_ComanCathode};

	LED_Type red_LED1={DIO_PORTD,DIO_PIN3,LED_FORWARD};//red
	LED_Type yellow_LED1={DIO_PORTD,DIO_PIN1,LED_FORWARD};//yellow
	LED_Type green_LED1={DIO_PORTD,DIO_PIN0,LED_FORWARD};//green
	LED_Type red_LED2={DIO_PORTD,DIO_PIN7,LED_FORWARD};//red2
	LED_Type yellow_LED2={DIO_PORTD,DIO_PIN6,LED_FORWARD};//yellow2
	LED_Type green_LED2={DIO_PORTA,DIO_PIN7,LED_FORWARD};//green2

	LED_voidSetConfig(red_LED1);
	LED_voidSetConfig(yellow_LED1);
	LED_voidSetConfig(green_LED1);
	LED_voidSetConfig(red_LED2);
	LED_voidSetConfig(yellow_LED2);
	LED_voidSetConfig(green_LED2);

	SSEG_voidSetConfig(sseg1);
	SSEG_voidSetConfig(sseg2);

	while(1)
	{
		for(u8 counter=1;counter<10;counter++)
	        {
	        if(counter<=7)
	        {
	            SSEG_voidSendNumber(sseg1,counter);
	            SSEG_voidSendNumber(sseg2,counter);
	            _delay_ms(10);
	            LED_voidOn(red_LED1);
	            LED_voidOn(green_LED2);
	            flage=1;
	            _delay_ms(2000);
	        }
	        if(counter>7 && counter<10)
	        {
	        	LED_voidOff(green_LED2);
	        	SSEG_voidSendNumber(sseg1,counter);
	            SSEG_voidSendNumber(sseg2,counter);
	            _delay_ms(10);
	            LED_voidOn(red_LED1);
	        	LED_voidOn(yellow_LED2);
	        	flage=2;
	        	_delay_ms(2000);
	        }
	        }
		 LED_voidOff(yellow_LED2);
		 LED_voidOff(red_LED1);
		for(u8 counter=1;counter<10;counter++)
				{
				if(counter<=7)
			   zzzzzzzzzzzzzzzzzz {
				    SSEG_voidSendNumber(sseg1,counter);
				    SSEG_voidSendNumber(sseg2,counter);
				    _delay_ms(10);
				    LED_voidOn(red_LED2);
				    LED_voidOn(green_LED1);
				    flage=3;
				    _delay_ms(2000);
				}
				if(counter>7 && counter<10)
				{
					LED_voidOff(green_LED1);
					SSEG_voidSendNumber(sseg1,counter);
				    SSEG_voidSendNumber(sseg2,counter);
				    _delay_ms(10);
				    LED_voidOn(red_LED2);
					LED_voidOn(yellow_LED1);
					flage=4;
					_delay_ms(2000);
				}
				}
		LED_voidOff(yellow_LED1);
		LED_voidOff(red_LED2);
	}
}

void __vector_1(void)__attribute__((signal));//exit0
void __vector_1(void)
	{
	LCD_Vinit();
	LCD_GOTOXY(1,0);
	LCD_Send_string("Train is coming");
	LCD_GOTOXY(2,0);
	LCD_Send_string("soon");


	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
	SSEG_Types sseg1={SSEG_PORTC,SSEG_ComanCathode};
		SSEG_Types sseg2={SSEG_PORTA,SSEG_ComanCathode};

		LED_Type red_LED1={DIO_PORTD,DIO_PIN3,LED_FORWARD};//red
		LED_Type yellow_LED1={DIO_PORTD,DIO_PIN1,LED_FORWARD};//yellow
		LED_Type green_LED1={DIO_PORTD,DIO_PIN0,LED_FORWARD};//green
		LED_Type red_LED2={DIO_PORTD,DIO_PIN7,LED_FORWARD};//red2
		LED_Type yellow_LED2={DIO_PORTD,DIO_PIN6,LED_FORWARD};//yellow2
		LED_Type green_LED2={DIO_PORTA,DIO_PIN7,LED_FORWARD};//green2

		LED_voidSetConfig(red_LED1);
		LED_voidSetConfig(yellow_LED1);
		LED_voidSetConfig(green_LED1);
		LED_voidSetConfig(red_LED2);
		LED_voidSetConfig(yellow_LED2);
		LED_voidSetConfig(green_LED2);

		SSEG_voidSetConfig(sseg1);
		SSEG_voidSetConfig(sseg2);
		_delay_ms(1000);
				/*red_1 on&green2 on in  main*/
						if(flage==1||flage==2)
						{
							SSEG_voidSendNumber(sseg1,0);
							SSEG_voidSendNumber(sseg2,0);
							LED_voidOn(red_LED1);
							LED_voidOff(green_LED2);
							LED_voidOff(yellow_LED2);
							for(u8 counter=1;counter<4;counter++)
						    {
						    		SSEG_voidSendNumber(sseg2,counter);
						    		LED_voidOn( yellow_LED2);
						    		_delay_ms(1000);
						    		LED_voidOff(yellow_LED2);
						    }
							LED_voidOn(red_LED2);
							////////////////////////////////
							SSEG_voidSendNumber(sseg1,0);
							SSEG_voidSendNumber(sseg2,0);
							_delay_ms(1000);
							for(u8 i=4;i>=1;i--)
							{
								if(i=4)
								{
									LCD_GOTOXY(2,0);
									LCD_Send_string("in 4 Sec");
									SSEG_voidSendNumber(sseg1,4);
									SSEG_voidSendNumber(sseg2,4);
									_delay_ms(2000);
								}
								if(i=3)
								{
									LCD_GOTOXY(2,3);
									LCD_Send_string("3");
									SSEG_voidSendNumber(sseg1,3);
									SSEG_voidSendNumber(sseg2,3);
									_delay_ms(2000);
								}
								if(i=2)
								{
									LCD_GOTOXY(2,3);
									LCD_Send_string("2");
									SSEG_voidSendNumber(sseg1,2);
									SSEG_voidSendNumber(sseg2,2);
									_delay_ms(2000);
									LCD_GOTOXY(2,3);
								    LCD_Send_string("1");
								    SSEG_voidSendNumber(sseg1,1);
								    SSEG_voidSendNumber(sseg2,1);
								    _delay_ms(2000);
								}
								if(i=1)
								{
									LCD_Clear();
									_delay_ms(10);
									LCD_GOTOXY(1,0);
									LCD_Send_string("Train arrived");
									SSEG_voidSendNumber(sseg1,0);
									SSEG_voidSendNumber(sseg2,0);
									_delay_ms(2000);
								}

							}

                                 	DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);//bazzer on
									_delay_ms(5000);
									DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);//bazzer off
									LED_voidOff(red_LED2);
						}
						if(flage==3||flage==4)
						{
							SSEG_voidSendNumber(sseg1,0);
														SSEG_voidSendNumber(sseg2,0);
														LED_voidOn(red_LED2);
														LED_voidOff(green_LED1);
														LED_voidOff(yellow_LED1);
														for(u8 counter=1;counter<4;counter++)
													    {
													    		SSEG_voidSendNumber(sseg1,counter);
													    		LED_voidOn( yellow_LED1);
													    		_delay_ms(1000);
													    		LED_voidOff(yellow_LED1);
													    }
														LED_voidOn(red_LED1);
														////////////////////////////////
														SSEG_voidSendNumber(sseg1,0);
														SSEG_voidSendNumber(sseg2,0);
														_delay_ms(3000);
														for(u8 i=4;i>=1;i--)
														{
															if(i=4)
															{
																LCD_GOTOXY(2,0);
																LCD_Send_string("in 4 Sec");
																SSEG_voidSendNumber(sseg1,4);
																SSEG_voidSendNumber(sseg2,4);
																_delay_ms(2000);
															}
															if(i=3)
															{
																LCD_GOTOXY(2,3);
																LCD_Send_string("3");
																SSEG_voidSendNumber(sseg1,3);
																SSEG_voidSendNumber(sseg2,3);
																_delay_ms(2000);
															}
															if(i=2)
															{
																LCD_GOTOXY(2,3);
																LCD_Send_string("2");
																SSEG_voidSendNumber(sseg1,2);
																SSEG_voidSendNumber(sseg2,2);
																_delay_ms(2000);
																LCD_GOTOXY(2,3);
															    LCD_Send_string("1");
															    SSEG_voidSendNumber(sseg1,1);
															    SSEG_voidSendNumber(sseg2,1);
															    _delay_ms(2000);
															}
															if(i=1)
															{
																LCD_Clear();
																_delay_ms(10);
																LCD_GOTOXY(1,0);
																LCD_Send_string("Train arrived");
																SSEG_voidSendNumber(sseg1,0);
																SSEG_voidSendNumber(sseg2,0);
																_delay_ms(2000);
															}

														}

							                                 	DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);//bazzer on
																_delay_ms(5000);
																DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);//bazzer off
																LED_voidOff(red_LED1);
						}


						LCD_Clear();
				}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                          /*scale 1 7segma*/
//{
//		sw_types SW0={SW_PORTD,SW_PIN2,SW_PULLUP};
//		SW_voidSetConfig(SW0);
//		EINT_voidInt0(FALLING_EDGE);
//
//		SSEG_Types sseg1={SSEG_PORTC,SSEG_ComanCathode};
//		LED_Type red_LED1={DIO_PORTD,DIO_PIN3,LED_FORWARD};//red
//		LED_Type green_LED1={DIO_PORTD,DIO_PIN0,LED_FORWARD};//green
//		LED_Type yellow_LED1={DIO_PORTD,DIO_PIN1,LED_FORWARD};//yellow
//		LED_voidSetConfig(red_LED1);
//		LED_voidSetConfig(yellow_LED1);
//		LED_voidSetConfig(green_LED1);
//
//	while(1)
//	{
//
//	for(u8 counter=1;counter<10;counter++)
//			{
//				SSEG_voidSendNumber(sseg1,counter);
//
//				_delay_ms(10);
//				LED_voidOn(red_LED1);//red1
//				_delay_ms(1000);
//			flage=1;
//			}
//			LED_voidOff(red_LED1);//red1
//			for(u8 counter=1;counter<10;counter++)
//					{
//						SSEG_voidSendNumber(sseg1,counter);
//						_delay_ms(10);
//						LED_voidOn(green_LED1);
//						_delay_ms(1000);
//                         flage=2;
//					}
//			LED_voidOff(green_LED1);
//			for(u8 counter=1;counter<3;counter++)
//			{
//				SSEG_voidSendNumber(sseg1,counter);
//				_delay_ms(10);
//				LED_voidOn(yellow_LED1);
//				_delay_ms(1000);
//			         flage=3;
//			}
//			LED_voidOff(yellow_LED1);
//		}
// return 0;
//}
//
//
//void __vector_1(void)__attribute__((signal));//exit0
//void __vector_1(void)
//	{
//	LCD_Vinit();
//	LCD_GOTOXY(1,0);
//	LCD_Send_string("Train is coming");
//	LCD_GOTOXY(2,0);
//	LCD_Send_string("in 4 Sec");
//
//	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
//		SSEG_Types sseg1={SSEG_PORTC,SSEG_ComanCathode};
//				LED_Type red_LED1={DIO_PORTD,DIO_PIN3,LED_FORWARD};//red
//				LED_Type green_LED1={DIO_PORTD,DIO_PIN0,LED_FORWARD};//green
//				LED_Type yellow_LED1={DIO_PORTD,DIO_PIN1,LED_FORWARD};//yellow
//				LED_voidSetConfig(red_LED1);
//				LED_voidSetConfig(yellow_LED1);
//				LED_voidSetConfig(green_LED1);
//				_delay_ms(1000);
//				/*red on in  main*/
//		if(flage==1)//red_1 on
//		{
//			for(u8 i=4;i>1;i--)
//			{
//				if(i=4)
//				{
//					LCD_GOTOXY(2,3);
//					LCD_Send_string("3");
//					_delay_ms(2000);
//				}
//				if(i=3)
//				{
//					LCD_GOTOXY(2,3);
//					LCD_Send_string("2");
//					_delay_ms(2000);
//
//				}
//				if(i=2)
//				{
//					LCD_GOTOXY(2,3);
//					LCD_Send_string("1");
//					_delay_ms(2000);
//				}
//
//			}
//
//			SSEG_voidSendNumber(sseg1,0);
//					DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);//bazzer on
//					_delay_ms(5000);
//					DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);//bazzer off
//		}
//		//////////////////////////////
//
//		if(flage==2 || flage==3 )//green_1 on|| yellow_1 on
//			{
//			LED_voidOff(green_LED1);
//			LED_voidOff(yellow_LED1);
//
//			for(u8 counter=1;counter<4;counter++)
//			{
//					SSEG_voidSendNumber(sseg1,counter);
//					LED_voidOn( yellow_LED1);
//					_delay_ms(1000);
//					LED_voidOff(yellow_LED1);
//			}
//			LED_voidOn(red_LED1);
//			for(u8 i=4;i>1;i--)
//						{
//							if(i=4)
//							{
//								LCD_GOTOXY(2,3);
//								LCD_Send_string("3");
//								_delay_ms(2000);
//							}
//							if(i=3)
//							{
//								LCD_GOTOXY(2,3);
//								LCD_Send_string("2");
//								_delay_ms(2000);
//
//							}
//							if(i=2)
//							{
//								LCD_GOTOXY(2,3);
//								LCD_Send_string("1");
//								_delay_ms(2000);
//							}
//
//			SSEG_voidSendNumber(sseg1,0);
//			DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);//bazzer on
//			_delay_ms(3000);
//			DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);//bazzer off
//		  }
//		LED_voidOff(red_LED1);
//	}
//		LCD_Clear();
//}
