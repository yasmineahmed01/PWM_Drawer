/*
 * PWM_priv.h
 *
 *  Created on: Apr 9, 2023
 *      Author: yasmi
 */

#ifndef MCAL_PWM_PWM_PRIV_H_
#define MCAL_PWM_PWM_PRIV_H_

#define SREG 			*((volatile uint16*) 0x5F)
#define TIMSK 			*((volatile uint16*) 0x59)
#define TIFR 			*((volatile uint16*) 0x58)

#define SPH 			*((volatile uint16*) 0x5E)
#define SPL 			*((volatile uint16*) 0x5D)

#define TCCR0 			*((volatile uint16*) 0x53)
#define TCNT0 			*((volatile uint16*) 0x52)
#define OCR0 			*((volatile uint16*) 0x5C)

#define TCCR2 			*((volatile uint16*) 0x45)
#define TCNT2 			*((volatile uint16*) 0x44)
#define OCR2 			*((volatile uint16*) 0x43)


#endif /* MCAL_PWM_PWM_PRIV_H_ */
