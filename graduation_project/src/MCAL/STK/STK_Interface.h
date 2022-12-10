/*
 * STK_Interface.h
 *
 *  Created on: 22 Oct 2022
 *      Author: moham
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_

#define ENABLE 1
#define DISNABLE 0

void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32TimerTicks);
void STK_voidSetInterval_single(u32 Copy_u32TimerTicks , void (*fptr)(void));
void STK_voidSetInterval_periodic(u32 Copy_u32TimerTicks , void (*fptr)(void));
void STK_voidStopInterval(void);
u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);

#endif /* MCAL_STK_STK_INTERFACE_H_ */
