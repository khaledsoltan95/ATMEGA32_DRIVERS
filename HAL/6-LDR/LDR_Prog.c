#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "ADC_Interface.h"

#include "LDR_Interface.h"
#include "LDR_Prv.h"
#include "LDR_Cfg.h"

										/* Functions Initialization */

	uint16 LDR_u16PreconfigGetLightLevel ( void )
	{
		uint16 Local_u16ChannelReading ;

		ADC_u8StartSingleConversionSynch(LDR_ADC_CHANNEL,&Local_u16ChannelReading);

		return Local_u16ChannelReading ;

	}

	uint16 LDR_u16PostconfigGetLightLevel ( uint8 Local_u8ADC_ChannelSelect )
	{
		uint16 Local_u16ChannelReading ;

		ADC_u8StartSingleConversionSynch(Local_u8ADC_ChannelSelect,&Local_u16ChannelReading);

		return Local_u16ChannelReading ;

	}
