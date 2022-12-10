/***
 *      _____   _____ _____   _____  _____  _______      __  _______ ______   _
 *     |  __ \ / ____/ ____| |  __ \|  __ \|_   _\ \    / /\|__   __|  ____| | |
 *     | |__) | |   | |      | |__) | |__) | | |  \ \  / /  \  | |  | |__    | |__
 *     |  _  /| |   | |      |  ___/|  _  /  | |   \ \/ / /\ \ | |  |  __|   | '_ \
 *     | | \ \| |___| |____  | |    | | \ \ _| |_   \  / ____ \| |  | |____ _| | | |
 *     |_|  \_\\_____\_____| |_|    |_|  \_\_____|   \/_/    \_\_|  |______(_)_| |_|
 *
 *  	Created on: 16/10/2022
 *      Author: Mohamed Assem
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#define 	RCC_BASE_ADDR				0x40021000

#define		PLL_DS						0
#define		PLL_EN						1
						
#define		CSS_OFF						0
#define		CSS_ON						1
						
#define		HSE_NBP						0
#define		HSE_BP						1
						
#define		HSE_OFF						0
#define		HSE_ON						1

#define		HSI_OFF						0
#define		HSI_ON						1
						
#define		MCO_NO						0b000
#define		MCO_SC						0b100
#define		MCO_HSI						0b101
#define		MCO_HSE						0b110
#define		MCO_PLL						0b111
						
#define		PLL_USB_DIV					0
#define		PLL_USB_NDIV				1
						
#define		PLL_X2						0b0000
#define		PLL_X3						0b0001
#define		PLL_X4						0b0010
#define		PLL_X5						0b0011
#define		PLL_X6						0b0100
#define		PLL_X7						0b0101
#define		PLL_X8						0b0110
#define		PLL_X9						0b0111
#define		PLL_X10						0b1000
#define		PLL_X11						0b1001
#define		PLL_X12						0b1010
#define		PLL_X13						0b1011
#define		PLL_X14						0b1100
#define		PLL_X15						0b1101
#define		PLL_X16						0b1110
#define		PLL_X16						0b1111
						
#define		PLL_HSE_NDIV				0	
#define		PLL_HSE_DIV					1
						
#define		PLL_HSI						0
#define		PLL_HSE						1
						
#define		ADC_X2						0b00
#define		ADC_X4						0b01
#define		ADC_X6						0b10
#define		ADC_X8						0b11
						
#define		APBH_N						0b000
#define		APBH_X2						0b100
#define		APBH_X4						0b101
#define		APBH_X8						0b110
#define		APBH_X16					0b111

#define		APBL_N						0b000
#define		APBL_X2						0b100
#define		APBL_X4						0b101
#define		APBL_X8						0b110
#define		APBL_X16					0b111
						
#define		AHB_N						0b0000
#define		AHB_X2						0b1000
#define		AHB_X4						0b1001
#define		AHB_X8						0b1010
#define		AHB_X16 					0b1011	
#define		AHB_X64 					0b1100	
#define		AHB_X128					0b1101	
#define		AHB_X256					0b1110	
#define		AHB_X512					0b1111	
						
#define		SW_HSI						0b00
#define		SW_HSE						0b01
#define		SW_PLL						0b10
#define		SW_NO						0b11

#define 	RCC_CR 			*((volatile u32*)(RCC_BASE_ADDR + 0x00))
#define 	RCC_CFGR 		*((volatile u32*)(RCC_BASE_ADDR + 0x04))
#define 	RCC_CIR 		*((volatile u32*)(RCC_BASE_ADDR + 0x08))
#define 	RCC_APB2RSTR 	*((volatile u32*)(RCC_BASE_ADDR + 0x0C))
#define 	RCC_APB1RSTR 	*((volatile u32*)(RCC_BASE_ADDR + 0x10))
#define 	RCC_AHBENR 		*((volatile u32*)(RCC_BASE_ADDR + 0x14))
#define 	RCC_APB2ENR 	*((volatile u32*)(RCC_BASE_ADDR + 0x18))
#define 	RCC_APB1ENR 	*((volatile u32*)(RCC_BASE_ADDR + 0x1C))
#define 	RCC_BDCR 		*((volatile u32*)(RCC_BASE_ADDR + 0x20))
#define 	RCC_CSR 		*((volatile u32*)(RCC_BASE_ADDR + 0x24))

#endif /* RCC_PRIVATE_H_ */
