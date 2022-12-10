/*
 * GPIO_Program.c
 *
 *  Created on: 17 Oct 2022
 *      Author: moham
 */

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 Copy_u8Dir)
{
	if(Copy_u8PinNo < 16)
	{
		switch(Copy_u8PortNo)
		{
		case GPIO_PORTA:
			if(Copy_u8PinNo < 8)
			{
				GPIOA->CRL &= ~(0b1111 << (4 * Copy_u8PinNo));
				GPIOA->CRL |=  ((0b1111 & Copy_u8Dir) << (4 * Copy_u8PinNo));
			}
			else if(Copy_u8PinNo < 16)
			{
				GPIOA->CRH &= ~(0b1111 << ((Copy_u8PinNo - 8 ) * 4));
				GPIOA->CRH |=  ((0b1111 & Copy_u8Dir) << ((Copy_u8PinNo - 8 ) * 4));
			}
			break;
		case GPIO_PORTB:
			if(Copy_u8PinNo < 8)
			{
				GPIOB->CRL &= ~(0b1111 << (4 * Copy_u8PinNo));
				GPIOB->CRL |=  ((0b1111 & Copy_u8Dir) << (4 * Copy_u8PinNo));
			}
			else if(Copy_u8PinNo < 16)
			{
				GPIOB->CRH &= ~(0b1111 << ((Copy_u8PinNo - 8 ) * 4));
				GPIOB->CRH |=  ((0b1111 & Copy_u8Dir) << ((Copy_u8PinNo - 8 ) * 4));
			}
			break;
		case GPIO_PORTC:
			if(Copy_u8PinNo < 8)
			{
				GPIOC->CRL &= ~(0b1111 << (4 * Copy_u8PinNo));
				GPIOC->CRL |=  ((0b1111 & Copy_u8Dir) << (4 * Copy_u8PinNo));
			}
			else if(Copy_u8PinNo < 16)
			{
				GPIOC->CRH &= ~(0b1111 << ((Copy_u8PinNo - 8 ) * 4));
				GPIOC->CRH |=  ((0b1111 & Copy_u8Dir) << ((Copy_u8PinNo - 8 ) * 4));
			}
			break;
		}
		if(Copy_u8Dir == INPUT_PULL_UP)
		{
			GPIO_voidSetPinVAlue(Copy_u8PortNo , Copy_u8PinNo , GPIO_HIGH);
		}
		else if(Copy_u8Dir == INPUT_PULL_DOWN)
		{
			GPIO_voidSetPinVAlue(Copy_u8PortNo , Copy_u8PinNo , GPIO_LOW);
		}
	}
}

void GPIO_voidSetPinVAlue(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 Copy_u8Val)
{
	if(Copy_u8PinNo < 16)
	{
		switch(Copy_u8PortNo)
		{
		case GPIO_PORTA:
			if(Copy_u8Val == GPIO_HIGH)
			{
				SET_BIT(GPIOA->ODR , Copy_u8PinNo );
			}
			else if(Copy_u8Val == GPIO_LOW)
			{
				CLR_BIT(GPIOA->ODR , Copy_u8PinNo );
			}
			break;
		case GPIO_PORTB:
			if(Copy_u8Val == GPIO_HIGH)
			{
				SET_BIT(GPIOB->ODR , Copy_u8PinNo );
			}
			else if(Copy_u8Val == GPIO_LOW)
			{
				CLR_BIT(GPIOB->ODR , Copy_u8PinNo );
			}
			break;
		case GPIO_PORTC:
			if(Copy_u8Val == GPIO_HIGH)
			{
				SET_BIT(GPIOC->ODR , Copy_u8PinNo );
			}
			else if(Copy_u8Val == GPIO_LOW)
			{
				CLR_BIT(GPIOC->ODR , Copy_u8PinNo );
			}
			break;
		}
	}
}

// wrapper function -> Adaptor Pattern
void GPIO_voidSetPinVAlue2(GPIO_Config_t* pxGpio , u8 Copy_u8Val)
{
	GPIO_voidSetPinVAlue(pxGpio->Port , pxGpio->Pin , Copy_u8Val);
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PortNo , u8 Copy_u8PinNo)
{
	u8 L_u8PinValue = 0 ;
	if(Copy_u8PinNo < 16)
	{
		switch(Copy_u8PortNo)
		{
		case GPIO_PORTA:
			L_u8PinValue = GET_BIT(GPIOA->IDR , Copy_u8PinNo);
			break;
		case GPIO_PORTB:
			L_u8PinValue = GET_BIT(GPIOB->IDR , Copy_u8PinNo);
			break;
		case GPIO_PORTC:
			L_u8PinValue = GET_BIT(GPIOC->IDR , Copy_u8PinNo);
			break;
		}
	}
	return L_u8PinValue ;
}

void GPIO_vInit(GPIO_Config_t* pxGpio)
{
	u8 L_u8Dir = 0 ;
	if(pxGpio->Mode == mGPIO_OUTPUT)
	{
		L_u8Dir |= pxGpio->OutputSpeed ;
		// 0b0000[AltFunc][OutputType][Output Speed]
		if(pxGpio->AltFn != mGPIO_GeneralPurpose)
		{
			SET_BIT(L_u8Dir , 3);
		}
		if(pxGpio->OutputType != mGPIO_PushPull)
		{
			SET_BIT(L_u8Dir , 2);
		}
	}
	else
	{
		//input settings
	}
//	L_u8Dir = OUTPUT_2MHZ_GPPP ;
	GPIO_voidSetPinDirection(pxGpio->Port , pxGpio->Pin , L_u8Dir);
}




/*
//---------------------------------------------------------------------------------------
void GPIO_voidSetPortDirection_High(u8 Copy_u8PortNo , u32 Copy_u32Dir){

}

void GPIO_voidSetPortDirection_Low(u8 Copy_u8PortNo , u32 Copy_u32Dir){

}

void GPIO_voidSetPortValue_High(u8 Copy_u8PortNo , u8 Copy_u8Val)
{

}

void GPIO_voidSetPortValue_Low(u8 Copy_u8PortNo , u8 Copy_u8Val)
{

}
 */
