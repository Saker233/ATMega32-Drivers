/*
 * EXTI0_program.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Saker
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI0_interface.h"
#include "EXTI0_register.h"
#include "EXTI0_config.h"
#include "EXTI0_private.h"


static void (*EXTI0_pvCallback)(void);

void EXTI0_voidInit()
{
#if(SENSE == LOW_LEVEL)
	CLR_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);

#elif(SENSE == ANY_CHANGE)
	CLR_BIT(MCUCR, 1);
	SET_BIT(MCUCR, 0);

#elif(SENSE == FALLING_EDGE)
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);

#elif(SENSE == RISING_EDGE)
	SET_BIT(MCUCR, 1);
	SET_BIT(MCUCR, 0);
#endif

	/* ENBALE EXTI0 */
	SET_BIT(GICR, 6);
}
void EXTI0_voidEnable()
{
	SET_BIT(GICR, 6);
}
void EXTI0_voidDisable()
{
	CLR_BIT(GICR, 6);
}
void EXITI0_voidSetSenseControl(u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL:
			CLR_BIT(MCUCR, 1);
			CLR_BIT(MCUCR, 0);
			break;
		case ANY_CHANGE:
			CLR_BIT(MCUCR, 1);
			SET_BIT(MCUCR, 0);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR, 1);
			CLR_BIT(MCUCR, 0);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, 1);
			SET_BIT(MCUCR, 0);
			break;
	}
}

void EXTI0_voidSetCallBack(void (*Copy_pvCallBack)(void))
{
	EXTI0_pvCallback = Copy_pvCallBack;
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI0_pvCallback != NULL)
	{
		EXTI0_pvCallback();
	}
	else
	{

	}
}











