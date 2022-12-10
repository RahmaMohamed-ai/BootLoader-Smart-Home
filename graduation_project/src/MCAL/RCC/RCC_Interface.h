/***
 *      _____   _____ _____   _____ _   _ _______ ______ _____  ______      _____ ______   _
 *     |  __ \ / ____/ ____| |_   _| \ | |__   __|  ____|  __ \|  ____/\   / ____|  ____| | |
 *     | |__) | |   | |        | | |  \| |  | |  | |__  | |__) | |__ /  \ | |    | |__    | |__
 *     |  _  /| |   | |        | | | . ` |  | |  |  __| |  _  /|  __/ /\ \| |    |  __|   | '_ \
 *     | | \ \| |___| |____   _| |_| |\  |  | |  | |____| | \ \| | / ____ \ |____| |____ _| | | |
 *     |_|  \_\\_____\_____| |_____|_| \_|  |_|  |______|_|  \_\_|/_/    \_\_____|______(_)_| |_|
 *
 *  	Created on: 16/10/2022
 *      Author: Mohamed Assem
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB			0
#define RCC_APB2		1
#define RCC_APB1		2

#define 	RCC_CR_PLLRDY				25
#define 	RCC_CR_PLLON				24
#define 	RCC_CR_CSSON				19
#define 	RCC_CR_HSEBYP				18
#define 	RCC_CR_HSERDY				17
#define 	RCC_CR_HSEON				16
#define 	RCC_CR_HSICAL				8
#define 	RCC_CR_HSITRIM				3
#define 	RCC_CR_HSIRDY				1
#define 	RCC_CR_HSION				0

#define 	RCC_CFGR_MCO				24
#define 	RCC_CFGR_USBPRE				22
#define 	RCC_CFGR_PLLMUL				18
#define 	RCC_CFGR_PLLXTPRE			17
#define 	RCC_CFGR_PLLSRC				16
#define 	RCC_CFGR_ADCPRE				14
#define 	RCC_CFGR_PPRE2				11
#define 	RCC_CFGR_PPRE1				8
#define 	RCC_CFGR_HPRE				4
#define 	RCC_CFGR_SWS				2
#define 	RCC_CFGR_SW					0

#define 	RCC_CIR_CSSC				23
#define 	RCC_CIR_PLLRDYC				20
#define 	RCC_CIR_HSERDYC				19
#define 	RCC_CIR_HSIRDYC				18
#define 	RCC_CIR_LSERDYC				17
#define 	RCC_CIR_LSIRDYC				16
#define 	RCC_CIR_PLLRDYIE			12
#define 	RCC_CIR_HSERDYIE			11
#define 	RCC_CIR_HSIRDYIE			10
#define 	RCC_CIR_LSERDYIE			9
#define 	RCC_CIR_LSIRDYIE			8
#define 	RCC_CIR_CSSF				7
#define 	RCC_CIR_PLLRDYF				4
#define 	RCC_CIR_HSERDYF				3
#define 	RCC_CIR_HSIRDYF				2
#define 	RCC_CIR_LSERDYF				1
#define 	RCC_CIR_LSIRDYF				0

#define 	RCC_APB2RSTR_TIM11RST		21
#define 	RCC_APB2RSTR_TIM10RST		20
#define 	RCC_APB2RSTR_TIM9RST		19
#define 	RCC_APB2RSTR_ADC3RST		15
#define 	RCC_APB2RSTR_USART1RST		14
#define 	RCC_APB2RSTR_TIM8RST		13
#define 	RCC_APB2RSTR_SPI1RST		12
#define 	RCC_APB2RSTR_TIM1RST		11
#define 	RCC_APB2RSTR_ADC2RST		10
#define 	RCC_APB2RSTR_ADC1RST		9
#define 	RCC_APB2RSTR_IOPGRST		8
#define 	RCC_APB2RSTR_IOPFRST		7
#define 	RCC_APB2RSTR_IOPERST		6
#define 	RCC_APB2RSTR_IOPDRST		5
#define 	RCC_APB2RSTR_IOPCRST		4
#define 	RCC_APB2RSTR_IOPBRST		3
#define 	RCC_APB2RSTR_IOPARST		2
#define 	RCC_APB2RSTR_AFIORST		0

#define 	RCC_APB1RSTR_DACRST			29
#define 	RCC_APB1RSTR_PWRRST			28
#define 	RCC_APB1RSTR_BKPRST			27
#define 	RCC_APB1RSTR_CANRST			25
#define 	RCC_APB1RSTR_USBRST			23
#define 	RCC_APB1RSTR_I2C2RST		22
#define 	RCC_APB1RSTR_I2C1RST		21
#define 	RCC_APB1RSTR_UART5RST		20
#define 	RCC_APB1RSTR_UART4RST		19
#define 	RCC_APB1RSTR_USART3RST		18
#define 	RCC_APB1RSTR_USART2RST		17
#define 	RCC_APB1RSTR_SPI3RST		15
#define 	RCC_APB1RSTR_SPI2RST		14
#define 	RCC_APB1RSTR_WWDGRST		11
#define 	RCC_APB1RSTR_TIM14RST		8
#define 	RCC_APB1RSTR_TIM13RST		7
#define 	RCC_APB1RSTR_TIM12RST		6
#define 	RCC_APB1RSTR_TIM7RST		5
#define 	RCC_APB1RSTR_TIM6RST		4
#define 	RCC_APB1RSTR_TIM5RST		3
#define 	RCC_APB1RSTR_TIM4RST		2
#define 	RCC_APB1RSTR_TIM3RST		1
#define 	RCC_APB1RSTR_TIM2RST		0

#define 	RCC_AHBENR_SDIOEN			10
#define 	RCC_AHBENR_FSMCEN			8
#define 	RCC_AHBENR_CRCEN			6
#define 	RCC_AHBENR_FLITFEN			4
#define 	RCC_AHBENR_SRAMEN			2
#define 	RCC_AHBENR_DMA2EN			1
#define 	RCC_AHBENR_DMA1EN			0

#define 	RCC_APB2ENR_TIM11EN			21
#define 	RCC_APB2ENR_TIM10EN			20
#define 	RCC_APB2ENR_TIM9EN			19
#define 	RCC_APB2ENR_ADC3EN			15
#define 	RCC_APB2ENR_USART1EN		14
#define 	RCC_APB2ENR_TIM8EN			13
#define 	RCC_APB2ENR_SPI1EN			12
#define 	RCC_APB2ENR_TIM1EN			11
#define 	RCC_APB2ENR_ADC2EN			10
#define 	RCC_APB2ENR_ADC1EN			9
#define 	RCC_APB2ENR_IOPGEN			8
#define 	RCC_APB2ENR_IOPFEN			7
#define 	RCC_APB2ENR_IOPEEN			6
#define 	RCC_APB2ENR_IOPDEN			5
#define 	RCC_APB2ENR_IOPCEN			4
#define 	RCC_APB2ENR_IOPBEN			3
#define 	RCC_APB2ENR_IOPAEN			2
#define 	RCC_APB2ENR_AFIOEN			0

#define 	RCC_APB1ENR_DACEN			29
#define 	RCC_APB1ENR_PWREN			28
#define 	RCC_APB1ENR_BKPEN			27
#define 	RCC_APB1ENR_CANEN			25
#define 	RCC_APB1ENR_USBEN			23
#define 	RCC_APB1ENR_I2C2EN			22
#define 	RCC_APB1ENR_I2C1EN			21
#define 	RCC_APB1ENR_UART5EN			20
#define 	RCC_APB1ENR_UART4EN			19
#define 	RCC_APB1ENR_USART3EN		18
#define 	RCC_APB1ENR_USART2EN		17
#define 	RCC_APB1ENR_SPI3EN			15
#define 	RCC_APB1ENR_SPI2EN			14
#define 	RCC_APB1ENR_WWDGEN			11
#define 	RCC_APB1ENR_TIM14EN			8
#define 	RCC_APB1ENR_TIM13EN			7
#define 	RCC_APB1ENR_TIM12EN			6
#define 	RCC_APB1ENR_TIM7EN			5
#define 	RCC_APB1ENR_TIM6EN			4
#define 	RCC_APB1ENR_TIM5EN			3
#define 	RCC_APB1ENR_TIM4EN			2
#define 	RCC_APB1ENR_TIM3EN			1
#define 	RCC_APB1ENR_TIM2EN			0

#define		RCC_BDCR_BDRST				16
#define		RCC_BDCR_RTCEN				15
#define		RCC_BDCR_RTCSEL				8
#define		RCC_BDCR_LSEBYP				2
#define		RCC_BDCR_LSERDY				1
#define		RCC_BDCR_LSEON				0

#define		RCC_CSR_LPWRRSTF			31
#define		RCC_CSR_WWDGRSTF			30
#define		RCC_CSR_IWDGRSTF			29
#define		RCC_CSR_SFTRSTF				28
#define		RCC_CSR_PORRSTF				27
#define		RCC_CSR_PINRSTF				26
#define		RCC_CSR_RMVF				24
#define		RCC_CSR_LSIRDY				1
#define		RCC_CSR_LSION				0

void RCC_voidInit(void);
void RCC_voidEnableClock(u8 Copy_u8BussID , u16 Copy_u16PeripheralID);
void RCC_voidDisableClock(u8 Copy_u8BussID , u16 Copy_u16PeripheralID);

#endif /* RCC_INTERFACE_H_ */
