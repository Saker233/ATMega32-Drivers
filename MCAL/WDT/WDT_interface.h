/*
 * WDT_interface.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Saker
 */

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define 	TIME_16ms				0
#define 	TIME_32ms				1
#define 	TIME_65ms				2
#define 	TIME_130ms				3
#define 	TIME_260ms				4
#define 	TIME_520ms				5
#define 	TIME_1s					6
#define 	TIME_2s					7




void WDT_voidEnable();
void WDT_voidDisable();
void WDT_voidSleep(u8 Copy_u8Time);

#endif /* WDT_INTERFACE_H_ */
