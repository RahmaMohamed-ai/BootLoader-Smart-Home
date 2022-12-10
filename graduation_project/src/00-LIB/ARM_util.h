/*
 * ARM_util.h
 *
 *  Created on: 17 Oct 2022
 *      Author: moham
 */

#ifndef ARM_UTIL_H_
#define ARM_UTIL_H_

//delay (d) in milli seconds 8MHZ
#define ARM_DELAY_MS(d)	\
		do{ \
			u32 i = 500 * d ; \
			while(i--){asm("nop");} \
		}while(0)

#endif /* ARM_UTIL_H_ */
