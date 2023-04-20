/*
 * PWM_int.h
 *
 *  Created on: Apr 9, 2023
 *      Author: yasmi
 */

#ifndef MCAL_PWM_PWM_INT_H_
#define MCAL_PWM_PWM_INT_H_

#include "PWM_config.h"
#include "../../Service/BIT_MATH.h"
#include "avr/io.h"

/*-Choosing the pwm mode*/
void PWM_Init(void);

/*Settting the prescaler*/
void PWM_Start(PWM_PRESCALER prescaler);

/*Settting the prescaler to 0 */
void PWM_Stop(void);


void PWM_SetDuty(PWM_MODE mode, uint8_t dutyCycle);

#endif /* MCAL_PWM_PWM_INT_H_ */
