/*
 * USART_register.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Saker
 */

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_


#define 	UDR				*((volatile u8*)(0x2C))
#define 	UCSRA			*((volatile u8*)(0x2B))
#define 	UCSRB			*((volatile u8*)(0x2A))
#define 	UCSRC			*((volatile u8*)(0x40))
#define 	UBRRL			*((volatile u8*)(0x29))


#endif /* USART_REGISTER_H_ */
