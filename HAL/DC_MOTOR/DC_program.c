/*
 * DC_program.c
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



void DC_voidRotateCW()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_u8HIGH);
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_u8LOW);
}
void DC_voidRotateACW()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_u8LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_u8HIGH);
}
void DC_voidStop()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN1, DIO_u8LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT, DC_MOTOR_PIN2, DIO_u8LOW);
}

