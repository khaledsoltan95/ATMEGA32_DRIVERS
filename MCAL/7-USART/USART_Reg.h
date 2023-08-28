#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

											/* USART REGISTERS */

		#define 	UDR	                	*((volatile uint8*)0x2C)	  	/*USART I/O Data Register*/

		#define 	UCSRA	                *((volatile uint8*)0x2B)	  	/*USART Control and Status Register A*/
		#define 	UCSRA_RXC			 	7u                           	/*USART Receive Complete*/
		#define 	UCSRA_TXC			 	6u                           	/*USART Transmit Complete*/
		#define 	UCSRA_UDRE			 	5u                           	/*USART Data Register Empty*/
		#define 	UCSRA_FE			 	4u                           	/*Frame Error*/
		#define 	UCSRA_DOR			 	3u                           	/*Data OverRun*/
		#define 	UCSRA_PE			 	2u                           	/*Parity Error*/
		#define 	UCSRA_U2X				1u                           	/*Double the USART Transmission Speed*/
		#define 	UCSRA_MPCM			 	0u                           	/*Multi-processor Communication Mode*/

		#define 	UCSRB	                *((volatile uint8*)0x2A)	  	/*USART Control and Status Register B*/
		#define 	UCSRB_RXCIE			 	7u                           	/*Complete Interrupt Enable*/
		#define 	UCSRB_TXCIE			 	6u                           	/*Complete Interrupt Enable*/
		#define 	UCSRB_UDRIE			 	5u                           	/*USART Data Register Empty Interrupt Enable*/
		#define 	UCSRB_RXEN			 	4u                           	/*Receiver Enable*/
		#define 	UCSRB_TXEN			 	3u                           	/*Transmitter Enable*/
		#define 	UCSRB_UCSZ2			 	2u                           	/*Character Size*/
		#define 	UCSRB_RXB8				1u                           	/*Receive Data Bit 8*/
		#define 	UCSRB_TXB8			 	0u                           	/*Transmit Data Bit 8*/

		#define 	UCSRC	                *((volatile uint8*)0x40)	  	/*USART Control and Status Register C*/
		#define 	UCSRC_URSEL			 	7u                           	/*Register Select*/
		#define 	UCSRC_UMSEL			 	6u                           	/*USART Mode Select*/
		#define 	UCSRC_UPM1			 	5u                           	/*Parity Mode*/
		#define 	UCSRC_UPM0			 	4u                           	/*Parity Mode*/
		#define 	UCSRC_USBS			 	3u                           	/*Stop Bit Select*/
		#define 	UCSRC_UCSZ1			 	2u                           	/*Character Size*/
		#define 	UCSRC_UCSZ0				1u                           	/*Character Size*/
		#define 	UCSRC_UCPOL			 	0u                           	/*Clock Polarity*/

		#define 	UBRRL               	*((volatile uint8*)0x29)		/*USART Baud Rate Registers*/
		#define 	UBRRH               	*((volatile uint8*)0x40)		/*USART Baud Rate Registers*/
		#define 	UBRRH_URSEL			 	15u                           	/*Register Select*/
		#define 	UBRRH_R				 	14u                           	/*Reserved Bits*/
		#define 	UBRRH_R				 	13u                           	/*Reserved Bits*/
		#define 	UBRRH_R				 	12u                           	/*Reserved Bits*/
		#define 	UBRRH_11				11u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRH_10				10u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRH_9					9u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRH_8				 	8u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_7				 	7u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_6				 	6u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_5				 	5u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_4				 	4u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_3				 	3u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_2				 	2u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_1					1u                           	/*USART BAUD RATE REGISTER */
		#define 	UBRRL_0				 	0u                           	/*USART BAUD RATE REGISTER */


#endif
