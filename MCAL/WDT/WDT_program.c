/*
 * WDT_program.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Saker
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_interface.h"
#include "WDT_config.h"
#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_register.h"



void WDT_voidEnable()
{
	SET_BIT(WDTCR, 3);
}
void WDT_voidDisable()
{
	GIE_voidDisbale();
	WDTCR = (1<<4) | (1<<3);
	WDTCR = 0;
	GIE_voidEnable();
}
void WDT_voidSleep(u8 Copy_u8Time)
{
	WDTCR &= 0b11111000;
	WDTCR |= Copy_u8Time;
}
