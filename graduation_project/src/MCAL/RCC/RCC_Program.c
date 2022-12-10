/***
 *      _____   _____ _____   _____  _____   ____   _____ _____            __  __   _
 *     |  __ \ / ____/ ____| |  __ \|  __ \ / __ \ / ____|  __ \     /\   |  \/  | | |
 *     | |__) | |   | |      | |__) | |__) | |  | | |  __| |__) |   /  \  | \  / | | |__
 *     |  _  /| |   | |      |  ___/|  _  /| |  | | | |_ |  _  /   / /\ \ | |\/| | | '_ \
 *     | | \ \| |___| |____  | |    | | \ \| |__| | |__| | | \ \  / ____ \| |  | |_| | | |
 *     |_|  \_\\_____\_____| |_|    |_|  \_\\____/ \_____|_|  \_\/_/    \_\_|  |_(_)_| |_|
 *
 *  	Created on: 16/10/2022
 *      Author: Mohamed Assem
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

void RCC_voidInit(void)
{

#if 	PLLON == PLL_DS
	CLR_BIT(RCC_CR , RCC_CR_PLLON);
#elif 	PLLON == PLL_EN
	SET_BIT(RCC_CR , RCC_CR_PLLON);
#endif

#if 	CSSON == CSS_OFF
	CLR_BIT(RCC_CR , RCC_CR_CSSON);
#elif 	CSSON == CSS_ON
	SET_BIT(RCC_CR , RCC_CR_CSSON);
#endif

#if 	HSEBYP == HSE_NBP
	CLR_BIT(RCC_CR , RCC_CR_HSEBYP);
#elif 	HSEBYP == HSE_BP
	SET_BIT(RCC_CR , RCC_CR_HSEBYP);
#endif

#if 	HSEON == HSE_OFF
	CLR_BIT(RCC_CR , RCC_CR_HSEON);
#elif 	HSEON == HSE_ON
	SET_BIT(RCC_CR , RCC_CR_HSEON);
#endif

#if 	HSION == HSI_OFF
	CLR_BIT(RCC_CR , RCC_CR_HSION);
#elif 	HSION == HSI_ON
	SET_BIT(RCC_CR , RCC_CR_HSION);
#endif

	RCC_CFGR &= ~(0b111<<RCC_CFGR_MCO);
	RCC_CFGR |=  (MCO << RCC_CFGR_MCO);

#if 	USBPRE == PLL_USB_DIV
	CLR_BIT(RCC_CFGR , RCC_CFGR_USBPRE);
#elif 	USBPRE == PLL_USB_NDIV
	SET_BIT(RCC_CFGR , RCC_CFGR_USBPRE);
#endif

	RCC_CFGR &= ~(0b1111 << RCC_CFGR_PLLMUL);
	RCC_CFGR |=  (PLLMUL << RCC_CFGR_PLLMUL);

#if 	PLLXTPRE == PLL_HSE_NDIV
	CLR_BIT(RCC_CFGR , RCC_CFGR_PLLXTPRE);
#elif 	PLLXTPRE == PLL_HSE_DIV
	SET_BIT(RCC_CFGR , RCC_CFGR_PLLXTPRE);
#endif

#if 	PLLSRC == PLL_HSI
	CLR_BIT(RCC_CFGR , RCC_CFGR_PLLSRC);
#elif 	PLLSRC == PLL_HSE
	SET_BIT(RCC_CFGR , RCC_CFGR_PLLSRC);
#endif

	RCC_CFGR &= ~(0b11 << RCC_CFGR_ADCPRE);
	RCC_CFGR |=  (ADCPRE << RCC_CFGR_ADCPRE);

	RCC_CFGR &= ~(0b111<<RCC_CFGR_PPRE2);
	RCC_CFGR |=  (PPRE2 << RCC_CFGR_PPRE2);

	RCC_CFGR &= ~(0b111<<RCC_CFGR_PPRE1);
	RCC_CFGR |=  (PPRE1 << RCC_CFGR_PPRE1);

	RCC_CFGR &= ~(0b1111 << RCC_CFGR_HPRE);
	RCC_CFGR |=  (HPRE << RCC_CFGR_HPRE);

	RCC_CFGR &= ~(0b111<<RCC_CFGR_SW);
	RCC_CFGR |=  (SW << RCC_CFGR_SW);

/* Setting
 * /*HSE Settings
	//2- HSE BYPASS ?
	//1- HSE ON ?

	/*HSI Settings
	// HSI TRIM ?
	// HSI ON ?

	/*PLL Settings
	// PLLON ?
	// PLLSRC ? -> HSI/2 , HSE/2 , HSE ?
	// PLLMUL ? 2:16 but NOT EXCEED 72 MHZ

	/*Other Settings
	// CSS ON ?
	// MCO ?
	// AHB , APB1, APB2 Prescalers ?
	// ADC Prescaler

	/*System Clock Settings
	//SYSTEM CLOCK Switch bits : HSI/HSE/PLL*/

}

void RCC_voidEnableClock(u8 Copy_u8BussID , u16 Copy_u16PeripheralID)
{
	switch(Copy_u8BussID)
	{
	case RCC_AHB :
		SET_BIT(RCC_AHBENR , Copy_u16PeripheralID);
		break;
	case RCC_APB2 :
		SET_BIT(RCC_APB2ENR , Copy_u16PeripheralID);
		break;
	case RCC_APB1 :
		SET_BIT(RCC_APB1ENR , Copy_u16PeripheralID);
		break;
	}
}

void RCC_voidDisableClock(u8 Copy_u8BussID , u16 Copy_u16PeripheralID)
{
	switch(Copy_u8BussID)
	{
	case RCC_AHB :
		CLR_BIT(RCC_AHBENR , Copy_u16PeripheralID);
		break;
	case RCC_APB2 :
		CLR_BIT(RCC_APB2ENR , Copy_u16PeripheralID);
		break;
	case RCC_APB1 :
		CLR_BIT(RCC_APB1ENR , Copy_u16PeripheralID);
		break;
	}
}

