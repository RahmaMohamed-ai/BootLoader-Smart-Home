#include "00-LIB/STD_TYPES.h"
#include "00-LIB/ARM_util.h"

#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/STK/STK_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/UART/USART_INTERFACE.h"

volatile char buffer[10];
volatile u8 uart_flag = 0;

void uart_cbk(u8 data)
{
	static u32 buffer_idx = 0;
	buffer[buffer_idx] = data;
	if (buffer_idx == (sizeof(buffer) / sizeof(buffer[0])-1) || buffer[buffer_idx] == '\n' || buffer[buffer_idx] == '\r')
	{
		buffer[buffer_idx] = '\0';
		buffer_idx = 0 ;
		uart_flag = 1;
	}
	else
	{
		buffer_idx++;
	}
}

int main (void)
{
//#define SCB_VTOR   *((volatile u32*)0xE000ED08)
//
//	SCB_VTOR = 0x08001000;
	RCC_voidInit();
	STK_voidInit();
	NVIC_voidInit();

	RCC_voidEnableClock(RCC_APB2 , RCC_APB2ENR_IOPAEN);
	RCC_voidEnableClock(RCC_APB1 , RCC_APB1ENR_USART2EN);

	GPIO_voidSetPinDirection(GPIO_PORTA , 2 , OUTPUT_2MHZ_AFPP);
	GPIO_voidSetPinDirection(GPIO_PORTA , 3 , INPUT_FLOATING);

	NVIC_voidEnableInterrupt(NVIC_USART2);

	MUSART2_VidInit();

	int led_flag = 0 ;
	GPIO_voidSetPinDirection(GPIO_PORTA , 7 , OUTPUT_2MHZ_GPPP);
	GPIO_voidSetPinDirection(GPIO_PORTA , 8 , INPUT_PULL_DOWN);
	GPIO_voidSetPinDirection(GPIO_PORTA , 5 , OUTPUT_2MHZ_GPPP);
	GPIO_voidSetPinDirection(GPIO_PORTA , 6 , INPUT_PULL_DOWN);
	GPIO_voidSetPinDirection(GPIO_PORTA , 11 , OUTPUT_2MHZ_GPPP);
	GPIO_voidSetPinVAlue(GPIO_PORTA , 5 , GPIO_LOW);

	MUSART2_VidSetCallBack(uart_cbk);

	while(1)
	{

		if(GPIO_u8GetPinValue(GPIO_PORTA , 8) == 1 && led_flag == 0)
		{
			MUSART2_VidSendStringSynch("Room 1 Motion detect \n");
			GPIO_voidSetPinVAlue(GPIO_PORTA , 5 , GPIO_HIGH);
			led_flag = 1 ;
		}
		if(GPIO_u8GetPinValue(GPIO_PORTA , 6) == 0)
		{
			MUSART2_VidSendStringSynch("fire !!!!!!! \n");
			GPIO_voidSetPinVAlue(GPIO_PORTA , 11 , GPIO_HIGH);
		}
		else
		{
			GPIO_voidSetPinVAlue(GPIO_PORTA , 11 , GPIO_LOW);
		}

		if( buffer[0] == 'o' && buffer[1] == 'p' && buffer[2] == 'e' && buffer[3] == 'n' )
		{
			MUSART2_VidSendStringSynch("Door is opening \r\n");
			for(int i = 0 ; i < 10 ; i ++)
			{
				GPIO_voidSetPinVAlue(GPIO_PORTA , 7 , GPIO_HIGH);
				STK_voidSetBusyWait(2000);
				GPIO_voidSetPinVAlue(GPIO_PORTA , 7 , GPIO_LOW);
				STK_voidSetBusyWait(18000);
			}
			buffer[0] = 0 ;
		}
		if(buffer[0] == 'c' && buffer[1] == 'l' && buffer[2] == 'o' && buffer[3] == 's' && buffer[4] == 'e')
		{
			MUSART2_VidSendStringSynch("Door is closing \r\n");
			for(int i = 0 ; i < 10 ; i ++)
			{
				GPIO_voidSetPinVAlue(GPIO_PORTA , 7 , GPIO_HIGH);
				STK_voidSetBusyWait(1000);
				GPIO_voidSetPinVAlue(GPIO_PORTA , 7 , GPIO_LOW);
				STK_voidSetBusyWait(19000);
			}
			buffer[0] = 0 ;
		}
		if(buffer[0] == 'r' && buffer[1] == 'o' && buffer[2] == 'o' && buffer[3] == 'm' && buffer[4] == '1')
		{
			if(led_flag == 1)
			{
				GPIO_voidSetPinVAlue(GPIO_PORTA , 5 , GPIO_LOW);
				led_flag = 0 ;
			}
			else
			{
				GPIO_voidSetPinVAlue(GPIO_PORTA , 5 , GPIO_HIGH);
				led_flag = 1 ;
			}
			buffer[0] = 0 ;
		}
	}
}

