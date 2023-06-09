///********************************* project MDS *********************************************//

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include"uitils/BIT_MATH.h"
#include"uitils/std_types.h"
#include "MCAL/DIO/DIO.h"
#include <avr/delay.h>
#include "MCAL/ADC/ADC.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "DIO_Interface.h"


#define  Trigger_pin	PA2

int TimerOverflow = 0;

ISR(TIMER1_OVF_vect) {
	TimerOverflow++;
}

int main() {

	int static x = 0;
	f32 Result=0;
	ADC_voidInt();
	 while((GET_BIT(ADCSRA_REG,4))==0);
	 Result=ADCL_REG|(ADCH_REG<<8);
	/********************* ultrasonic sensor *******************************/
	/*******************pA2 : ultar  (trig)*********************************/
	/*******************pD6 : ultra (Echo)**********************************/

	char string[10];
	long count;
	double distance;

	DDRA = 0b00000100;
	PORTD = 0xFF;

	sei();
	TIMSK = (1 << TOIE1);
	TCCR1A = 0;

	while (1)
	{
	 while((GET_BIT(ADCSRA_REG,4))==0);
	 Result=ADCL_REG|(ADCH_REG<<8);
	 DIO_voidSetPinDirection(GROUPC,PIN_7,OUTPUT);
		PORTA |= (1 << Trigger_pin);
		_delay_us(10);
		PORTA &= (~(1 << Trigger_pin));

		TCNT1 = 0;
		TCCR1B = 0x41;
		TIFR = 1 << ICF1;
		TIFR = 1 << TOV1;

		while ((TIFR & (1 << ICF1)) == 0)
			;

		TCNT1 = 0;
		TCCR1B = 0x01;
		TIFR = 1 << ICF1;
		TIFR = 1 << TOV1;
		TimerOverflow = 0;

		while ((TIFR & (1 << ICF1)) == 0)
			;

		count = ICR1 + (65535 * TimerOverflow);

		distance = (double) count / 466.47;

		dtostrf(distance, 2, 2, string);

		char ar[10];

		if (distance > 3 && distance < 10  )
		{
			x++;
			sprintf(ar, "%d%c", (int) x);
			if(Result>500)
			 {DIO_voidSetPinValue(GROUPC,PIN_7,HIGH);}
			else
		     {DIO_voidSetPinValue(GROUPC,PIN_7,LOW);}
		}
		if(distance>10 || Result<500)
		{
			DIO_voidSetPinValue(GROUPC,PIN_7,LOW);
		}
		     SET_BIT(ADCSRA_REG,4);
			 SET_BIT(ADCSRA_REG,6);
			 Result=0;
	}
return 0;
	}

