/*
 * DC_main.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Saker
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "DC_config.h"
#include "DC_interface.h"
#include "DC_private.h"



int main()
{
	DIO_u8SetPortDirection(DIO_u8PORTA, 0b00000011);
	DIO_u8SetPortDirection(DIO_u8PORTC, 0b00000000);
	DIO_u8SetPortDirection(DIO_u8PORTD, 0b00000000);
	DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8HIGH);

	u8 *Local_u8PORTCPIN = 0;
	u8 *Local_u8PORTDPIN = 0;

	while(1)
	{
		DIO_u8GetPinValue(DIO_u8PORTC, DIO_u8PIN0, &Local_u8PORTCPIN);
		DIO_u8GetPinValue(DIO_u8PORTD, DIO_u8PIN0, &Local_u8PORTDPIN);

		if((Local_u8PORTCPIN == 0b00000001) && (Local_u8PORTDPIN == 0b00000000))
		{
			DC_voidRotateCW();
		}
		else if((Local_u8PORTCPIN == 0b00000000) && (Local_u8PORTDPIN == 0b00000001))
		{
			DC_voidRotateACW();
		}
		else
		{
			DC_voidStop();
		}




	}
}
