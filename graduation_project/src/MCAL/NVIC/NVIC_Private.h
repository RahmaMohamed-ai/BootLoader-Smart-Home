/*
 * NVIC_Private.h
 *
 *  Created on: 19 Oct 2022
 *      Author: moham
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

/*SCB Private*/

#define SCB_NVIC_G16S0			0x05FA0300
#define SCB_NVIC_G8S2			0x05FA0400
#define SCB_NVIC_G4S4			0x05FA0500
#define SCB_NVIC_G2S8			0x05FA0600
#define SCB_NVIC_G0S16			0x05FA0700


/***********************/


#define NVIC_BASE_ADDRESS					0xE000E100

#define NVIC_REG32_DEF(offset)				*((volatile u32*)(NVIC_BASE_ADDRESS + offset))

#define NVIC_ISER0							NVIC_REG32_DEF(0x000)
#define NVIC_ISER1							NVIC_REG32_DEF(0x004)
#define NVIC_ISER2							NVIC_REG32_DEF(0x008)

#define NVIC_ICER0							NVIC_REG32_DEF(0x080)
#define NVIC_ICER1							NVIC_REG32_DEF(0x084)
#define NVIC_ICER2							NVIC_REG32_DEF(0x088)

#define NVIC_ISPR0							NVIC_REG32_DEF(0x100)
#define NVIC_ISPR1							NVIC_REG32_DEF(0x104)
#define NVIC_ISPR2							NVIC_REG32_DEF(0x108)

#define NVIC_ICPR0							NVIC_REG32_DEF(0x180)
#define NVIC_ICPR1							NVIC_REG32_DEF(0x184)
#define NVIC_ICPR2							NVIC_REG32_DEF(0x188)

#define NVIC_IABR0							NVIC_REG32_DEF(0x200)
#define NVIC_IABR1							NVIC_REG32_DEF(0x204)
#define NVIC_IABR2							NVIC_REG32_DEF(0x208)

#define NVIC_IPR							((volatile u8*)(NVIC_BASE_ADDRESS + 0x300))

#define NVIC_STIR							NVIC_REG32_DEF(0xE00)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
