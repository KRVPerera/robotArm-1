/*
 * Robot_arm_atmega_2560.c
 *
 * Created: 10/3/2014 2:52:44 PM
 *  Author: Buddhika Jayawardhana
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#include "ConvensionDefine.h"//file including order is important
#include "PinDefine.h"
#include "Motor.h"
#include "MotorDeclaration.h"
#include "MotorFunctions.h"
#include "InterruptServiceRoutunes.h"


/* THE LOGIC
*The Motor structure defines the attributes
of a Motor.
*Seven Motor structures for seven motors.
*Commands and Interrupts change the attribute of each Motor
*Poll function then make the decision by looking at each Motor structure
*/

int main(void){
	struct Motor MtestM;
	M0 = &MtestM;
	cli();
	pinSetup();
	initialize();
	motorObjectSetup(M0);
	M0->maxRevolutionsRight=50;
	M0->maxRevolutionsLeft = -50;
	M0->targetDirection = LEFT;
	M0->running = TRUE;
 	pollMotor(M0);
	 /*
  	PORTB |=(1<<PB7);
  	_delay_ms(500);
  	PORTB &= ~(1<<PB7);
  	_delay_ms(500);
  	PORTB |= (1<<PB7);
  	_delay_ms(500);
  	PORTB &= ~(1<<PB7);
  	_delay_ms(500);
	  */
	  sei();
	

	
	while(1){
		pollMotor(M0);

	}
	return 0;
	
}








