#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "ADC_Interface.h"
#include "ADC_Prv.h"
#include "ADC_Cfg.h"
#include "ADC_Reg.h"

	static uint8 ADC_u8Index = 0;

	static ChainConversionStruct_t *ADC_structChainConversion ;

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
	
	uint16 ADC_u8StartConversionSynch ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult )
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

	uint16 ADC_u8StartConversionAsynch ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult , void(*copy_pvNotification)(void) )

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

	uint8 ADC_StartChainConversionAsynch(ChainConversionStruct_t *copy_structpConversionChainSent)
	{
		uint8 Local_u8ErrorState = OK ;
		if ((copy_structpConversionChainSent != NULL) && (copy_structpConversionChainSent ->Conversion_Channel_arr != NULL ) && (copy_structpConversionChainSent -> result_arr != NULL) && (copy_structpConversionChainSent ->NotificationFunction != NULL ))
		{
			if (ADC_u8BusyFlag == IDLE)
			{
				ADC_u8AsynchType = CHAIN;

														/* Set the ADC busy flag */
				ADC_u8BusyFlag = BUSY;

														/* Save the parameters */

				ADC_structChainConversion = copy_structpConversionChainSent ;

														/* Set the ADC channel */
				ADMUX &= CHANNEL_SELECTION_MASK;
				ADMUX |= ADC_structChainConversion->Conversion_Channel_arr[ADC_u8Index];


														/* Enable ADC conversion complete interrupt */
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
					ADC_structChainConversion -> result_arr[ADC_u8Index] = ADCH


			#elif 			ADC_u8RESOLUTION == TEN_BITS
					ADC_structChainConversion -> result_arr[ADC_u8Index] = ADC ;

			#endif

					ADC_u8Index ++ ;

								/* If all samples have been taken, disable the ADC and call the callback function */
			if (ADC_u8Index >= ADC_structChainConversion->Conversion_Number)
			{
				CLR_BIT(ADCSRA, ADCSRA_ADIE);
				ADC_u8ConversionIndex = 0;
			    ADC_u8BusyFlag = IDLE;
				if(ADC_structChainConversion->NotificationFunction != NULL)
				{
					ADC_structChainConversion->NotificationFunction() ;
				}

			}
				        			/* start the next conversion */
			else
			{
								/* Set the ADC channel */

				ADMUX &= CHANNEL_SELECTION_MASK;
				ADMUX |= ADC_structChainConversion->Conversion_Channel_arr[ADC_u8Index];


								/* Start next conversion and Enable ADC conversion complete interrupt */
				SET_BIT(ADCSRA, ADCSRA_ADSC);
				SET_BIT(ADCSRA, ADCSRA_ADIE);
			}
		}


	}



