/*
 * Timer_program.c
 *
 *  Created on: Dec 19, 2023
 *      Author: ahmed
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*Timer */
#include "Timer_register.h"
#include "Timer_config.h"
#include "Timer_private.h"
#include "Timer_interface.h"

void (*Global_OVPtrFunc)(void) = NULL;
void (*Global_COMPPtrFunc)(void) = NULL;
u16 G_u16OVCounts;
u16 G_u16CompCounts;
/**
 *      void TIMER_voidInit(void)
 *      1- This function to initialize the timer
 *      2- return -> void
 *      3- Arguments -> void
 *
 */

void TIMER_voidInit(void)
{

#if (TIMER_COUNTER_MODE == TIMER)
	/* Masking the Timer mode and if the timer mode normal only masing is enoug  */
	TCCR0 &= 0xB7;
	TCCR0 |=TIMER_MODE;

	#if (TIMER_MODE == CTC)
		/*Setting the CTC pin to work with compare mode */
		TCCR0 &=0xCF;
		TCCR0 |=CTC_PIN;

	#elif (TIMER_MODE == FAST_PWM)
		/*Setting the CTC pin to work with Fast-PWM mode (Non-Inverting or Inverting) */
		TCCR0 &=0xCF;
		TCCR0 |=PWM_MODE;

	#elif (TIMER_MODE == PHASE_PWM)
		/*Setting the CTC pin to work with Phase-PWM mode (Non-Inverting or Inverting) */
		TCCR0 &=0xCF;
		TCCR0 |=PWM_MODE;

	#endif

#elif (TIMER_COUNTER_MODE == COUNTER)
	/*Setting the Counter Sense either with the falling or rising edge */
	TCCR0 &= 0xF8;
	TCCR0 |= COUNTER_SENSE;


#endif


}

/* void TIMER_voidSetIntervalSynchronous (u16 Copy_u16Counts)
 *       1- This function to make busy delay by the timer
 *       2- return -> void
 *       3- Arguments -> Copy_u16Counts
 *       (the number of counts needed after calculating the Tick Time, Total Time )
 * 		Tick Time = PreScaler/F_CPU
 * 		Total Time = Tick Time * Resolution of timer  (TOP+1 in case of Timer1)    (2^(8)=256)
 * 		Number of Counts = Required Time / Total Time
 **/



void TIMER_voidSetIntervalSynchronous (u16 Copy_u16Counts)
{

	for (u16 Local_u16Iterator = 0;Local_u16Iterator<Copy_u16Counts;Local_u16Iterator++ )
	{
		while (GET_BIT(TIFR,TIFR_TOV0) !=1);
		SET_BIT(TIFR,TIFR_TOV0);
	}

}

/* void TIMER_voidOVSetIntervalASynchronous (u16 Copy_u16Counts)
 *       1- This function to make OV timer works with interrupts using Callback
 *       2- return -> void
 *       3- Arguments -> Copy_u16Counts
 *       (the number of counts needed after calculating the Tick Time, Total Time )
 * 			Tick Time = PreScaler/F_CPU
 * 			Total Time = Tick Time * Resolution of timer  (TOP+1 in case of Timer1)    (2^(8)=256)
 * 			Number of Counts = Required Time / Total Time
 **/


void TIMER_voidOVSetIntervalASynchronous (u16 Copy_u16Counts, void (*PtrFunc)(void))
{
	SET_BIT(TMISK,TMISK_TOIE0);
	Global_OVPtrFunc = PtrFunc;
	G_u16OVCounts    = Copy_u16Counts;

}

/* void TIMER_voidCOSetIntervalASynchronous (u16 Copy_u16Counts)
 *       1- This function to make COMP timer works with interrupts using Callback
 *       2- return -> void
 *       3- Arguments -> Copy_u16Counts
 *       (the number of counts needed after calculating the Tick Time, Total Time )
 * 			Tick Time = PreScaler/F_CPU
 * 			Total Time = Tick Time * Resolution of timer  (TOP+1 in case of Timer1)    (2^(8)=256)
 * 			Number of Counts = Required Time / Total Time
 **/

void TIMER_voidCOSetIntervalASynchronous (u16 Copy_u16Counts, void (*PtrFunc)(void))
{
	SET_BIT(TMISK,TIFR_TOV0);
	Global_COMPPtrFunc = PtrFunc;
	G_u16CompCounts    = Copy_u16Counts;

}


/* void TIMER_voidSetCompareValue(u16 Copy_u16CompVal)
 *       1- This function to put a value in the compare register in order for compare match
 *       2- return -> void
 *       3- Arguments -> Copy_u16CompVal (the value needed to compare match)
 *
 **/

void TIMER_voidSetCompareValue(u16 Copy_u16CompVal)
{

	OCR0 = Copy_u16CompVal;

}
/* void TIMER_voidSetPreLoadValue(u16 Copy_u16PreLoadVal)
 *       1- This function to preload timer  register in order to achieve a specific time ov
 *       2- return -> void
 *       3- Arguments -> Copy_u16PreLoadVal (the value needed to be preloaded)
 *
 **/

void TIMER_voidSetPreLoadValue(u16 Copy_u16PreLoadVal)
{

	TCNT0 = Copy_u16PreLoadVal;

}

/* void TIMER_voidSetPreLoadValue(u16 Copy_u16PreLoadVal)
 *       1- This function to start the timer according to the PreScaler identified
 *       2- return -> void
 *       3- Arguments -> void
 *
 **/

void TIMER_voidStart(void)
{

	TCCR0&=0xF8;
	TCCR0|= TIMER_PRESCALER;

}

/* void TIMER_voidSetPreLoadValue(u16 Copy_u16PreLoadVal)
 *       1- This function to stop the timer
 *       2- return -> void
 *       3- Arguments -> void
 *
 **/
void TIMER_voidStop(void)
{
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

}

/* ISR for OV Timer */
void __vector_11 (void) __attribute__ ((signal));

void __vector_11 (void)
{
	static u16 LS_Iterator = 0;
	LS_Iterator++;
	if (LS_Iterator == G_u16OVCounts )
	{
		Global_OVPtrFunc();
		LS_Iterator = 0;
	}


}

/* ISR for COMP Timer */
void __vector_12 (void) __attribute__ ((signal));

void __vector_12 (void)
{
	static u16 LS_Iterator = 0;
	LS_Iterator++;
	if (LS_Iterator == G_u16CompCounts )
	{
		Global_COMPPtrFunc();
		LS_Iterator = 0;
	}


}



