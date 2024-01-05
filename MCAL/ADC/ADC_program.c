/*
 * ADC_program.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Saker
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_config.h"


void ADC_voidInit()
{
	/* Select Reference Voltage */
#if (VREF == AREFF)
	{
		CLR_BIT(ADMUX, 7);
		CLR_BIT(ADMUX, 6);
	}
#elif (VREF == AVCC)
	{
		CLR_BIT(ADMUX, 7);
		SET_BIT(ADMUX, 6);
	}
#elif (VREF == INTERNAL_VOLTAGE)
	{
		SET_BIT(ADMUX, 7);
		SET_BIT(ADMUX, 6);
	}
#endif


	/* Select Adjustment    */
	CLR_BIT(ADMUX, 5);

	/* Select PreScalar */
	ADCSRA &= 0b11111000;
	ADCSRA |= PRESCALAR;

	/*  Enable ADC Peripheral */
	SET_BIT(ADCSRA, 7);
}
u16 ADC_u16ReadChannel(u8 Copy_u8Channel)
{

	/*   Select Channel  */

	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;

	/* Start Conversion */

	SET_BIT(ADCSRA, 6);

	/* Pooling on the Flag */

	while((GET_BIT(ADCSRA, 4)) !=1)
	{
		asm("NOP");
	}

	/* Clear Flag */

	SET_BIT(ADCSRA, 4);

	return ADC;



}
