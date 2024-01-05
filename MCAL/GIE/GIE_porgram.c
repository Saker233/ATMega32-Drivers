/*
 * GIE_porgram.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Saker
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_config.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_register.h"


void GIE_voidEnable()
{
	SET_BIT(SREG, 7);
}
void GIE_voidDisbale()
{
	CLR_BIT(SREG, 7);
}
