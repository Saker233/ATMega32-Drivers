/*
 * main.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Saker
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "USART_interface.h"





int main()
{

	u8 Local_u8Data = 0;
	DIO_voidInit();
	USART_voidInit();
//	DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0, DIO_u8HIGH);


	while(1)
	{
		Local_u8Data = USART_u8Receive();

		if(Local_u8Data == 'O')
		{
			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN4, DIO_u8HIGH);
		}
		else
		{
			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN4, DIO_u8LOW);
		}
//		if(GET_BIT(DIO_u8PORTA, 0) == 1)
//		{
//			USART_voidSendData('O');
//		}
//		else
//		{
//			USART_voidSendData('F');
//		}
	}
}
