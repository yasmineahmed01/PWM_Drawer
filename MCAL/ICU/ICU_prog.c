/*
 * ICU_prog.c
 *
 *  Created on: Apr 9, 2023
 *      Author: yasmi
 */

#include "ICU_int.h"

#define F_CPU 16000000

void ICU_Measure(uint16_t* frequency,uint16_t* duty_cycle){

		///////////////////////////////////////////////
		///////////// Input Capture Unit///////////////
		///////////////////////////////////////////////
		///Using ICU (TIMER1) to measure the signal////
		///////////////////////////////////////////////
		// Start The Timer1
		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);  	// Clear ICF (Input Capture flag) flag

		TCCR1B = 0x41;  	// Trigger at Rising edge, no prescaler
		while ((TIFR&(1<<ICF1)) == 0); //poling on the flag
		uint16_t R1 = ICR1;  		// Take value of capture register
		TIFR = (1<<ICF1);  	// Clear ICF flag */

		TCCR1B = 0x01;  	// Trigger at Rising edge, no prescaler
		while ((TIFR&(1<<ICF1)) == 0);//poling on the flag
		uint16_t R2 = ICR1;  		// Take value of capture register
		TIFR = (1<<ICF1);  	// Clear ICF flag

		TCCR1B = 0x41;  	// Trigger at Rising edge, no prescaler
		while ((TIFR&(1<<ICF1)) == 0);//poling on the flag
		uint16_t R3 = ICR1;  		// Take value of capture register
		TIFR = (1<<ICF1);  	// Clear ICF flag

		TCCR1B = 0;  		// Stop the timer

		if(R1 < R2 && R2 < R3)  	// Check for valid condition, to avoid timer overflow reading
		{

			//period is calculated from the start time and end time
			uint16_t period = R3 - R1;

			// Calculate frequency
			*frequency = F_CPU / period;

			// Calculate duty cycle from the first rising to the first falling
			*duty_cycle = ((R2 - R1) * 100 ) / period;


		}
}
