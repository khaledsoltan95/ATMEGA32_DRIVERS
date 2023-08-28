#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"


#include "TIMER_Interface.h"
#include "TIMER_Prv.h"
#include "TIMER_Cfg.h"
#include "TIMER_Reg.h"

static void (*TIMER0_pvNotificationFunc)(void) = NULL ;

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



