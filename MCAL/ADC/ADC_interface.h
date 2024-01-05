/*
 * ADC_interface.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Saker
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define CHANNEL_0				0
#define CHANNEL_1				1
#define CHANNEL_2				2
#define CHANNEL_3				3
#define CHANNEL_4				4
#define CHANNEL_5				5
#define CHANNEL_6				6
#define CHANNEL_7				7



void ADC_voidInit();
u16 ADC_u16ReadChannel(u8 Copy_u8Channel);




#endif /* ADC_INTERFACE_H_ */
