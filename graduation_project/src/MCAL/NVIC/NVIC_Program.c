/*
 * NVIC_Program.c
 *
 *  Created on: 19 Oct 2022
 *      Author: moham
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

//#include "../../MCAL/SCB_Interface.h"

#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"


void NVIC_voidInit(void)
{
#define SCB_AIRCR	*((volatile u32*)(0xE000ED00 + 	0x0C))

	SCB_AIRCR = SCB_PRIORITY_GROUPING ;
}
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		SET_BIT(NVIC_ISER0 , Copy_u8InterruptId) ;
	}
	else if(Copy_u8InterruptId < 60)
	{
		SET_BIT(NVIC_ISER1 , Copy_u8InterruptId-32) ;
	}
}
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		SET_BIT(NVIC_ICER0 , Copy_u8InterruptId) ;
	}
	else if(Copy_u8InterruptId < 60)
	{
		SET_BIT(NVIC_ICER1 , Copy_u8InterruptId-32) ;
	}
}
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		SET_BIT(NVIC_ISPR0 , Copy_u8InterruptId) ;
	}
	else if(Copy_u8InterruptId < 60)
	{
		SET_BIT(NVIC_ISPR1 , Copy_u8InterruptId-32) ;
	}
}
void NVIC_voidClrPendingFlag(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		SET_BIT(NVIC_ICPR0 , Copy_u8InterruptId) ;
	}
	else if(Copy_u8InterruptId < 60)
	{
		SET_BIT(NVIC_ICPR1 , Copy_u8InterruptId-32) ;
	}
}
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptId)
{
	u8 L_u8Active = 0 ;
	if(Copy_u8InterruptId < 32)
	{
		L_u8Active = GET_BIT(NVIC_IABR0 , Copy_u8InterruptId) ;
	}
	else if(Copy_u8InterruptId < 60)
	{
		L_u8Active = GET_BIT(NVIC_IABR1 , Copy_u8InterruptId-32) ;
	}
	return L_u8Active ;
}
void NVIC_voidSetSWPriority(u8 Copy_u8InterruptId , u8 Copy_u8Priority)
{
	if(Copy_u8InterruptId < 60)
	{
		NVIC_IPR[Copy_u8InterruptId] &= ~(0b1111 << 4);
		NVIC_IPR[Copy_u8InterruptId] |= ~(Copy_u8Priority << 4);
	}
}
