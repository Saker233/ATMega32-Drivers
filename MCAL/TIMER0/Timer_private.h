/*
 * Timer_private.h
 *
 *  Created on: Dec 19, 2023
 *      Author: ahmed
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define NORMAL            0b00000000
#define CTC               0b00001000
#define FAST_PWM          0b01001000
#define PHASE_PWM         0b01000000


#define PreScaler_1       0b00000000
#define PreScaler_8       0b00000010
#define PreScaler_64      0b00000011
#define PreScaler_256     0b00000100
#define PreScaler_1024    0b00000101


#define CTC_DISABLE       0b00000000
#define CTC_TOGGLE        0b00010000
#define CTC_CLEAR         0b00100000
#define CTC_SET           0b00110000

#define INVERTING         0b00100000
#define NON_INVERTING     0b00110000

#define COUNTER_SENSE_DISABLE           0x00
#define COUNTER_SENSE_RISING            0x06
#define COUNTER_SENSE_FALLING           0x07


#endif /* TIMER_PRIVATE_H_ */
