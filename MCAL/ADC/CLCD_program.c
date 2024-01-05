/*
 * CLCD_program.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Saker
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"



void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*  RS = 0 "Command" */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8LOW);

	/* RW = 0 "Write" */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8LOW);

	/* Send Command */
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	/* Enable */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8HIGH);
	/* Delay */
	_delay_ms(2);
	/* Disable */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8LOW);
}
void CLCD_voidSendCharacter(u8 Copy_u8Character)
{
	/*  RS = 1 "Command" */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8HIGH);

	/* RW = 0 "Write" */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8LOW);

	/* Send Command */
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Character);
	/* Enable */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8HIGH);
	/* Delay */
	_delay_ms(2);
	/* Disable */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8LOW);
}

void CLCD_voidInit()
{
	_delay_ms(40);
	/* Function Set (8 bits mode // 2 lines // 5 * 7 dots) */
	CLCD_voidSendCommand(0b00111000);
	/* Display on/off */
	CLCD_voidSendCommand(0b00001100);
	/* Display Clear */
	CLCD_voidSendCommand(0b00000001);
}

void CLCD_voidSendString(u8 * Copy_pcString)
{

	u8 Local_u8Iterator = 0;

	while(Copy_pcString[Local_u8Iterator] != '\0')
	{
		CLCD_voidSendCharacter(Copy_pcString[Local_u8Iterator]);
		Local_u8Iterator++;
	}


}

void CLCD_voidClearDisplay()
{
	CLCD_voidSendCommand(0b00000001);
}

void CLCD_voidMoveCursor(u8 Copy_u8x, u8 Copy_u8y)
{
	u8 Local_u8Address = Copy_u8x + (Copy_u8y * (0x40));
	SET_BIT(Local_u8Address,7);
	CLCD_voidSendCommand(Local_u8Address);
}

void CLCD_voidSendNum(u32 Copy_u32Num)
{
	u8 Local_u8Digits[10];
	u8 Local_u8Iterator = 0;
	while(Copy_u32Num != 0)
	{
		Local_u8Digits[Local_u8Iterator] = (Copy_u32Num % 10) + '0';
		Copy_u32Num /= 10;
		Local_u8Iterator++;
	}
	for(s8 i = Local_u8Iterator-1; i>=0; i--)
	{
		CLCD_voidSendCharacter(Local_u8Digits[i]);
	}
}




