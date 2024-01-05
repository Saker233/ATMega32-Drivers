/*
 * Timer_config.h
 *
 *  Created on: Dec 19, 2023
 *      Author: ahmed
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/* Timer mode -> Timer, Counter
 * Timer -> Normal, CTC, FAST-PWM, PHASE-PWM
 * PreScaler -> SCALER/8, SCALER/64, SCALER/128 , SCALER/256, SCALER/1024
 * CTC Pin -> Toggle, clear, set
 * Counter -> Rising Edge, Falling Edge
 * PWM_MODE -> Inverting, Non-Inverting
 *
 * */

#define TIMER_COUNTER_MODE          TIMER
#define TIMER_MODE                  NORMAL
#define TIMER_PRESCALER             PreScaler_8
#define CTC_PIN					    CTC_DISABLE
#define PWM_MODE                    NON_INVERTING
#define COUNTER_SENSE               COUNTER_SENSE_DISABLE

#endif /* TIMER_CONFIG_H_ */
