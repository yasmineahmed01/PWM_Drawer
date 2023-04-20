/*
 * PWM_prog.c
 *
 *  Created on: Apr 9, 2023
 *      Author: yasmi
 */


#include "PWM_int.h"
#include "PWM_config.h"


#define BITS 256

void PWM_Init(void)
{
	//Define direction of 0C2 as output
	SET_BIT(DDRD, PD7);

	//generate a fast PWM signal
	SET_BIT(TCCR2, WGM00);
	SET_BIT(TCCR2, WGM01);
}

void PWM_Start(PWM_PRESCALER prescaler)
{
	switch(prescaler)
	{
		case PWM_No_Prescaling:
		SET_BIT(TCCR2, CS00);
		CLR_BIT(TCCR2, CS01);
		CLR_BIT(TCCR2, CS02);
		break;
		case PWM_8:
		CLR_BIT(TCCR2, CS00);
		SET_BIT(TCCR2, CS01);
		CLR_BIT(TCCR2, CS02);
		break;
		case PWM_64:
		SET_BIT(TCCR2, CS00);
		SET_BIT(TCCR2, CS01);
		CLR_BIT(TCCR2, CS02);
		break;
		case PWM_256:
		CLR_BIT(TCCR2, CS00);
		CLR_BIT(TCCR2, CS01);
		SET_BIT(TCCR2, CS02);
		break;
		case PWM_1024:
		SET_BIT(TCCR2, CS00);
		CLR_BIT(TCCR2, CS01);
		SET_BIT(TCCR2, CS02);
	}
}

void PWM_Stop(void)
{
	//stop the signal by choosing prescaler 0
	CLR_BIT(TCCR2, CS00);
	CLR_BIT(TCCR2, CS01);
	CLR_BIT(TCCR2, CS02);
}

void PWM_SetDuty (PWM_MODE mode, uint8_t dutyCycle)
{
	//choosing the mode
	switch(mode)
	{
		case Disconnected:
		CLR_BIT(TCCR2, COM00);
		CLR_BIT(TCCR2, COM01);
		OCR2 = 0;
		break;

		//Setting the OCR2 depending on the duty cycle (from Mazidi ref)
		case Inverting:
		SET_BIT(TCCR2, COM00);
		SET_BIT(TCCR2, COM01);
		OCR2 = (BITS - 1) - ((BITS * dutyCycle) / 100) - 1;
		break;
		case Non_Inverting:
		CLR_BIT(TCCR2, COM00);
		SET_BIT(TCCR2, COM01);
		OCR2 = ((BITS * dutyCycle) / 100) - 1;
	}

}
