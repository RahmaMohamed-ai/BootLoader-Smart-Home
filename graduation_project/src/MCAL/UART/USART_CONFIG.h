/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/* System Clock */

#define F_CPU                    8000000UL

/* USART1_Configuration */

#define USART1_STATUS            USART1_ENABLE
#define USART1_BAUD_RATE         (u32)9600

#define USART1_WORD_LENGTH       _8BIT_WORD_LENGTH
#define USART1_PARITY            PARITY_DISABLE
#define USART1_INTERRUPT         INT_DISABLE

#define USART1_TRANSMITTER       TRANSMITTER_ENABLE
#define USART1_RECEIVER          RECEIVER_ENABLE

#define USART1_STOP_BITS         ONE_STOP_BIT

/* USART2_Configuration */

#define USART2_STATUS            USART2_ENABLE
#define USART2_BAUD_RATE         (u32)9600

#define USART2_WORD_LENGTH       _8BIT_WORD_LENGTH
#define USART2_PARITY            PARITY_DISABLE
#define USART2_INTERRUPT         RXNE_INT_ENABLE

#define USART2_TRANSMITTER       TRANSMITTER_ENABLE
#define USART2_RECEIVER          RECEIVER_ENABLE

#define USART2_STOP_BITS         ONE_STOP_BIT

#endif /* USART_CONFIG_H_ */
