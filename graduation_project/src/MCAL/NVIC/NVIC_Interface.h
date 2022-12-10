/*
 * NVIC_Interface.h
 *
 *  Created on: 19 Oct 2022
 *      Author: moham
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

enum
{
	NVIC_WWDG ,
	NVIC_PVD ,
	NVIC_TAMPER ,
	NVIC_RTC ,
	NVIC_FLASH ,
	NVIC_RCC ,
	NVIC_EXTI0 ,
	NVIC_EXTI1 ,
	NVIC_EXTI2 ,
	NVIC_EXTI3 ,
	NVIC_EXTI4 ,
	NVIC_DMA1_C1 ,
	NVIC_DMA1_C2 ,
	NVIC_DMA1_C3 ,
	NVIC_DMA1_C4 ,
	NVIC_DMA1_C5 ,
	NVIC_DMA1_C6 ,
	NVIC_DMA1_C7 ,
	NVIC_ADC1_2 ,
	NVIC_USB_HP_CAN_TX ,
	NVIC_USB_LP_CAN_RX0 ,
	NVIC_CAN_RX1 ,
	NVIC_CAN_SCE ,
	NVIC_EXTI9_5 ,
	NVIC_TIM1_BRK ,
	NVIC_TIM1_UP ,
	NVIC_TIM1_TRG_COM ,
	NVIC_TIM1_CC ,
	NVIC_TIM2 ,
	NVIC_TIM3 ,
	NVIC_TIM4 ,
	NVIC_I2C1_EV ,
	NVIC_I2C1_ER ,
	NVIC_I2C2_EV ,
	NVIC_I2C2_ER ,
	NVIC_SPI1 ,
	NVIC_SPI2 ,
	NVIC_USART1 ,
	NVIC_USART2 ,
	NVIC_USART3 ,
	NVIC_EXTI15_10 ,
	NVIC_RTCALARM ,
	NVIC_USBWAKEUP ,
	NVIC_TIM8_BRK ,
	NVIC_TIM8_UP ,
	NVIC_TIM8_TRG_COM ,
	NVIC_TIM8_CC ,
	NVIC_ADC3 ,
	NVIC_FSMC ,
	NVIC_SDIO ,
	NVIC_TIM5 ,
	NVIC_SPI3 ,
	NVIC_UART4 ,
	NVIC_UART5 ,
	NVIC_TIM6 ,
	NVIC_TIM7 ,
	NVIC_DMA2_C1 ,
	NVIC_DMA2_C2 ,
	NVIC_DMA2_C3 ,
	NVIC_DMA2_C4_5
};

void NVIC_voidInit(void);
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptId);
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptId);

void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptId);
void NVIC_voidClrPendingFlag(u8 Copy_u8InterruptId);

u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptId);

void NVIC_voidSetSWPriority(u8 Copy_u8InterruptId , u8 Copy_u8Priority);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
