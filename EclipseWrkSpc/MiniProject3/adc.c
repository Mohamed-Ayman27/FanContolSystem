/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Mohamed Ayman
 *
 *******************************************************************************/



#include <avr/io.h>
#include <avr/interrupt.h>
#include "adc.h"

volatile uint16 g_ADCresult=0;

ISR(ADC_vect)
{
	g_ADCresult=ADC;
}

void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = choose to connect reference voltage
	 * ADLAR   = choose which adjustment
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (ADMUX & (0X3F)) | ((Config_Ptr->VoltRef)<<6);

	ADMUX = (ADMUX & (0XCF)) | ((Config_Ptr->Adjust)<<5);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = Chosen from the user
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = User Defined
	 */
	ADCSRA = (1<<ADEN);

	ADCSRA = (ADCSRA & (0XF8)) | (Config_Ptr->PreScale);


#if ADC_DESIGN == 1

	ADCSRA &= ~(1<<ADIE);

#elif ADC_DESIGN == 2

	ADCSRA |= (1<<ADIE);

#endif




}

#if ADC_DESIGN == 1

uint16 ADC_readChannel(uint8 Ch_num) //(Ch_num 0:7)
{
	/*Insert Channel num in ADMUX*/
	ADMUX = (ADMUX &(0xE0)) | (Ch_num & (0x07));

	/*Start Conv*/
	SET_BIT(ADCSRA,ADSC);

	/*Polling*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/*Clear Flag*/
	SET_BIT(ADCSRA,ADIF);


	return ADC;

}
#elif ADC_DESIGN == 2

void ADC_readChannel(uint8 Ch_num)
{
	SREG|=(1<<7);
	/*Insert Channel num in ADMUX*/
	ADMUX = (ADMUX &(0xE0)) | (Ch_num & (0x07));

	/*Start Conv*/
	SET_BIT(ADCSRA,ADSC);

}

#endif
