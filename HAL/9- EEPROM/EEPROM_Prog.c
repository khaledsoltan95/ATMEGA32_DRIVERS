#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include <util/delay.h>

#include "TWI_Interface.h"

#include "EEPROM_Interface.h"
#include "EEPROM_Cfg.h"
#include "EEPROM_Prv.h"

										/* Functions Initialization */

void EEPROM_voidWriteDataByte ( uint16 copy_u16MemoryAddress , uint8 copy_u8DataByte )
{
	uint8 Local_u8SlaveAddress = EEPROM_FIXED_ADDRESS | ( A2_CONNECTION <<2 ) | ( ( copy_u16MemoryAddress >> 8 ) & 0X3 );

												/* SEND START CONDITION */

	TWI_voidSendStartCondition() ;

												/* SEND SLAVE ADDRESS WITH WRITE */

	TWI_voidSendSlaveAddressWithWrite( Local_u8SlaveAddress ) ;

												/* SEND MEMORY LOCATION ADDRESS */

	TWI_voidMasterWriteDataByte( (uint8) copy_u16MemoryAddress) ;

												/* SEND DATA */

	TWI_voidMasterWriteDataByte( copy_u8DataByte ) ;

												/* SEND STOP CONDITION */

	TWI_voidSendStopCondition() ;

												/* delay 10 mSec */
	_delay_ms(10) ;

}

uint8 EEPROM_u8ReadDataByte ( uint16 copy_u16MemoryAddress )
{
	uint8 Local_u8ReceivedData ;

	uint8 Local_u8SlaveAddress = EEPROM_FIXED_ADDRESS | ( A2_CONNECTION <<2 ) | ( ( copy_u16MemoryAddress >> 8 ) & 0X3 );

												/* SEND START CONDITION */

	TWI_voidSendStartCondition() ;

												/* SEND SLAVE ADDRESS WITH WRITE */

	TWI_voidSendSlaveAddressWithWrite( Local_u8SlaveAddress ) ;

												/* SEND MEMORY LOCATION ADDRESS */

	TWI_voidMasterWriteDataByte( (uint8) copy_u16MemoryAddress) ;

												/* SEND REPEATED START TO CHANGE THE OPERATION TO READ OPERATION */

	TWI_voidSendRepeatedStart() ;

												/* SEND SLAVE ADDRESS WITH READ */

	TWI_voidSendSlaveAddressWithRead( Local_u8SlaveAddress ) ;

												/* READ DATA FROM SLAVE EEPROM */

	TWI_voidMasterReadDataByte( &Local_u8ReceivedData ) ;

												/* SEND STOP CONDITION */

	TWI_voidSendStopCondition() ;

												/* RETURN RECEIVED DATA */

	return Local_u8ReceivedData ;

}
