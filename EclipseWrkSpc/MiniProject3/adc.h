 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Mohamed Ayman
 *
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                         External                                   *
 *******************************************************************************/

#if ADC_DESIGN == 2

/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;

#endif

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
#define ADC_DESIGN 1

#if( (ADC_DESIGN!=1) && (ADC_DESIGN!=2))
#error "Please choose 1 for polling and 2 for interrupt design"
#endif



typedef enum
{
	AREF,AVCC,INTERNAL_2_56V=3
}ADC_voltageRef;

typedef enum
{
	RIGHT,LEFT
}ADC_leftAdjust;

typedef enum
{
	PRE_2=1, PRE_4, PRE_8, PRE_16, PRE_32, PRE_64, PRE_128
}ADC_prescaler;

typedef struct
{
	ADC_voltageRef VoltRef;
	ADC_prescaler PreScale;
	ADC_leftAdjust Adjust;
}ADC_ConfigType;




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType *Config_Ptr); // Initializes the ADC

#if ADC_DESIGN == 1

uint16 ADC_readChannel(uint8 Ch_num); //Reads the digital out from ADC

#elif ADC_DESIGN == 2

void ADC_readChannel(uint8 Ch_num); //Reads the digital out from ADC

#endif




#endif /* ADC_H_ */
