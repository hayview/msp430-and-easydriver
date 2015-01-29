/*
 * easydriver.c
 *
 *  Created on: Jan 13, 2015
 *      Author: hayview
 */

#include "easydriver.h"

void motorAInit(void){
	MOTOR_A_INIT();
	MOTOR_A_SLEEP();
}

void motorBInit(void){
	MOTOR_B_INIT();
	MOTOR_B_SLEEP();
}

void motorsInit(void){
	MOTORS_INIT();
	MOTORS_SLEEP();
}

void motorARunCycles(int stepper_cycles)
{
	int step_counts;

	if (stepper_cycles<0){
		MOTOR_A_ANTI_CW();
		stepper_cycles=abs(stepper_cycles);
	}
	else{
		MOTOR_A_CW();
	}

	MOTOR_A_WAKEUP();

	while(stepper_cycles>0){
		for(step_counts=0;step_counts<=1600;step_counts++){
			MOTOR_A_STEP();
			_delay_cycles(MOTOR_SPEED);
		}
		stepper_cycles--;
	}

	MOTOR_A_SLEEP();
}

void motorBRunCycles(int stepper_cycles)
{
	int step_counts;

	if (stepper_cycles<0){
		MOTOR_A_ANTI_CW();
		stepper_cycles=abs(stepper_cycles);
	}
	else{
		MOTOR_B_CW();
	}

	MOTOR_B_WAKEUP();

	while(stepper_cycles>0){
		for(step_counts=0;step_counts<=1600;step_counts++){
			MOTOR_B_STEP();
			_delay_cycles(MOTOR_SPEED);
		}
		stepper_cycles--;
	}

	MOTOR_B_SLEEP();
}

void motorsRunCycles(int stepper_cycles)
{
	int step_counts;

	if (stepper_cycles<0){
		MOTORS_ANTI_CW();
		stepper_cycles=abs(stepper_cycles);
	}
	else{
		MOTORS_CW();
	}

	MOTORS_WAKEUP();

	while(stepper_cycles>0){
		for(step_counts=0;step_counts<=1600;step_counts++){
			MOTORS_STEP();
			_delay_cycles(MOTOR_SPEED);
		}
		stepper_cycles--;
	}

	MOTORS_SLEEP();
}

void motorAGotoPosition(int stepper_degrees)
{
	long step_degrees=1600;
	int step_counts;

	if(stepper_degrees<0){
		MOTOR_A_ANTI_CW();
		stepper_degrees=abs(stepper_degrees);
	}
	else{
		MOTOR_A_CW();
	}

	step_degrees=step_degrees*(long)stepper_degrees;
	step_degrees=step_degrees/360;
	step_counts=(int)step_degrees;

	MOTOR_A_WAKEUP();

	while(step_counts>0){
		MOTOR_A_STEP();
		_delay_cycles(MOTOR_SPEED);
		step_counts--;
	}

	MOTOR_A_SLEEP();
}

void motorBGotoPosition(int stepper_degrees)
{
	long step_degrees=1600;
	int step_counts;

	if(stepper_degrees<0){
		MOTOR_B_ANTI_CW();
		stepper_degrees=abs(stepper_degrees);
	}
	else{
		MOTOR_B_CW();
	}

	step_degrees=step_degrees*(long)stepper_degrees;
	step_degrees=step_degrees/360;
	step_counts=(int)step_degrees;

	MOTOR_B_WAKEUP();

	while(step_counts>0){
		MOTOR_B_STEP();
		_delay_cycles(MOTOR_SPEED);
		step_counts--;
	}

	MOTOR_B_SLEEP();
}

void motorsGotoPosition(int stepper_degrees)
{
	long step_degrees=1600;
	int step_counts;

	if(stepper_degrees<0){
		MOTORS_ANTI_CW();
		stepper_degrees=abs(stepper_degrees);
	}
	else{
		MOTORS_CW();
	}

	step_degrees=step_degrees*(long)stepper_degrees;
	step_degrees=step_degrees/360;
	step_counts=(int)step_degrees;

	MOTORS_WAKEUP();

	while(step_counts>0){
		MOTORS_STEP();
		_delay_cycles(MOTOR_SPEED);
		step_counts--;
	}

	MOTORS_SLEEP();
}