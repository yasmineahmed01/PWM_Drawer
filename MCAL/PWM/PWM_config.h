/*
 * PWM_config.h
 *
 *  Created on: Apr 9, 2023
 *      Author: yasmi
 */

#ifndef MCAL_PWM_PWM_CONFIG_H_
#define MCAL_PWM_PWM_CONFIG_H_


#include "PWM_priv.h"

//MODES OF PWM
typedef enum
{
	Disconnected = 0,
	Inverting = 1,
	Non_Inverting = 2
}PWM_MODE;

//Prescaler va;ues
typedef enum
{
	PWM_No_Prescaling = 0 ,  //prescale 1
	PWM_8 = 1,
	PWM_64 = 2,
	PWM_256 = 3,
	PWM_1024 = 4
}PWM_PRESCALER;

#endif /* MCAL_PWM_PWM_CONFIG_H_ */
