/*
 * GPIO_Interface.h
 *
 *  Created on: 17 Oct 2022
 *      Author: moham
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#define OUTPUT_2MHZ_GPPP 		0b0010
#define OUTPUT_10MHZ_GPPP 		0b0001
#define OUTPUT_50MHZ_GPPP 		0b0011

#define OUTPUT_2MHZ_GPOD 		0b0110
#define OUTPUT_10MHZ_GPOD 		0b0101
#define OUTPUT_50MHZ_GPOD 		0b0111

#define OUTPUT_2MHZ_AFPP 		0b1010
#define OUTPUT_10MHZ_AFPP 		0b1001
#define OUTPUT_50MHZ_AFPP 		0b1011

#define OUTPUT_2MHZ_AFOD 		0b1110
#define OUTPUT_10MHZ_AFOD 		0b1101
#define OUTPUT_50MHZ_AFOD 		0b1111

#define INPUT_ANALOG			0b0000
#define INPUT_FLOATING			0b0100
#define INPUT_PULL_DOWN			0b1000
#define INPUT_PULL_UP			0b10001

#define GPIO_HIGH				1
#define GPIO_LOW				0

#define GPIO_PORTA 				0
#define GPIO_PORTB				1
#define GPIO_PORTC 				2

#define GPIO_PIN0				0
#define GPIO_PIN1				1
#define GPIO_PIN2				2
#define GPIO_PIN3				3
#define GPIO_PIN4				4
#define GPIO_PIN5				5
#define GPIO_PIN6				6
#define GPIO_PIN7				7
#define GPIO_PIN8				8
#define GPIO_PIN9				9
#define GPIO_PIN10				10
#define GPIO_PIN11				11
#define GPIO_PIN12				12
#define GPIO_PIN13				13
#define GPIO_PIN14				14
#define GPIO_PIN15				15

typedef enum
{
	mGPIO_PORTA,
	mGPIO_PORTB,
	mGPIO_PORTC
}GPIO_Port_t;

typedef enum
{
	mGPIO_PIN0,
	mGPIO_PIN1,
	mGPIO_PIN2
}GPIO_Pin_t;

typedef enum
{
	mGPIO_NOSPEED = 0b00,
	mGPIO_2MHZ = 0b10,
	mGPIO_10MHZ = 0b01,
	mGPIO_50MHZ = 0b11
}GPIO_OutputSpeed_t;

typedef enum
{
	mGPIO_INPUT,
	mGPIO_OUTPUT
}GPIO_Mode_t;

#define ALTFUNC 1
#define OpenDrain 1
#define mGPIO_PushPull 0
#define mGPIO_GeneralPurpose 0

typedef struct
{
	GPIO_Port_t Port ;
	GPIO_Pin_t Pin ;
	GPIO_Mode_t Mode ;
	GPIO_OutputSpeed_t OutputSpeed ;
	u8 OutputType;						/*PushPull = 0 , OpenDrain = 1*/
	u8 InputType;						/*PULL_UP = 0b11 , PULLDPWN = 0b10 , FLOATING = 0b01 , ANALOG = 0b00*/
	u8 AltFn;							/*GPIO = 0 , ALTFUNC = 1*/
}GPIO_Config_t;

void GPIO_vInit(GPIO_Config_t* pxGpio);
void GPIO_voidSetPinVAlue2(GPIO_Config_t* pxGpio , u8 Copy_u8Val);

void GPIO_voidSetPinDirection(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 Copy_u8Dir);
void GPIO_voidSetPinVAlue(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 Copy_u8Val);
u8 GPIO_u8GetPinValue(u8 Copy_u8PortNo , u8 Copy_u8PinNo);
void GPIO_voidSetPortDirection_High(u8 Copy_u8PortNo , u32 Copy_u32Dir);
void GPIO_voidSetPortDirection_Low(u8 Copy_u8PortNo , u32 Copy_u32Dir);
void GPIO_voidSetPortValue_High(u8 Copy_u8PortNo , u8 Copy_u8Val);
void GPIO_voidSetPortValue_Low(u8 Copy_u8PortNo , u8 Copy_u8Val);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
