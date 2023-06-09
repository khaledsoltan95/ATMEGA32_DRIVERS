#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "TIMER_Interface.h"
#include "TIMER_Prv.h"
#include "TIMER_Cfg.h"
#include "TIMER_Reg.h"

static uint16 TIMER_u16Counter = 0 ;
static void (*TIMER_pvNotificationFunc)(void) = NULL ;

	void TIMER_voidInitT0 ( void )
	{
		#if TIMER_u8MODE == NORMAL_MODE
			CLR_BIT (TCCR0,TCCR0_WGM00);
			CLR_BIT (TCCR0,TCCR0_WGM01);
		#elif TIMER_u8MODE == PWM_PHASE_CORRECT_MODE
			SET_BIT (TCCR0,TCCR0_WGM00);
			CLR_BIT (TCCR0,TCCR0_WGM01);
		#elif TIMER_u8MODE == CTC_MODE
			CLR_BIT (TCCR0,TCCR0_WGM00);
			SET_BIT (TCCR0,TCCR0_WGM01);
		#elif TIMER_u8MODE == FAST_PWM_MODE
			SET_BIT (TCCR0,TCCR0_WGM00);
			SET_BIT (TCCR0,TCCR0_WGM01);
		#else
			#error Wrong TIMER_u8MODE Configuration Value
		#endif

									/* CONFIGURE CLOCK SELECTION */

			TCCR0 &= CLOCK_SELECTION_MASK ;
			TCCR0 |= TIMER_u8CLOCK ;

									/*SET PRELOAD VALUE */

			TCNT0 = TIMER_u16PreloadValue ;

									/* Timer/Counter0 Overflow Interrupt Enable */

			SET_BIT(TIMSK,TIMSK_TOIE0) ;


	}
	uint8 TIMER_u8StartTimer (  void(*copy_pvNotification)(void) )

		{
			uint8 Local_u8ErrorState = OK ;
			if (  copy_pvNotification != NULL  )
			{
						/* CONVERT THE NOTIFICATION FUNCTION LOCAL VARIABLES INTO GLOBAL */

			TIMER_pvNotificationFunc = copy_pvNotification ;
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}

			return Local_u8ErrorState ;
		}


												/* Timer/Counter0 Overflow ISR */

	void __vector_11 ( void )			__attribute__((signal)) ;
	void __vector_11 ( void )
	{

		TIMER_u16Counter ++ ;
		if ( TIMER_u16Counter == 62500 )
		{
			if ( TIMER_pvNotificationFunc != NULL )
			{
				TIMER_pvNotificationFunc() ;
			}
			else
			{
				// DO NOTHING
			}
		}
	}



