/*
 * ADC_Program.c
 *
 *  Created on: Apr 12, 2023
 *      Author: LENOVO
 */
#include "uitils/std_types.h"
#include "uitils/BIT_MATH.h"
#include "ADC_Private.h"

void ADC_voidInt(void)
{
	/*AVCC(b2ne hwsl 5v mn 2l controler 3la 2nhom 2l clock)"Vref=5"*/
		SET_BIT(ADMUX_REG,6);
		CLR_BIT(ADMUX_REG,7);//"e3ny hwsl trf mn 2l potion bl gnd w 2l tany bl vcc"
		/*RIGHT ADJUST (34an acuuracy high 2omal 2l left bfked feh b3d 2l reads */
		CLR_BIT(ADMUX_REG,5);
	    /*single ended(b2ne b4t8l 3la channel w7da bs) on ADC0*/
		CLR_BIT(ADMUX_REG,0);
		CLR_BIT(ADMUX_REG,1);
		CLR_BIT(ADMUX_REG,2);
		CLR_BIT(ADMUX_REG,3);
		CLR_BIT(ADMUX_REG,4);
		/////

		/*2na h4t8l polying (e3ny disable pie e3ny 2na m4 48ala interupt l2 dah 2na 2wl lma ht3ely 2raya h7wlha 3latol) */

		/*enable ADC (e3ny hst5dmha ll adc m4 DIOpin 3deh)*/
		SET_BIT(ADCSRA_REG,7);
	    /*single conversion*/
		SET_BIT(ADCSRA_REG,6);//start conversion (e3ny b3d kl read lazem 23mlha set)
	    /*deh set lw 2na 48ala free runing mode*/
		CLR_BIT(ADCSRA_REG,5);
		/*clear ADC flag*/
		SET_BIT(ADCSRA_REG,4);
		/*enable pie bit 3 (m4 h3mlha set 34an 2na 48ala polying*/

		/*ADC PRE(largest pre 34an 3eza 22l freq)fh5leh /128*/
		SET_BIT(ADCSRA_REG,0);
		SET_BIT(ADCSRA_REG,1);
		SET_BIT(ADCSRA_REG,2);

}


