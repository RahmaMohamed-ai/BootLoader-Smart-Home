/*
 * STK_Private.h
 *
 *  Created on: 22 Oct 2022
 *      Author: moham
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

#define 	STK_BASE_ADDRESS				0xE000E010

typedef struct
{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
	volatile u32 CALIB ;
}STK_MemMap_t;

#define 	STK		((volatile STK_MemMap_t*)(STK_BASE_ADDRESS))




#endif /* MCAL_STK_STK_PRIVATE_H_ */
