#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"


#include "TIMER_Interface.h"
#include "TIMER_Prv.h"
#include "TIMER_Cfg.h"
#include "TIMER_Reg.h"

static void (*TIMER0_pvNotificationFunc)(void) = NULL ;
static void (*TIMER1_pvNotificationFunc)(void) = NULL ;

	void TIMER0_voidInit ( void )
	{
		#if TIMER0_u8MODE == NORMAL_MODE

			CLR_BIT (TCCR0,TCCR0_WGM00);
			CLR_BIT (TCCR0,TCCR0_WGM01);

									/* CONFIGURE CLOCK SELECTION */

			TCCR0 &= PRESCALER_MASK ;
			TCCR0 |= TIMER0_u8CLOCK ;

									/*SET PRELOAD VALUE */

			TCNT0 = TIMER0_u8PreloadValue ;

									/* Timer/Counter0 Overflow Interrupt Enable */

			SET_BIT(TIMSK,TIMSK_TOIE0) ;

		#elif TIMER0_u8MODE == PWM_PHASE_CORRECT_MODE
			SET_BIT (TCCR0,TCCR0_WGM00);
			CLR_BIT (TCCR0,TCCR0_WGM01);

		#elif TIMER0_u8MODE == CTC_MODE

			CLR_BIT (TCCR0,TCCR0_WGM00);
			SET_BIT (TCCR0,TCCR0_WGM01);

									/* CONFIGURE CLOCK SELECTION */

			TCCR0 &= PRESCALER_MASK ;
			TCCR0 |= TIMER0_u8CLOCK ;

									/* CONFIGURE CTC-Mode */

			TCCR0 &= CTC_MODE_MASK ;
			TCCR0 |= CTC_MODE_OPTION ;

									/* SET COMPARE VALUE */

			 OCR0 = TIMER0_u8CompareValue ;

									/* Timer/Counter0 Output Compare Match Interrupt Enable */

			 SET_BIT(TIMSK,TIMSK_OCIE0) ;

		#elif TIMER0_u8MODE == FAST_PWM_MODE
			SET_BIT (TCCR0,TCCR0_WGM00);
			SET_BIT (TCCR0,TCCR0_WGM01);

									/* CONFIGURE CLOCK SELECTION */

			TCCR0 &= PRESCALER_MASK ;
			TCCR0 |= TIMER0_u8CLOCK ;

									/* CONFIGURE CTC-Mode */

			TCCR0 &= CTC_MODE_MASK ;
			TCCR0 |= FAST_PWM_MODE_OPTION ;

				#if COMPARE_VALUE_GENERATION_METHOD == INITIALLY_SET

									/* SET COMPARE VALUE */

			OCR0 = TIMER0_u8CompareValue ;

				#endif

		#else
			#error Wrong TIMER0_u8MODE Configuration Value
		#endif

	}

	void TIMER0_voidSetCompVal (uint8 copy_u8CompVal)
	{
		OCR0 = copy_u8CompVal ;
	}
	void TIMER1_voidInit ( void )
	{

			#if TIMER1_u8MODE == NORMAL_MODE
											/* MODE SET */

				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

											/* CONFIGURE CLOCK SELECTION */

				TCCR1B &= PRESCALER_MASK ;
				TCCR1B |= TIMER1_u8CLOCK ;


			#elif TIMER1_u8MODE == PWM_Phase_Correct_8_bit

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == PWM_Phase_Correct_9_bit

				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == PWM_Phase_Correct_10_bit

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == CTC_MODE1

				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == Fast_PWM_8_bit

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == Fast_PWM_9_bit

				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == Fast_PWM_10_bit

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				CLR_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == PWM_Phase_and_Frequency_Correct1

				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == PWM_Phase_and_Frequency_Correct2

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == PWM_Phase_Correct1

				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == PWM_Phase_Correct2

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				CLR_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == CTC_MODE2

				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == RESERVED

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				CLR_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

			#elif TIMER1_u8MODE == Fast_PWM1
										/* MODE SET */
				CLR_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

										/* CONFIGURE CLOCK SELECTION */

				TCCR1B &= PRESCALER_MASK ;
				TCCR1B |= TIMER1_u8CLOCK ;

										/* CHANNEL SET */

				TCCR1A &= CHANNEL_MASK ;
				TCCR1A |= FAST_PWM_MODE_OPTION_CHANNELA ;
				TCCR1A |= FAST_PWM_MODE_OPTION_CHANNELB ;

					#if COMPARE_VALUE_GENERATION_METHOD_A == INITIALLY_SET

										/* SET COMPARE VALUE */

				OCR1AL = TIMER1_u8CompareValue_A ;

					#endif

					#if COMPARE_VALUE_GENERATION_METHOD_B == INITIALLY_SET

									/* SET COMPARE VALUE */

				OCR1B = TIMER1_u8CompareValue_B ;

					#endif
										/* SET TOP VALUE */

				ICR1 = TIMER1_u8TOPValue ;

			#elif TIMER1_u8MODE == Fast_PWM2

				SET_BIT (TCCR1A,TCCR1A_WGM10);
				SET_BIT (TCCR1A,TCCR1A_WGM11);
				SET_BIT (TCCR1B,TCCR1B_WGM12);
				SET_BIT (TCCR1B,TCCR1B_WGM13);

			#else
				#error Wrong TIMER1_u8MODE Configuration Value
			#endif

	}

	void TIMER1_voidSetAngle 		( uint16 copy_u16Val )
	{
		OCR1B = copy_u16Val ;
	}
	void TIMER1_voidSetTimerVal (uint16 copy_u16Val)
	{
		TCNT1 = copy_u16Val ;
	}

	uint16 TIMER1_u16GetTimerVal (void)
	{
		return TCNT1 ;
	}
	uint8 TIMER0_u8SetCallBack (  void(*copy_pvNotification)(void) )

		{
			uint8 Local_u8ErrorState = OK ;
			if (  copy_pvNotification != NULL  )
			{
						/* CONVERT THE NOTIFICATION FUNCTION LOCAL VARIABLES INTO GLOBAL */

				TIMER0_pvNotificationFunc = copy_pvNotification ;
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}

			return Local_u8ErrorState ;
		}

	uint8 TIMER1_u8SetCallBack (  void(*copy_pvNotification)(void) )

		{
			uint8 Local_u8ErrorState = OK ;
			if (  copy_pvNotification != NULL  )
			{
						/* CONVERT THE NOTIFICATION FUNCTION LOCAL VARIABLES INTO GLOBAL */

				TIMER1_pvNotificationFunc = copy_pvNotification ;
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}

			return Local_u8ErrorState ;
		}

	uint8 TIMER0_u8CounterFunction ( void )
	{

		uint32 Local_u32Iterator = 0 ;
							/* CONFIGURE CLOCK SELECTION */

		TCCR0 &= PRESCALER_MASK ;
		TCCR0 |= NO_CLOCK_SOURCE ;			// STOP THE CLOCK
		while (Local_u32Iterator <= 200000)
		{
			Local_u32Iterator ++ ;
		}
		TCCR0 &= PRESCALER_MASK ;
		TCCR0 |= TIMER0_u8CLOCK ;


		return TCNT0 ;
	}
												/* Timer/Counter0 Compare Match ISR */

	void __vector_10 ( void )			__attribute__((signal)) ;
	void __vector_10 ( void )
	{

			if ( TIMER0_pvNotificationFunc != NULL )
			{
				TIMER0_pvNotificationFunc() ;
			}
			else
			{
				// DO NOTHING
			}

	}


												/* Timer/Counter0 Overflow ISR */

	void __vector_11 ( void )			__attribute__((signal)) ;
	void __vector_11 ( void )
	{
			if ( TIMER0_pvNotificationFunc != NULL )
			{
				TIMER0_pvNotificationFunc() ;
			}
			else
			{
				// DO NOTHING
			}

	}



