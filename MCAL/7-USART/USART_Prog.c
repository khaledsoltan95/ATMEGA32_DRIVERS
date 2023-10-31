	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ERR_TYPE.h"

	#include "USART_Reg.h"
	#include "USART_Cfg.h"
	#include "USART_Prv.h"
	#include "USART_Interface.h"
	#include "CLCD_Interface.h"

	static uint8 *USART_u8Date = NULL ;
	static uint8 USART_DataType = SINGLE ;
	static uint8 USART_u8Status = FREE ;
	static uint8 USART_u8DataLength = 0u ;
	static uint8 USART_u8Counter = 0u ;
	static uint8 *USART_pu8Buffer = NULL ;
	static void (*USARTpNotificationFunc)(void) = NULL ;


	void USART_voidInit			( void )
	{
		uint8 Local_u8UCSRCValue = 0u ;

		/* UCSRC SELECTION NOT UBRRH */
		SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL) ;

		/* POLARITY SELECTION */
	#if 	USART_u8ClockPolarity == RISING_TRANSMITTING_FALLING_RECEIVING
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UCPOL);
	#elif 	USART_u8ClockPolarity == DISABLE
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UCPOL);
	#elif 	USART_u8ClockPolarity == FALLING_TRANSMITTING_RISING_RECEIVING
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCPOL);
	#else
	#error "USART_u8ClockPolarity option not valid"
	#endif

		/* 8 DATA BITS SELECTION */
	#if 	USART_u8DataBitsNumber == FIVE_BITS
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ0);
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ1);
		CLR_BIT	(UCSRB,UCSRB_UCSZ2);
	#elif 	USART_u8DataBitsNumber == SIX_BITS
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ0);
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ1);
		CLR_BIT	(UCSRB,UCSRB_UCSZ2);
	#elif 	USART_u8DataBitsNumber == SEVEN_BITS
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ0);
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ1);
		CLR_BIT	(UCSRB,UCSRB_UCSZ2);
	#elif 	USART_u8DataBitsNumber == EIGHT_BITS
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ0);
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ1);
		CLR_BIT	(UCSRB,UCSRB_UCSZ2);
	#elif 	USART_u8DataBitsNumber == NINE_BITS
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ0);
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UCSZ1);
		SET_BIT	(UCSRB,UCSRB_UCSZ2);
	#else
	#error "USART_u8DataBitsNumber option not valid"
	#endif

		/* NO PARITY SELECTION */
	#if 	USART_u8ParityMode == NO_PARITY
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UPM0);
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UPM1);
	#elif 	USART_u8ParityMode == EVEN_PARITY
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UPM0);
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UPM1);
	#elif 	USART_u8ParityMode == ODD_PARITY
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UPM0);
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UPM1);
	#else
	#error "USART_u8ParityMode option not valid"
	#endif

		/* STOP BIT SELECTION */
	#if 	USART_u8StopBitNumber == ONE_STOP_BIT
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_USBS);
	#elif 	USART_u8StopBitNumber == TWO_STOP_BITS
		SET_BIT	(Local_u8UCSRCValue,UCSRC_USBS);
	#else
	#error "USART_u8StopBitNumber option not valid"
	#endif

		/* OPERATION SELECTION */
	#if 	USART_u8Type == SYNCHRONOUS
		SET_BIT	(Local_u8UCSRCValue,UCSRC_UMSEL);        		// SYNCHRONOUS SELECTION
	#elif 	USART_u8Type == ASYNCHRONOUS
		CLR_BIT	(Local_u8UCSRCValue,UCSRC_UMSEL);        		// ASYNCHRONOUS SELECTION
	#else
	#error "USART_u8Type option not valid"
	#endif

		//											/* DOUBLE SPEED COLLECTION */
	#if 	USART_u8DoubleTransmissionSpeed == ENABLE
		SET_BIT	(UCSRA,UCSRA_U2X);
	#elif 	USART_u8DoubleTransmissionSpeed == DISABLE
		CLR_BIT	(UCSRA,UCSRA_U2X);
	#else
	#error "USART_u8DoubleTransmissionSpeed option not valid"
	#endif

		/* COMPLETE INTERRUPT SELECTION  */
	#if 	USART_u8SendCompleteInterrupt == ENABLE

		SET_BIT(UCSRB,UCSRB_TXCIE) ;  				// TX Complete Interrupt ENABLE
	#elif 	USART_u8SendCompleteInterrupt == DISABLE
		CLR_BIT	(UCSRB,UCSRB_TXCIE);        		// TX Complete Interrupt DISABLE
	#else
	#error "USART_u8SendCompleteInterrupt option not valid"
	#endif

	#if 	USART_u8ReceiveCompleteInterrupt == ENABLE
		SET_BIT(UCSRB,UCSRB_RXCIE);        			// RX Complete Interrupt ENABLE
	#elif 	USART_u8ReceiveCompleteInterrupt == DISABLE
		CLR_BIT	(UCSRB,UCSRB_RXCIE);        		// RX Complete Interrupt DISABLE
	#else
	#error "USART_u8ReceiveCompleteInterrupt option not valid"
	#endif

	#if 	USART_u8EmptyRegisterCompleteInterrupt == ENABLE
		SET_BIT	(UCSRB,UCSRB_UDRIE);        		// USART Data Register Empty Interrupt ENABLE
	#elif 	USART_u8EmptyRegisterCompleteInterrupt == DISABLE
		CLR_BIT	(UCSRB,UCSRB_UDRIE);    	     	// USART Data Register Empty Interrupt DISABLE
	#else
	#error "USART_u8EmptyRegisterCompleteInterrupt option not valid"
	#endif

		/* MODIFY UCSRC SETTING CHANGES MUST BE UPDATED AT THE TIME */
		UCSRC = Local_u8UCSRCValue ;

		/* 9600 bPS SELECTION */
		UBRRL = USART_u16InitUBRRValue() ;

		/* ENABLE RECIEVING & SENDING DATA */
	#if 	USART_u8SendingEnable == ENABLE
		SET_BIT (UCSRB,UCSRB_TXEN) ;       		// Transmitter Enable
	#elif 	USART_u8SendingEnable == DISABLE
		CLR_BIT (UCSRB,UCSRB_TXEN) ;       		// Transmitter Disable
	#else
	#error "USART_u8SendingEnable option not valid"
	#endif
	#if 	USART_u8ReceivingEnable == ENABLE
		SET_BIT (UCSRB,UCSRB_RXEN) ;      		// Receiver Enable
	#elif 	USART_u8ReceivingEnable == DISABLE
		CLR_BIT (UCSRB,UCSRB_RXEN) ;       		// Receiver Disable
	#else
	#error "USART_u8ReceivingEnable option not valid"
	#endif

	}

	void USART_voidSendByteSynch 		( uint8 copy_u8Data)
	{
		/* CHECK UDRE FLAG */

		while ( ( GET_BIT (UCSRA,UCSRA_UDRE) ) != 1u ) ;				/* WAIT UNTIL TRANSMIT BUFFER IS EMPTY AND READY */

		/* SET THE DATA */

		UDR = copy_u8Data ;
	}

	uint8 USART_u8RecieveByteSynch	 	( void )
	{
		uint16 Local_u8Counter = 0u ;
		/* CHECK RXC FLAG */

		while ( (( GET_BIT(UCSRA,UCSRA_RXC) ) != 1u) && (Local_u8Counter < 10u) )		/* WAIT UNTIL DATA IS RECEIVED OR COUNTER LESS THAN 2000U */
		{
			Local_u8Counter ++;
		}
		if (Local_u8Counter == 10u)
		{
			return TIMEOUT_ERR ;
		}
		else
		{
			/* RETURN THE DATA */
			return UDR ;
		}
	}

	uint8 USART_u8SendBufferSynch 		( uint8 * copy_pu8Buffer , uint8 copy_u8Length )
	{
		uint8 Local_u8ErrorState = OK ;
		if (copy_pu8Buffer != NULL)
		{
			uint8 Local_u8Counter ;
			for (Local_u8Counter = 0u ; Local_u8Counter < copy_u8Length ; Local_u8Counter ++)
			{
				USART_voidSendByteSynch(copy_pu8Buffer[Local_u8Counter]) ;
			}
		}
		else
		{
			Local_u8ErrorState =  NULL_PTR ;
		}

		return Local_u8ErrorState ;
	}

	uint8 USART_u8ReceiveBufferSynch 	( uint8 * copy_pu8Buffer , uint8 copy_u8Length )
	{
		uint8 Local_u8ErrorState = OK ;
		if (copy_pu8Buffer != NULL)
		{
			uint8 Local_u8Counter ;
			for (Local_u8Counter = 0u ; Local_u8Counter < copy_u8Length ; Local_u8Counter ++)
			{
				copy_pu8Buffer[Local_u8Counter] = USART_u8RecieveByteSynch() ;
			}
		}
		else
		{
			Local_u8ErrorState =  NULL_PTR ;
		}

		return Local_u8ErrorState ;
	}

	uint8 USART_u16FindUBRRValue 		(uint8 copy_UARTType , uint8 copy_u8DoubleSpeedStatus , uint8 copy_OscillatorFrequency , uint32 copy_BaudRate , uint16 *copy_pUDRRValue)
	{
		uint8 Local_u8ErrorState = OK ;
		if ((copy_OscillatorFrequency >= 1u) && (copy_OscillatorFrequency <= 20u) && (copy_BaudRate <= 1000000))
		{
			if (copy_UARTType == ASYNCHRONOUS)
			{
				if (copy_u8DoubleSpeedStatus == ENABLE)
				{
					*copy_pUDRRValue = (uint16) (((uint32)copy_OscillatorFrequency * 1000000u)/((uint32)copy_BaudRate * 8u)) - 1u ;
				}
				else if (copy_u8DoubleSpeedStatus == DISABLE)
				{
					*copy_pUDRRValue = (uint16) (((uint32)copy_OscillatorFrequency * 1000000u)/((uint32)copy_BaudRate * 16u)) - 1u ;
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
			}
			else if (copy_UARTType == SYNCHRONOUS)
			{
				*copy_pUDRRValue = (uint16) (((uint32)copy_OscillatorFrequency * 1000000u)/((uint32)copy_BaudRate * 2u)) - 1u ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

		return Local_u8ErrorState ;
	}

	uint16 USART_u16InitUBRRValue 		(void)
	{
		uint16 Local_u16UDRRValue = 0u ;
	#if USART_u8Type == ASYNCHRONOUS
	#if USART_u8DoubleTransmissionSpeed == ENABLE
		Local_u16UDRRValue = (uint16) (((USART_u8OscillatorFrequency * 1000000ul)/(USART_u32BaudRate * 8ul)) - 1u) ;
	#elif USART_u8DoubleTransmissionSpeed == DISABLE
		Local_u16UDRRValue = (uint16) ((USART_u8OscillatorFrequency * 1000000u)/(USART_u32BaudRate * 16u)) - 1u ;
	#else
	#error "USART_u8DoubleTransmissionSpeed option not valid"
	#endif

	#elif USART_u8Type == SYNCHRONOUS
		Local_u16UDRRValue = (uint16) ((USART_u8OscillatorFrequency * 1000000u)/(USART_u32BaudRate * 2u)) - 1u ;
	#else
	#error "USART_u8Type option not valid"
	#endif
		return Local_u16UDRRValue ;
	}

	uint8 USART_voidSendByteAsynch 		( uint8* copy_u8Data , void(*copy_pNotificationFunc)(void))
	{
		uint8 Local_u8ErrorState = OK ;
		if ((copy_u8Data != NULL) && (copy_pNotificationFunc != NULL))
		{
						// Make it Global
			/* Check the Flag */
			if (USART_u8Status == FREE)
			{
				USART_u8Status = BUSY;
				USART_DataType = SINGLE ;
				USARTpNotificationFunc = copy_pNotificationFunc ;
				SET_BIT(UCSRB,UCSRB_TXCIE) ;  								// TX Complete Interrupt ENABLE
				UDR = *copy_u8Data ;
				//Local_u8ErrorState = UDR ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}

		return Local_u8ErrorState ;
	}

	uint8 USART_u8RecieveByteAsynch	 	( uint8* copy_u8Data , void (*copy_pNotificationFunc)(void) )
	{
		uint8 Local_u8ErrorState = OK ;

		if ((copy_u8Data != NULL) && (copy_pNotificationFunc != NULL))
		{
			USART_DataType = SINGLE ;
			USART_u8Date = copy_u8Data ;
			USARTpNotificationFunc = copy_pNotificationFunc ;			// Make it Global
			SET_BIT(UCSRB,UCSRB_RXCIE);        							// RX Complete Interrupt ENABLE
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}

		return Local_u8ErrorState ;
	}

	uint8 USART_u8SendBufferAsynch 		( uint8 * copy_pu8Buffer , uint8 copy_u8Length , void (*copy_pNotificationFunc)(void))
	{
		uint8 Local_u8ErrorState = OK ;
		if ((copy_pu8Buffer != NULL) && (copy_pNotificationFunc != NULL))
		{

			/* Check the Flag */
			if (USART_u8Status == FREE)
			{
				USART_u8Status = BUSY ;
				USART_DataType = BUFFER ;
				USARTpNotificationFunc = copy_pNotificationFunc ;			// Make it Global
				USART_pu8Buffer = copy_pu8Buffer ; 							// Make it Global
				USART_u8DataLength = copy_u8Length ; 						// Make it Global
				SET_BIT(UCSRB,UCSRB_TXCIE) ;  								// TX Complete Interrupt ENABLE
				UDR = copy_pu8Buffer[0u] ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}

		return Local_u8ErrorState ;
	}

	uint8 USART_u8ReceiveBufferAsynch 	( uint8 * copy_pu8Buffer , uint8 copy_u8Length , void (*copy_pNotificationFunc)(void))
	{
		uint8 Local_u8ErrorState = OK ;
		if ((copy_pu8Buffer != NULL) && (copy_pNotificationFunc != NULL))
		{
			USART_DataType = BUFFER ;
			USARTpNotificationFunc = copy_pNotificationFunc ;		// Make it Global
			USART_pu8Buffer = copy_pu8Buffer ; 						// make it global
			USART_u8DataLength = copy_u8Length ; 					// make it global
			SET_BIT(UCSRB,UCSRB_RXCIE);        						// RX Complete Interrupt ENABLE
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}

	/* USART, Rx Complete ISR */

	void __vector_13 ( void )			__attribute__((signal)) ;
	void __vector_13 ( void )
	{
		//CLR_BIT(UCSRA,UCSRA_RXC) ;


		if (USART_DataType == SINGLE)
		{
			if(USARTpNotificationFunc != NULL)
			{
				*USART_u8Date = UDR ;
				CLR_BIT(UCSRB,UCSRB_RXCIE);        							// RX Complete Interrupt DISABLE
				USARTpNotificationFunc() ;
			}
			else
			{
				// DO NOTHING
			}
		}
		else if (USART_DataType == BUFFER)
		{
			if (USART_u8Counter < USART_u8DataLength )
			{
				USART_pu8Buffer[USART_u8Counter] = UDR ;
				USART_u8Counter ++ ;
			}
			else
			{
				USART_u8Counter = 0u ;
				USART_u8Status = FREE ;
				CLR_BIT(UCSRB,UCSRB_RXCIE) ;  								// RX Complete Interrupt DISABLE
				if(USARTpNotificationFunc != NULL)
				{
					USARTpNotificationFunc() ;
				}
				else
				{
					// DO NOTHING
				}
			}
		}
		else
		{
			// DO NOTHING
		}
	}

	/*  USART Data Register Empty ISR */

	void __vector_14 ( void )			__attribute__((signal)) ;
	void __vector_14 ( void )
	{
		USART_u8Status = FREE ;
	}

	/* USART, Tx Complete ISR */

	void __vector_15 ( void )			__attribute__((signal)) ;
	void __vector_15 ( void )
	{
		if (USART_DataType == SINGLE)
		{
			if (USARTpNotificationFunc != NULL)
			{
				USART_u8Status = FREE ;
				CLR_BIT(UCSRB,UCSRB_TXCIE) ;  								// TX Complete Interrupt DISABLE
				USARTpNotificationFunc() ;
			}
			else
			{
				// DO NOTHING
			}
		}
		else if (USART_DataType == BUFFER)
		{
			USART_u8Counter ++ ;
			if (USART_u8Counter < USART_u8DataLength)
			{
				UDR = USART_pu8Buffer[USART_u8Counter] ;
			}
			else
			{
				USART_u8Counter = 0u ;
				USART_u8Status = FREE ;
				CLR_BIT(UCSRB,UCSRB_TXCIE) ;  				// TX Complete Interrupt DISABLE
				if(USARTpNotificationFunc != NULL)
				{
					USARTpNotificationFunc() ;
				}
				else
				{
					// DO NOTHING
				}
			}
		}
		else
		{
			// DO NOTHING
		}

	}
