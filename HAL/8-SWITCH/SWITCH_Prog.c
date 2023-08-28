#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "DIO_Interface.h"

#include "SWITCH_Interface.h"
#include "SWITCH_Prv.h"
#include "SWITCH_Cfg.h"

										/* Functions Initialization */

	uint8 SWITCH_u8GetState  ( const SWITCH_Config_t* copy_SWITCHObject , uint8* copy_SWITCHState )
	{
		uint8 Local_u8ErrorState = OK ;
		uint8 Local_u8SwitchState ;
		if ( ( copy_SWITCHObject != NULL ) && ( copy_SWITCHState != NULL ) )
		{
			DIO_u8GetPinValue(copy_SWITCHObject -> Port ,copy_SWITCHObject -> Pin ,&Local_u8SwitchState);

			if (Local_u8SwitchState == DIO_PIN_LOW)
			{

				switch ( copy_SWITCHObject -> PullType )
				{
				case PULL_UP   : *copy_SWITCHState = SWITCH_PRESSED  ; break ;
				case PULL_DOWN : *copy_SWITCHState = SWITCH_RELEASED ; break ;
				default : Local_u8ErrorState = NOK ;
				}
			}
			else if (Local_u8SwitchState == DIO_PIN_HIGH)
			{
				switch ( copy_SWITCHObject -> PullType )
				{
				case PULL_UP   : *copy_SWITCHState = SWITCH_RELEASED  ; break ;
				case PULL_DOWN : *copy_SWITCHState = SWITCH_PRESSED   ; break ;
				default : Local_u8ErrorState = NOK ;
				}
			}
			else
			{
				// DO NOTHING
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}
