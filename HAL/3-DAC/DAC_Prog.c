#include "STD_TYPES.h"
#include "ERR_TYPE.h"

#include "DIO_Interface.h" 

#include "DAC_Interface.h"
#include "DAC_Prv.h"
#include "DAC_Cfg.h"

										/* Functions Initialization */

	uint8 DAC_voidSetAnalogVolt ( uint16 copy_u16Volt )
	{
		uint8 Local_u8ErrorState = OK ;
		if ( copy_u16Volt <= DAC_u16ReferenceVolt )
		{
			DIO_U8SetPortValue( DAC_u8PORT , (copy_u16Volt / DAC_u8Step) ) ;  			// DIGITAL VALUE = ANALOG VALUE / STEP
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
		return Local_u8ErrorState ;
	}
