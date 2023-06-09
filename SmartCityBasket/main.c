///********************************* project MDS *********************************************//

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uitils/std_types.h"
#include"uitils/BIT_MATH.h"
#include "MCAL/DIO/DIO.h"
//#include "DIO_Program.c"
//#include "HAL/LCD/LCD.h"
#include <avr/delay.h>
#include "MCAL/ADC/ADC.h"
#include"SW_Interface.h"
#include"SW_Pcfg.h"

#define  Trigger_pin	PA2

int TimerOverflow = 0;

ISR(TIMER1_OVF_vect) {
	TimerOverflow++;
}

int main()
{

	sw_types SW0={GROUPD,PIN_2,SW_PULLUP};
	DIO_SetPinDirection(GROUPA,PIN_7,OUTPUT);//red
	DIO_SetPinDirection(GROUPA,PIN_6,OUTPUT);//green
	DIO_SetPinDirection(GROUPC,PIN_7,OUTPUT);//BAZZER
	SW_voidSetConfig(SW0);
	DIO_SetPinDirection(GROUPD,PIN_5,OUTPUT);	//OC1A(servo)
	int static x = 0;
	/********************* ultrasonic sensor *******************************/
	/*******************pA2 : ultar  (trig)*********************************/
	/*******************pD6 : ultra (Echo)**********************************/


	char string[10];
	long count;
	double distance;

	DIO_SetPinDirection(GROUPA,PIN_2,OUTPUT);
    //DDRA = 0b00000100;
    DIO_SetPinValue(GROUPD,PIN_6,HIGH);
    //PORTD = 0b01000000;

	sei();
	TIMSK = (1 << TOIE1);
	TCCR1A = 0;

	while (1)
	{

	PORTA |= (1 << Trigger_pin);
	_delay_us(10);
	PORTA &= (~(1 << Trigger_pin));

	TCNT1 = 0;
	TCCR1B =0b01000001;
	TIFR = 1 << ICF1;
	TIFR = 1 << TOV1;

	while ((TIFR & (1 << ICF1)) == 0)
		;

	TCNT1 = 0;
	TCCR1B =0b00000001;
	TIFR = 1 << ICF1;
	TIFR = 1 << TOV1;
	TimerOverflow = 0;

	while ((TIFR & (1 << ICF1)) == 0)
		;

	count = ICR1 + (65535 * TimerOverflow);

	distance = (double) count / 466.47;

	dtostrf(distance, 2, 2, string);

	char ar[10];

//		if (distance > 3 && distance < 10)
//		{
//			sprintf(ar, "%d%c", (int) x);
//			_delay_ms(200);
//			/***************servo******************/
//			TCCR1A=0b10000010;
//				TCCR1B=0b00011100;
//				ICR1=625;
//				_delay_ms(10);
//				OCR1A=15;//0degree
//			    _delay_ms(500);
//			   	OCR1A=75;//180degree
//			    _delay_ms(500);
//			    OCR1A=15;//0degree
//			    ICR1=0;
//			    TCCR1A=0;
//			    TCCR1B=0;
//		}
//	///////////////////////////////
//		if(DIO_GetPinValue(GROUPD,PIN_2)==0)
//		  {
//			_delay_ms(100);
//			if(DIO_GetPinValue(GROUPD,PIN_2)==0)
//			{
//
//				if (distance >10 && distance < 15)
//				{
//					DIO_SetPinValue(GROUPA,PIN_6,HIGH); //green on
//					sprintf(ar, "%d%c", (int) x);
//			         _delay_ms(10);
//					/***************servo******************/
//					TCCR1A=0b10000010;
//				    TCCR1B=0b00011100;
//				    ICR1=625;
//				    _delay_ms(10);
//				    OCR1A=15;//0degree
//					_delay_ms(4000);
//						OCR1A=75;//180degree
//					_delay_ms(500);
//					OCR1A=15;//0degree
//					ICR1=0;
//					TCCR1A=0;
//					TCCR1B=0;
//				}
//			   	if (distance >5 && distance < 10)
//			   {
//			   	DIO_SetPinValue(GROUPA,PIN_6,LOW); //green off
//			   	DIO_SetPinValue(GROUPA,PIN_7,HIGH); //red on
//			   	sprintf(ar, "%d%c", (int) x);
//			   	_delay_ms(10);
//			   	/***************servo******************/
//			   	       TCCR1A=0b10000010;
//			   	     	TCCR1B=0b00011100;
//			   	     	ICR1=625;
//			   	     	_delay_ms(10);
//			   	     	OCR1A=15;//0degree
//			   	         _delay_ms(4000);
//			   	        	OCR1A=75;//180degree
//			   	         _delay_ms(500);
//			   	         OCR1A=15;//0degree
//			   	         ICR1=0;
//			   	         TCCR1A=0;
//			   	         TCCR1B=0;
//
//			   }
//				if (distance >3 && distance < 5)
//				{
//
//					DIO_SetPinValue(GROUPC,PIN_7,HIGH);//bazzer on
//					sprintf(ar, "%d%c", (int) x);
//				     _delay_ms(10);
//				    /***************servo******************/
//				    TCCR1A=0b10000010;
//				    TCCR1B=0b00011100;
//				    ICR1=625;
//				    _delay_ms(10);
//				    OCR1A=15;//0degree
//				    _delay_ms(4000);
//				    	OCR1A=75;//180degree
//				    _delay_ms(500);
//				    OCR1A=15;//0degree
//				    ICR1=0;
//				    TCCR1A=0;
//				    TCCR1B=0;
//
//				}
//				else
//				{
//					DIO_SetPinValue(GROUPA,PIN_7,LOW); //red off
//					DIO_SetPinValue(GROUPC,PIN_7,LOW);//bazzer off
//					sprintf(ar, "%d%c", (int) x);
//			        _delay_ms(10);
//			       /***************servo******************/
//			       TCCR1A=0b10000010;
//			       TCCR1B=0b00011100;
//			       ICR1=625;
//			       _delay_ms(10);
//			       OCR1A=15;//0degree
//			       _delay_ms(4000);
//			       	OCR1A=75;//180degree
//			       _delay_ms(500);
//			       OCR1A=15;//0degree
//			       ICR1=0;
//			       TCCR1A=0;
//			       TCCR1B=0;
//				}
//			}
//		}
//
//		}
//return 0;
//	}
/////////////////////////////
//while (1)
	//{
	if(DIO_GetPinValue(GROUPD,PIN_2)==0)
	{
				_delay_ms(100);
				if(DIO_GetPinValue(GROUPD,PIN_2)==0)
				{
	/***************servo******************/
			    TCCR1A=0b10000010;
				TCCR1B=0b00011100;
				ICR1=625;
				_delay_ms(10);
				OCR1A=15;//0degree
			    _delay_ms(4000);
			   	OCR1A=75;//180degree
			    _delay_ms(500);
			    OCR1A=15;//0degree
			    ICR1=0;
			    TCCR1A=0;
			    TCCR1B=0;
				}
				else
			    {

               TCCR1A=0b10000010;
				TCCR1B=0b00011100;
				ICR1=625;
				_delay_ms(10);
				OCR1A=15;//0degree
              _delay_ms(100);

			    ICR1=0;
			    TCCR1A=0;
			    TCCR1B=0;
	          }
	}
	if (distance >5 && distance < 10)
				{
					DIO_SetPinValue(GROUPA,PIN_6,HIGH); //green on
					DIO_SetPinValue(GROUPA,PIN_7,LOW); //red off
					DIO_SetPinValue(GROUPC,PIN_7,LOW);//bazzer off

				}
	if (distance <1)
	{
		DIO_SetPinValue(GROUPC,PIN_7,HIGH);//bazzer on
		_delay_ms(2000);
		DIO_SetPinValue(GROUPC,PIN_7,LOW);//bazzer off
	}
	if(distance > 15)
	{
		DIO_SetPinValue(GROUPC,PIN_7,LOW);//bazzer off
		DIO_SetPinValue(GROUPA,PIN_7,LOW); //red off
		DIO_SetPinValue(GROUPA,PIN_6,LOW); //green off

	}


  }

 return 0;
	}
