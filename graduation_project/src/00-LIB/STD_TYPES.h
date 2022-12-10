/***
 *       _____ _______ _____    _________     _______  ______  _____  _
 *      / ____|__   __|  __ \  |__   __\ \   / /  __ \|  ____|/ ____|| |
 *     | (___    | |  | |  | |    | |   \ \_/ /| |__) | |__  | (___  | |__
 *      \___ \   | |  | |  | |    | |    \   / |  ___/|  __|  \___ \ | '_ \
 *      ____) |  | |  | |__| |    | |     | |  | |    | |____ ____) || | | |
 *     |_____/   |_|  |_____/     |_|     |_|  |_|    |______|_____(_)_| |_|
 *
 *  	Created on: 16/10/2022
 *      Author: Mohamed Assem
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char 		u8 	;
typedef unsigned short 		u16	;
typedef unsigned long int 	u32 ;
typedef unsigned long long 	u64 ;

typedef signed char 		s8	;
typedef signed short 		s16 ;
typedef signed long int  	s32 ;
typedef signed long long  	s64 ;

typedef float  				f32	;
typedef double 				f64 ;
typedef long double 		f128;

#ifndef NULL
#define NULL ((void*)0)
#endif

#endif
