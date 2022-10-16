 /******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.h
 *
 * Description: Header file for the AVR LM35 driver
 *
 * Author: Mohamed Ayman
 *
 *******************************************************************************/
#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_PIN 2
#define SENSOR_MAX_VOLT_VALUE 1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
