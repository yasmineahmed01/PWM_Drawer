 # Input Capture Unit 
 TIMER1 is a hardware timer module available on the ATmega32 microcontroller. 
 The ICU TIMER1 is an input capture module that can be used to capture the value of an external signal at a specific time or interval. It provides a way to measure the frequency, period, or duty cycle of an incoming signal 
 
# Measuring pulse width
We can use the following steps to measure the pulse width of a wave.
1. Initialize TCCR1A and TCCRIB, and select capturing on rising edge.
2. Initialize ACSR to select the desired event source.
3. Monitor the ICF1 flag in TIFR to see if the edge has arrived. Upon the arrival of the edge, the TCNT1 value is loaded into the ICR1 register automatically by the AVR.
4. Save the ICRI and change the capturing edge to the falling edge.
5. Monitor the ICF1 flag in TIFR to see if the second edge has arrived.
Upon the arrival of the edge, the TCNT value is loaded into the ICR1 register automatically by the AVR.
6. Save the ICR1 for the second edge. Subtract the second edge value from

# Measuring period
We can use the following steps to measure the period of a wave.
1. Initialize the TCCRIA and TCCR1B.
2. Initialize the ACSR to select the desired event source.
3. Monitor the ICF1 flag in TIF to see if the edge has arrived. Upon the arrival of the edge, the TCNT1 is loaded into the ICR1 register automatically by the AVR.
4. Save the ICR1.
5. Monitor the ICF1 flag in TIF to see if the second edge has arrived.
Upon the arrival of the edge, the TCNT is loaded into the ICR1 register automatically by the AVR.
6. Save the ICR1 for the second edge. By subtracting the second edge value
