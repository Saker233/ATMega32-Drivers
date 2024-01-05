/*
 * EXTI0_interface.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Saker
 */

#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_


#define		LOW_LEVEL				1
#define		ANY_CHANGE				2
#define		FALLING_EDGE			3
#define		RISING_EDGE				4



void EXTI0_voidInit();
void EXTI0_voidEnable();
void EXTI0_voidDisable();
void EXITI0_voidSetSenseControl(u8 Copy_u8Sense);
void EXTI0_voidSetCallBack(void (*Copy_pvCallback)(void));


#endif /* EXTI0_INTERFACE_H_ */
