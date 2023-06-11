#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "ADC_Interface.h"
#include "ADC_Prv.h"
#include "ADC_Cfg.h"
#include "ADC_Reg.h"


	static ADC_Chain_t *ADC_pChainData = NULL ;

	static uint8 ADC_u8AsynchType  ;						// SINGLE OR CHAIN

	static uint8 ADC_u8ConversionIndex = 0u ;

	static uint16* ADC_pu16DigitalResult = NULL ;

	static void (*ADC_pvNotificationFunc)(void) = NULL ;

	static uint8 ADC_u8BusyFlag = IDLE ;


	void ADC_voidInit  			   ( void )
	{
											/* 1- REFERENCE SELECTION : AVCC with external capacitor at AREF pin */

		CLR_BIT ( ADMUX , ADMUX_REFS1 ) ;
		SET_BIT ( ADMUX , ADMUX_REFS0 ) ;
	#if 			ADC_u8RESOLUTION == EIGHT_BITS

											/* 2- PREPARE : LEFT ADJUST : 8_BITS RESOLUTION */

		SET_BIT ( ADMUX , ADMUX_ADLAR ) ; 						// LEFT ADJUST
	#elif 			ADC_u8RESOLUTION == TEN_BITS

		CLR_BIT ( ADMUX , ADMUX_ADLAR ) ;
	#else

		#error Wrong ADC_u8RESOLUTION  Configuration Value

	#endif

											/* 3- CHECK ON PRESCULAR CONFIGURATION SETTINGS  */

		ADCSRA &= PRESCALER_MASK  ; 					// CLEAR THE PRESCALER BITS
		ADCSRA |= ADC_u8PRESCALER ;

											/* 4- ADC ENABLE */

		SET_BIT ( ADCSRA , ADCSRA_ADEN ) ;

	}
	/**
	 * @brief this function is used to start single channel conversion and get back with the result
	 * @param copy_Channel : the required analog channel to convert , choose from options @ADC_Channel_t
	 * @param copy_pu16DigitalResult : out parameter for the digital result
	 * @return error state
	 */
	uint16 ADC_u8StartSingleConversionSynch ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult )
	{
		uint8 Local_u8ErrorState = OK ;
		if ( copy_pu16DigitalResult != NULL )
		{
			if ( ADC_u8BusyFlag == IDLE )
			{
				uint32 Local_u32Counter = 0u ;

										/* ADC IS NOW BUSY */

				ADC_u8BusyFlag = BUSY ;

										/* 1- SET THE REQUIRED CHANNEL */

				ADMUX &= CHANNEL_SELECTION_MASK ;				/* Clear the channel selection bits */
				ADMUX |= copy_Channel ;

										/* 2- SRART CONVERSION */

				SET_BIT ( ADCSRA , ADCSRA_ADSC ) ;

										/* 3- Wait (Block) until conversion is completed or the time out has not passed yet */

				while (( GET_BIT ( ADCSRA , ADCSRA_ADIF) == 0 ) && (Local_u32Counter < ADC_u32TIMEOUT_COUNT ) )
				{
					Local_u32Counter ++ ;
				}
				if ( Local_u32Counter == ADC_u32TIMEOUT_COUNT )
				{
								/* LOOP IS BROKEN BECAUSE TIME OUT HAS PASSED */

					Local_u8ErrorState = TIMEOUT_ERR ;
				}
				else     		/* LOOP IS BROKEN BECAUSE FLAG IS RAISED */
				{
											/* 4- CLEAR THE FLAG */

					SET_BIT ( ADCSRA , ADCSRA_ADIF ) ;

											/* 5- READ THE DATA */

					#if 			ADC_u8RESOLUTION == EIGHT_BITS
							// IN 8-BIT RESOLUTION ( ADC READONG == ADCH )

						*copy_pu16DigitalResult =  (uint16)ADCH ;

					#elif 			ADC_u8RESOLUTION == TEN_BITS
						*copy_pu16DigitalResult =  ADC ;

					#endif
									/*TASK IS DONE , ADC IS NOW IDLE */

						ADC_u8BusyFlag = IDLE ;
				}
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

	uint16 ADC_u8StartSingleConversionAsynch ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult , void(*copy_pvNotification)(void) )

	{
		ADC_u8AsynchType = SINGLE ;
		uint8 Local_u8ErrorState = OK ;
		if ( ( copy_pu16DigitalResult != NULL ) && ( copy_pvNotification != NULL ) )
		{
			if ( ADC_u8BusyFlag == IDLE )
			{
													/* ADC IS BUSY */

				ADC_u8BusyFlag = BUSY ;

					/* CONVERT THE DIGITAL RESULT AND THE NOTIFICATION FUNCTION LOCAL VARIABLES INTO GLOBAL */

				ADC_pu16DigitalResult  = copy_pu16DigitalResult ;
				ADC_pvNotificationFunc = copy_pvNotification ;



													/* 1- SET THE REQUIRED CHANNEL */

				ADMUX &= CHANNEL_SELECTION_MASK ;
				ADMUX |= copy_Channel ;

													/* 2- SRART CONVERSION */

				SET_BIT ( ADCSRA , ADCSRA_ADSC ) ;

													/* 3- ENABLE ADC CONVERSION COMPLETE INTERRUPT */

				SET_BIT( ADCSRA , ADCSRA_ADIE ) ;

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

	uint8  ADC_u8StartChainConversionAsynch 	 	 (const ADC_Chain_t *copy_ChainData)
	{
		uint8 Local_u8ErrorState = OK ;
		if (	copy_ChainData != NULL	)
		{
			if (ADC_u8BusyFlag == IDLE)
			{
														/* Set the ADC busy flag */
				ADC_u8BusyFlag = BUSY;

				ADC_u8AsynchType = CHAIN;
														/* Save the parameters */

				ADC_pChainData = copy_ChainData ;

				ADC_u8ConversionIndex = 0u ;

														/* Set the FIRST ADC channel */
				ADMUX &= CHANNEL_SELECTION_MASK;
				ADMUX |= ADC_pChainData->ChannelArr[ADC_u8ConversionIndex];


														/* Enable ADC conversion complete interrupt AND START CONVERSIONt */
				SET_BIT(ADCSRA, ADCSRA_ADSC);
				SET_BIT(ADCSRA, ADCSRA_ADIE);
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR;
		}
		return Local_u8ErrorState ;
	}

												/* ADC CONVERSION COMPLETE ISR */

	void __vector_16 ( void )			__attribute__((signal)) ;
	void __vector_16 ( void )
	{
		if (ADC_u8AsynchType == SINGLE)
		{
			#if 			ADC_u8RESOLUTION == EIGHT_BITS

							// IN 8-BIT RESOLUTION ( ADC READONG == ADCH )

					*ADC_pu16DigitalResult = (uint16)ADCH ;

			#elif 			ADC_u8RESOLUTION == TEN_BITS
					*ADC_pu16DigitalResult = ADC ;
			#endif
							/* ADC INTERRUPT DISABLE */

			CLR_BIT(ADCSRA,ADCSRA_ADIE) ;

							/*TASK IS DONE , ADC IS NOW IDLE */

			ADC_u8BusyFlag = IDLE ;

							/* INVOKE THE CALLBACK NOTIFICATION FUNCTION */

			if ( ADC_pvNotificationFunc != NULL )
			{
				ADC_pvNotificationFunc() ;
			}
			else
			{
				// DO NOTHING
			}
		}
		else if (ADC_u8AsynchType == CHAIN )
		{

			#if 			ADC_u8RESOLUTION == EIGHT_BITS

							// IN 8-BIT RESOLUTION ( ADC READONG == ADCH )
					ADC_pChainData -> ResultArr[ADC_u8ConversionIndex] = (uint16)ADCH ;


			#elif 			ADC_u8RESOLUTION == TEN_BITS
					ADC_pChainData -> ResultArr[ADC_u8ConversionIndex] = ADC ;

			#endif

					ADC_u8ConversionIndex ++ ;

								/* If all samples have been taken, disable the ADC and call the callback function */
			if (ADC_u8ConversionIndex == ADC_pChainData->ConversionsNum)
			{
				ADC_u8BusyFlag = IDLE;

				CLR_BIT(ADCSRA, ADCSRA_ADIE);   				// DISABLE INTERRUPT

				if(ADC_pChainData->NotificationFunc != NULL)
				{
					ADC_pChainData->NotificationFunc() ;
				}
				else
				{
					// DO NOTHING
				}

			}
				        			/* start the next conversion */
			else
			{
								/* Set the ADC channel */

				ADMUX &= CHANNEL_SELECTION_MASK;
				ADMUX |= ADC_pChainData->ChannelArr[ADC_u8ConversionIndex];


								/* Start next conversion */
				SET_BIT(ADCSRA, ADCSRA_ADSC);
			}
		}


	}



