#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "USART_Reg.h"
#include "USART_Cfg.h"
#include "USART_Prv.h"
#include "USART_Interface.h"

	void USART_voidInit			( void )
	{
		uint8 Local_u8UCSRCValue = 0 ;

											/* UCSRC SELECTION NOT UBRRH */

		SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL) ;

											/* 8 DATA BITS SELECTION */

		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ0);
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ1);
		CLR_BIT	(Local_u8UCSRCValue,UCSRB_UCSZ2);

											/* NO PARITY SELECTION */

		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UPM0);
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UPM1);

											/* STOP BIT SELECTION */

		CLR_BIT	(Local_u8UCSRCValue,UCSRC_USBS);

											/* ASYNCHRONOUS OPERATION SELECTION */

		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UMSEL);

											/* DOUBLE SPEED COLLECTION */

		SET_BIT	(UCSRA,UCSRA_U2X);

											/* NO INTERRUPT */

		CLR_BIT	(UCSRB,UCSRB_RXCIE);        	// RX Complete Interrupt DISABLE
		CLR_BIT	(UCSRB,UCSRB_TXCIE);			// TX Complete Interrupt DISABLE
		CLR_BIT	(UCSRB,UCSRB_UDRIE); 			// USART Data Register Empty Interrupt DISABLE

											/* MODIFY UCSRC SETTING */

		UCSRC = Local_u8UCSRCValue ;

											/* 9600 bPS SELECTION */

		UBRRL = 207U  ;

											/* ENABLE RECIEVING & SENDING DATA */

		SET_BIT (UCSRB,UCSRB_RXEN) ; 			// Receiver Enable
		SET_BIT (UCSRB,UCSRB_TXEN) ;			// Transmitter Enable


	}

	void USART_voidSend 		( uint8 copy_u8Data)
	{
											/* CHECK UDRE FLAG */

		while ( ( GET_BIT (UCSRA,UCSRA_UDRE) ) != 1 ) ;				/* WAIT UNTIL TRANSMIT BUFFER IS EMPTY AND READY */

											/* SET THE DATA */

		UDR = copy_u8Data ;
	}

	uint8 USART_u8Recieve	 	( void )
	{
											/* CHECK RXC FLAG */

		while ( ( GET_BIT(UCSRA,UCSRA_RXC) ) != 1 );				/* WAIT UNTIL DATA IS RECEIVED */

											/* RETURN THE DATA */

		return UDR ;
	}
