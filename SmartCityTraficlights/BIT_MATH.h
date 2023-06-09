/*
 * BIT_MATH.h
 *
 *  Created on: Oct 5, 2022
 *      Author: LENOVO
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,bit) x=x|(1<<bit)
#define CLR_BIT(x,bit) x=x&~(1<<bit)
#define TOG_BIT(x,bit) x=x^(1<<bit)
#define GET_BIT(x,bit) ((x>>bit)&1)


#endif /* SERVISES_BIT_MATH_H_ */
