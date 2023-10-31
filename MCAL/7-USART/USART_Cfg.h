#ifndef USART_CFG_H
#define USART_CFG_H

		/* Configuration Selection Options 	1- SYNCHRONOUS
		 * 									2- ASYNCHRONOUS
		 */
		#define USART_u8Type 										ASYNCHRONOUS


		/* Configuration Selection Options 	1- ENABLE
		 * with Asynchronous only			2- DISABLE
		 */
		#define	USART_u8DoubleTransmissionSpeed						ENABLE

		/* Configuration Selection Options 	1- RISING_TRANSMITTING_FALLING_RECEIVING
		 * with Synchronous only			2- FALLING_TRANSMITTING_RISING_RECEIVING
		 * 									3- DISABLE
		 */
		#define USART_u8ClockPolarity								DISABLE

		/* Configuration Selection Options 	1- ENABLE
		 * 									2- DISABLE
		 */
		#define USART_u8SendCompleteInterrupt 						ENABLE

		/* Configuration Selection Options 	1- ENABLE
		 * 									2- DISABLE
		 */
		#define USART_u8ReceiveCompleteInterrupt 					ENABLE

		/* Configuration Selection Options 	1- ENABLE
		 * 									2- DISABLE
		 */
		#define USART_u8EmptyRegisterCompleteInterrupt 				DISABLE

		/* Configuration Selection Options 	1- FIVE_BITS
		 * 									2- SIX_BITS
		 * 									3- SEVEN_BITS
		 * 									4- EIGHT_BITS
		 * 									5- NINE_BITS
		 */
		#define USART_u8DataBitsNumber				 				EIGHT_BITS

		/* Configuration Selection Options 	1- NO_PARITY
		 * 									2- EVEN_PARITY
		 * 									3- ODD_PARITY
		 */
		#define USART_u8ParityMode				 					NO_PARITY

		/* Configuration Selection Options 	1- ONE_STOP_BIT
		 * 									2- TWO_STOP_BITS
		 */
		#define USART_u8StopBitNumber				 				ONE_STOP_BIT

		/* Configuration Selection Options 	1- ENABLE
		 * 									2- DISABLE
		 */
		#define USART_u8SendingEnable								ENABLE

		/* Configuration Selection Options 	1- ENABLE
		 * 									2- DISABLE
		 */
		#define USART_u8ReceivingEnable								ENABLE

		/* SET VALUE RANGE FROM 2400 TO 1000000 */
		#define USART_u32BaudRate 									9600ul
#if 	(USART_u32BaudRate > 1000000) || (USART_u32BaudRate < 2400u)
#error "USART_u32BaudRate option not valid"
#endif

		/* SET VALUE RANGE FROM 1 TO 20 MHZ */
		#define USART_u8OscillatorFrequency 						16u
#if 	(USART_u8OscillatorFrequency > 20u) || (USART_u8OscillatorFrequency < 1u)
#error "USART_u8OscillatorFrequency option not valid"
#endif


#endif 
