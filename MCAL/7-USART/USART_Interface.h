#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H
	
											/* Functions Deceleration */

	void USART_voidInit					( void ) ;

	void USART_voidSendByteSynch 		( uint8 copy_u8Data);

	uint8 USART_u8RecieveByteSynch	 	( void ) ;

	uint8 USART_u8SendBufferSynch 		( uint8 * copy_pu8Buffer , uint8 copy_u8Length ) ;

	uint8 USART_u8ReceiveBufferSynch 	( uint8 * copy_pu8Buffer , uint8 copy_u8Length ) ;

	uint8 USART_u16FindUBRRValue 		(uint8 copy_UARTType , uint8 copy_u8DoubleSpeedStatus , uint8 copy_OscillatorFrequency , uint32 copy_BaudRate , uint16 *copy_pUDRRValue) ;

	uint16 USART_u16InitUBRRValue 		(void) ;				// initial value calculation

	uint8 USART_voidSendByteAsynch 		( uint8* copy_u8Data , void (*copy_pNotificationFunc)(void)) ;

	uint8 USART_u8RecieveByteAsynch	 	( uint8* copy_u8Data , void (*copy_pNotificationFunc)(void) ) ;

	uint8 USART_u8SendBufferAsynch 		( uint8 * copy_pu8Buffer , uint8 copy_u8Length , void (*copy_pNotificationFunc)(void)) ;

	uint8 USART_u8ReceiveBufferAsynch 	( uint8 * copy_pu8Buffer , uint8 copy_u8Length , void (*copy_pNotificationFunc)(void)) ;

#endif
