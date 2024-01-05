/*
 * main.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Saker
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "STEPPER_interface.h"



int main()
{

	DIO_voidInit();


	while(1)
	{
		STEPPER_voidRotateCW(360);
		STEPPER_voidRotateACW(360);
		STEPPER_voidRotateCW(90);
		STEPPER_voidRotateACW(90);
	}
}
