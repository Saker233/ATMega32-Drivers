/*
 * main.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Saker
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include <avr/delay.h>






int main()
{
	DIO_voidInit();
	ADC_voidInit();
	CLCD_voidInit();
	u16 reading;

	CLCD_voidSendCommand(1);
	while(1)
	{

		reading = ADC_u16ReadChannel(CHANNEL_0);
		reading *= 0.488;



		CLCD_voidSendNum(reading);
		_delay_ms(300);

		CLCD_voidSendCommand(1);
	}
}
