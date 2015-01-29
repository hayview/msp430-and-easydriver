/*
 * easydriver.h
 *
 *  Created on: Jan 13, 2015
 *      Author: hayview
 */

#ifndef EASYDRIVER_H_
#define EASYDRIVER_H_

#include <msp430.h>

/*
************************************************************
*                      CONSTANTS
************************************************************
*/
#define	MOTOR_A_DIR_PIN	 	BIT0
#define	MOTOR_A_STEP_PIN	BIT1
#define MOTOR_A_SLEEP_PIN  	BIT2
#define MOTOR_A_PINS		(MOTOR_A_DIR_PIN|MOTOR_A_STEP_PIN|MOTOR_A_SLEEP_PIN)
#define	MOTOR_B_DIR_PIN	 	BIT3
#define	MOTOR_B_STEP_PIN	BIT4
#define MOTOR_B_SLEEP_PIN  	BIT5
#define MOTOR_B_PINS		(MOTOR_B_DIR_PIN|MOTOR_B_STEP_PIN|MOTOR_B_SLEEP_PIN)
#define STEPS_PER_SECOND 	3200
#define MOTOR_SPEED		 	(16000000/STEPS_PER_SECOND)

/*
************************************************************
*                        MACROS
************************************************************
*/
#define MOTOR_A_INIT()	 	(P2DIR|=  MOTOR_A_PINS)
#define MOTOR_B_INIT()	 	(P2DIR|=  MOTOR_B_PINS)
#define MOTOR_A_SLEEP()	 	(P2OUT&= ~MOTOR_A_SLEEP_PIN)
#define MOTOR_B_SLEEP()	 	(P2OUT&= ~MOTOR_B_SLEEP_PIN)
#define MOTOR_A_WAKEUP()	(P2OUT|=  MOTOR_A_SLEEP_PIN)
#define MOTOR_B_WAKEUP()	(P2OUT|=  MOTOR_B_SLEEP_PIN)
#define MOTOR_A_CW()		(P2OUT&= ~MOTOR_A_DIR_PIN)
#define MOTOR_B_CW()		(P2OUT&= ~MOTOR_B_DIR_PIN)
#define MOTOR_A_ANTI_CW()	(P2OUT|=  MOTOR_A_DIR_PIN)
#define MOTOR_B_ANTI_CW()	(P2OUT|=  MOTOR_B_DIR_PIN)
#define MOTOR_A_STEP()	 	{P2OUT|=  MOTOR_A_STEP_PIN; P2OUT&=~MOTOR_A_STEP_PIN;}
#define MOTOR_B_STEP()	 	{P2OUT|=  MOTOR_B_STEP_PIN; P2OUT&=~MOTOR_B_STEP_PIN;}
#define MOTORS_INIT()	 	(P2DIR|= (MOTOR_A_PINS|MOTOR_B_PINS))
#define MOTORS_SLEEP()	 	(P2OUT&=~(MOTOR_A_SLEEP_PIN|MOTOR_B_SLEEP_PIN))
#define MOTORS_WAKEUP()	 	(P2OUT|= (MOTOR_A_SLEEP_PIN|MOTOR_B_SLEEP_PIN))
#define MOTORS_CW()	 		(P2OUT&=~(MOTOR_A_DIR_PIN|MOTOR_B_DIR_PIN))
#define MOTORS_ANTI_CW() 	(P2OUT|= (MOTOR_A_DIR_PIN|MOTOR_B_DIR_PIN))
#define MOTORS_STEP()	 	{P2OUT|= (MOTOR_A_STEP_PIN|MOTOR_B_STEP_PIN); P2OUT&=~(MOTOR_A_STEP_PIN|MOTOR_B_STEP_PIN);}

/*
************************************************************
*                 FUNCTIONS DECLARATION
************************************************************
*/
void motorAInit(void);
void motorBInit(void);
void motorARunCycles(int stepper_cycles);
void motorBRunCycles(int stepper_cycles);
void motorAGotoPosition(int stepper_degrees);
void motorBGotoPosition(int stepper_degrees);
void motorsInit(void);
void motorsRunCycles(int stepper_cycles);
void motorsGotoPosition(int stepper_degrees);

#endif /* EASYDRIVER_H_ */
