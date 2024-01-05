/*
 * CLCD_interface.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Saker
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendCharacter(u8 Copy_u8Character);
void CLCD_voidInit();
void CLCD_voidSendString(u8 * Copy_pcString);
void CLCD_voidClearDisplay();
void CLCD_voidMoveCursor(u8 Copy_u8x, u8 Copy_u8y);
void CLCD_voidSendNum(u32 Copy_u32Num);

#endif /* CLCD_INTERFACE_H_ */
