/***
 *      _____   _____ _____    _____ ____  _   _ ______ _____ _____   _
 *     |  __ \ / ____/ ____|  / ____/ __ \| \ | |  ____|_   _/ ____| | |
 *     | |__) | |   | |      | |   | |  | |  \| | |__    | || |  __  | |__
 *     |  _  /| |   | |      | |   | |  | | . ` |  __|   | || | |_ | | '_ \
 *     | | \ \| |___| |____  | |___| |__| | |\  | |     _| || |__| |_| | | |
 *     |_|  \_\\_____\_____|  \_____\____/|_| \_|_|    |_____\_____(_)_| |_|
 *
 *  	Created on: 16/10/2022
 *      Author: Mohamed Assem
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*Clock control register (RCC_CR) - PLLON - PLL enable
 * PLL_DS -> Disable PLL
 * PLL_EN -> Enable PLL													*/
#define 	PLLON		PLL_DS

/*Clock control register (RCC_CR) - CSSON - Clock security system enable
 * CSS_OFF -> Clock detector OFF
 * CSS_ON -> Clock detector ON												*/
#define 	CSSON		CSS_OFF

/*Clock control register (RCC_CR) - HSEBYP - External high-speed clock bypass
 * HSE_NBP -> external 4-16 MHz oscillator not bypassed
 * HSE_BP -> external 4-16 MHz oscillator bypassed with external clock		*/
#define 	HSEBYP		HSE_NBP

/*Clock control register (RCC_CR) - HSEON - HSE clock enable
 * HSE_OFF -> HSE oscillator OFF
 * HSE_ON -> HSE oscillator ON												*/
#define 	HSEON		HSE_ON

/*Clock control register (RCC_CR) - HSION - Internal high-speed clock enable
 * HSI_OFF -> internal 8 MHz RC oscillator OFF
 * HSI_ON -> internal 8 MHz RC oscillator ON								*/
#define 	HSION		HSI_OFF

/*Clock configuration register (RCC_CFGR) - MCO - Microcontroller clock output
 *MCO_NO  - > No clock
 *MCO_SC  - > System clock (SYSCLK) selected
 *MCO_HSI - > HSI clock selected
 *MCO_HSE - > HSE clock selected
 *MCO_PLL - > PLL clock divided by 2 selected								*/
#define 	MCO			MCO_NO

/*Clock configuration register (RCC_CFGR) - USBPRE - USB prescaler
 * PLL_USB_DIV -> PLL clock is divided by 1.5
 * PLL_USB_NDIV -> PLL clock is not divided										*/
#define 	USBPRE		PLL_USB_DIV

/*Clock configuration register (RCC_CFGR) - PLLMUL - PLL multiplication factor
 *PLL_X2 -> PLL input clock x 2
 *PLL_X3 -> PLL input clock x 3
 *PLL_X4 -> PLL input clock x 4
 *PLL_X5 -> PLL input clock x 5
 *PLL_X6 -> PLL input clock x 6
 *PLL_X7 -> PLL input clock x 7
 *PLL_X8 -> PLL input clock x 8
 *PLL_X9 -> PLL input clock x 9
 *PLL_X10 -> PLL input clock x 10
 *PLL_X11 -> PLL input clock x 11
 *PLL_X12 -> PLL input clock x 12
 *PLL_X13 -> PLL input clock x 13
 *PLL_X14 -> PLL input clock x 14
 *PLL_X15 -> PLL input clock x 15
 *PLL_X16 -> PLL input clock x 16
 *PLL_X16 -> PLL input clock x 16 												*/
#define 	PLLMUL		PLL_X2

/*Clock configuration register (RCC_CFGR) - PLLXTPRE - HSE divider for PLL entry
 * PLL_HSE_NDIV -> HSE clock not divided
 * PLL_HSE_DIV -> HSE clock divided by 2										*/
#define 	PLLXTPRE	PLL_HSE_NDIV

/*Clock configuration register (RCC_CFGR) - PLLSRC - PLL entry clock source
 * PLL_HSI -> HSI oscillator clock / 2 selected as PLL input clock
 * PLL_HSE -> HSE oscillator clock selected as PLL input clock					*/
#define 	PLLSRC		PLL_HSI

/*Clock configuration register (RCC_CFGR) - ADCPRE - ADC prescaler
 *ADC_X2 -> PCLK2 divided by 2
 *ADC_X4 -> PCLK2 divided by 4
 *ADC_X6 -> PCLK2 divided by 6
 *ADC_X8 -> PCLK2 divided by 8 													*/
#define 	ADCPRE		ADC_X2

/*Clock configuration register (RCC_CFGR) - PPRE2 - APB high-speed prescaler (APB2)
 *APBH_N -> HCLK not divided
 *APBH_X2 -> HCLK divided by 2
 *APBH_X4 -> HCLK divided by 4
 *APBH_X8 -> HCLK divided by 8
 *APBH_X16 -> HCLK divided by 16												*/
#define 	PPRE2		APBH_N

/*Clock configuration register (RCC_CFGR) - PPRE1 - APB low-speed prescaler (APB1)
 *APBL_N -> HCLK not divided
 *APBL_X2 -> HCLK divided by 2
 *APBL_X4 -> HCLK divided by 4
 *APBL_X8 -> HCLK divided by 8
 *APBL_X16 -> HCLK divided by 16												*/
#define 	PPRE1		APBL_N

/*Clock configuration register (RCC_CFGR) - HPRE - AHB prescaler
 *AHB_N -> SYSCLK not divided
 *AHB_X2 -> SYSCLK divided by 2
 *AHB_X4 -> SYSCLK divided by 4
 *AHB_X8 -> SYSCLK divided by 8
 *AHB_X16 -> SYSCLK divided by 16
 *AHB_X64 -> SYSCLK divided by 64
 *AHB_X128 -> SYSCLK divided by 128
 *AHB_X256 -> SYSCLK divided by 256
 *AHB_X512 -> SYSCLK divided by 512												*/
#define 	HPRE		AHB_N

/*Clock configuration register (RCC_CFGR) - SW - System clock switch
 *SW_HSI -> HSI selected as system clock
 *SW_HSE -> HSE selected as system clock
 *SW_PLL -> PLL selected as system clock
 *SW_NO -> not allowed														*/
#define 	SW			SW_HSE

#endif /* RCC_CONFIG_H_ */
