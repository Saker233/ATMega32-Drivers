/*
 * USART_program.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Saker
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"
#include "USART_config.h"


void USART_voidInit()
{
	u8 Local_u8UCSRC = 0b10000110;
	/* Set Character Size */
	CLR_BIT(UCSRB, 2);
	SET_BIT(Local_u8UCSRC, 2);
	SET_BIT(Local_u8UCSRC, 1);

	/*	Select UCSRC */
	SET_BIT(Local_u8UCSRC, 7);

	/*	Select Mode Asynchronous*/
	CLR_BIT(Local_u8UCSRC, 6);

	/*	Selecting Type of Parity*/
	Local_u8UCSRC &= 0b11001111;
	Local_u8UCSRC |= PARITY;

	/*	Selecting Stop bit Numbers*/
	CLR_BIT(Local_u8UCSRC, 3);


	UCSRC = Local_u8UCSRC;

	/*	BAUD RATE = 9600*/
	UBRRL = 51;
	/* Enable Receiver and Transmitter */
	SET_BIT(UCSRB, 4);
	SET_BIT(UCSRB, 3);
}
void USART_voidSendData(u8 Copy_u8Data)
{
	/* CHeck if the data register is empty or not */
	while((GET_BIT(UCSRA, 5)) != 1)
	{
		asm("NOP");
	}
	/* Put the variable being sent in the register */
	UDR = Copy_u8Data;
}
u8 USART_u8Receive(void)
{

	while((GET_BIT(UCSRA, 7)) != 1)
	{
		asm("NOP");
	}

	return UDR;
}
