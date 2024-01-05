/*
 * Timer_interface.h
 *
 *  Created on: Dec 19, 2023
 *      Author: ahmed
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER_voidInit(void);

void TIMER_voidSetIntervalSynchronous (u16 Copy_u16Counts);

void TIMER_voidOVSetIntervalASynchronous (u16 Copy_u16Counts, void (*PtrFunc)(void));

void TIMER_voidCOSetIntervalASynchronous (u16 Copy_u16Counts, void (*PtrFunc)(void));

void TIMER_voidSetCompareValue(u16 Copy_u16CompVal);

void TIMER_voidSetPreLoadValue(u16 Copy_u16PreLoadVal);

void TIMER_voidStart(void);

void TIMER_voidStop(void);

#endif /* TIMER_INTERFACE_H_ */
