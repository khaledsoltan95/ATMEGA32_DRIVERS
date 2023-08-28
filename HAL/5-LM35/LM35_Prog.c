#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "ADC_Interface.h"

#include "LM35_Interface.h"
#include "LM35_Prv.h"
#include "LM35_Cfg.h"

										/* Functions Initialization */

	uint8 LM35_u8GetTemperature ( void )
	{
		uint16 Local_u16ChannelReading ;

		volatile uint8 Local_u8TemperatureReading ;

		ADC_u8StartSingleConversionSynch(LM35_ADC_CHANNEL,&Local_u16ChannelReading);

		Local_u8TemperatureReading = (uint8)((( uint32 )Local_u16ChannelReading*500UL)/256UL);        // TEMPERATURE EQUATION

		return Local_u8TemperatureReading ;

	}
