/*
 * STK_Program.c
 *
 *  Created on: 22 Oct 2022
 *      Author: moham
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/ARM_util.h"
#include "../../00-LIB/BIT_MATH.h"

#include "STK_Interface.h"
#include "STK_Config.h"
#include "STK_Private.h"

static void (*STK_CallBack)(void);

static u8 single_flag = 0 ;

void STK_voidInit(void)
{
	/*clock sourse selection*/
	CLR_BIT(STK->CTRL , 2);
	/*interrupt enable disable*/
#if STK_INTERRUPT_ENABLE == ENABLE
	SET_BIT(STK->CTRL , 1);
#elif STK_INTERRUPT_ENABLE == DISNABLE
	CLR_BIT(STK->CTRL , 1);
#endif
}
void STK_voidSetBusyWait(u32 Copy_u32TimerTicks)
{
	/*clear timer value register*/
	STK->VAL = 0 ;
	/*reload the ticks timer in load register*/
	STK->LOAD = Copy_u32TimerTicks;
	/*start timer*/
	SET_BIT(STK->CTRL , 0);
	/*poll (wait on counterflag)*/
	while(GET_BIT(STK->CTRL , 16) != 1){}
	/*stop timer and clear counterflag*/
	CLR_BIT(STK->CTRL , 0);
	STK->VAL = 0 ;
}
void STK_voidSetInterval_single(u32 Copy_u32TimerTicks , void (*fptr)(void))
{
	single_flag = 1 ;
	/*register the call back func*/
	STK_CallBack = fptr ;
	/*clear timer value register*/
	STK->VAL = 0 ;
	/*reload the ticks timer in load register*/
	STK->LOAD = Copy_u32TimerTicks;
	/*start timer*/
	SET_BIT(STK->CTRL , 0);
}
void STK_voidSetInterval_periodic(u32 Copy_u32TimerTicks , void (*fptr)(void))
{
	single_flag = 0 ;
	/*register the call back func*/
	STK_CallBack = fptr ;
	/*clear timer value register*/
	STK->VAL = 0 ;
	/*reload the ticks timer in load register*/
	STK->LOAD = Copy_u32TimerTicks;
	/*start timer*/
	SET_BIT(STK->CTRL , 0);
}
void STK_voidStopInterval(void)
{
	SET_BIT(STK->CTRL , 0);
}
u32 STK_u32GetElapsedTime(void)
{
	return STK->LOAD - STK->VAL ;
}
u32 STK_u32GetRemainingTime(void)
{
	return STK->VAL ;
}

void SysTick_Handler(void)
{
	if(STK_CallBack != NULL)
	{
		if(single_flag)
		{
			single_flag = 0 ;
			STK->VAL = 0 ;
			CLR_BIT(STK->CTRL , 0 );
		}
		STK_CallBack();
	}
}
