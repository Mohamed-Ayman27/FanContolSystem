
 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Mohamed Ayman
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#include "common_macros.h"
#include "adc.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MAX_PWM_VALUE 255


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* PWM_H_ */
