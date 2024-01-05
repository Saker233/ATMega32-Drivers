/*
 * main.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Saker
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "DIO_interface.h"
#include "WDT_interface.h"



int main()
{
	DIO_voidInit();
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8LOW);
	WDT_voidEnable();
	WDT_voidSleep(TIME_1s);

	_delay_ms(500);
	WDT_voidDisable();

	while(1)
	{

	}
}
