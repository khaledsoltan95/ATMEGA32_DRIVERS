#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "DIO_Interface.h"

#include "LED_Interface.h"
#include "LED_Prv.h"
#include "LED_Cfg.h"

										/* Functions Initialization */

	uint8 LED_u8SetOn  ( const LED_Config_t* copy_LEDObject)
	{
		uint8 Local_u8ErrorState = OK ;
		if ( copy_LEDObject != NULL )
		{
			switch ( copy_LEDObject -> ActivityType )
			{
			case ACTIVE_HIGH : DIO_U8SetPinValue( copy_LEDObject -> Port , copy_LEDObject -> Pin , DIO_PIN_HIGH ); break ;
			case ACTIVE_LOW  : DIO_U8SetPinValue( copy_LEDObject -> Port , copy_LEDObject -> Pin , DIO_PIN_LOW ) ; break ;
			default : Local_u8ErrorState = NOK ; break ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}

	uint8 LED_u8SetOff ( const LED_Config_t* copy_LEDObject)
	{
		uint8 Local_u8ErrorState = OK ;
		if ( copy_LEDObject != NULL )
		{
			switch ( copy_LEDObject -> ActivityType )
			{
			case ACTIVE_HIGH : DIO_U8SetPinValue( copy_LEDObject -> Port , copy_LEDObject -> Pin , DIO_PIN_LOW ) ; break ;
			case ACTIVE_LOW  : DIO_U8SetPinValue( copy_LEDObject -> Port , copy_LEDObject -> Pin , DIO_PIN_HIGH) ; break ;
			default : Local_u8ErrorState = NOK ; break ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}

	uint8 LED_u8Toggle ( const LED_Config_t* copy_LEDObject)
	{
		uint8 Local_u8ErrorState = OK ;
		if ( copy_LEDObject != NULL )
		{
			DIO_u8TogglePinValue( copy_LEDObject -> Port , copy_LEDObject -> Pin );
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}
