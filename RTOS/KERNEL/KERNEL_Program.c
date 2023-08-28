#include "STD_TYPES.h"
#include "ERR_TYPE.h"

#include "TIMER_Interface.h"

#include "KERNEL_Cfg.h"
#include "KERNEL_Interface.h"
#include "KERNEL_Private.h"

	static Task_t 	System_Tasks[TASK_NUM] = {{0}} ;			// INITIALIZE ALL TASKS TO ZERO {NULL}

	void 		RTOS_voidStart 		( void )
	{
		TIMER0_voidInit();
		TIMER0_voidSetCompVal	( 250U );
		TIMER0_u8SetCallBack	( &Scheduler ) ;
	}

	uint8 		RTOS_u8CreateTask 	( uint8 copy_u8Periority ,  uint16 copy_u16Periodicity , void(*copy_PvTaskFunc)(void) )
	{
		uint8 Local_u8ErrorState = OK ;

		if (copy_PvTaskFunc != NULL )
		{
			if ( System_Tasks[copy_u8Periority].TaskFunc == NULL )
			{
				System_Tasks[copy_u8Periority].Periodicity	= copy_u16Periodicity ;
				System_Tasks[copy_u8Periority].TaskFunc 	= copy_PvTaskFunc ;
				System_Tasks[copy_u8Periority].Status 		= TASK_RESUMED ;
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}

		return Local_u8ErrorState ;

	}

	static void Scheduler 			( void )
	{
		uint8 Local_u8TaskCounter ;
		static uint16 Local_u16TickCounter = 0u ;
		uint16 Local_u16ReservedTickCounter ;
		Local_u16TickCounter ++ ;
		if ( Local_u16TickCounter == MAX )
		{
			Local_u16TickCounter = MAX - Local_u16ReservedTickCounter ;
		}
		else
		{

			for ( Local_u8TaskCounter = 0 ; Local_u8TaskCounter < TASK_NUM ; Local_u8TaskCounter ++ )
			{
				if ( System_Tasks[Local_u8TaskCounter].TaskFunc != NULL )
				{
					if ( ( Local_u16TickCounter % System_Tasks[Local_u8TaskCounter].Periodicity == 0 ) && ( System_Tasks[Local_u8TaskCounter].Status == TASK_RESUMED ) )
					{
							/* INVOKE THE TASK FUNCTION */

							System_Tasks[Local_u8TaskCounter].TaskFunc() ;
							Local_u16ReservedTickCounter = Local_u16TickCounter ;
					}
					else
					{
						// THERE IS NO TASK TO RUN OR TASK IS SUSPENDED
					}
					}
				else
				{
					// TASK FUNCTION IS NULL
				}
			}
		}
	}

	void 		RTOS_voidSuspendTask( uint8 copy_u8Periority )
	{
		System_Tasks[copy_u8Periority].Status = TASK_SUSPENDED ;
	}

	void 		RTOS_voidResumeTask	( uint8 copy_u8Periority )
	{
		System_Tasks[copy_u8Periority].Status = TASK_RESUMED ;
	}

	void 		RTOS_voidDeleteTask	( uint8 copy_u8Periority )
	{
		System_Tasks[copy_u8Periority].TaskFunc = NULL ;
	}
