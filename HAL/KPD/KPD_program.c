/*
 * KPD_program.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Saker
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "KPD_interface.h"

#include "KPD_config.h"
#include "KPD_private.h"

void KPD_voidInit()
{
	/* Activate Pull Up for rows, and initiate the columns with High */
	DIO_u8SetPortValue(KPD_PORT, DIO_ALL_PORT);
}
u8 KPD_u8GetPressedKey()
{
	u8 Local_u8KPDMappedArr[NUM_ROWS][NUM_COLS] = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}
	};

	u8 Local_u8Key = 255;
}
