/*
 * USART_interface.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Saker
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit();
void USART_voidSendData(u8 Copy_u8Data);
u8 USART_u8Receive(void);

#endif /* USART_INTERFACE_H_ */
