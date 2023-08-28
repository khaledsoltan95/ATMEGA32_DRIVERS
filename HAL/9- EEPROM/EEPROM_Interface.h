#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

	void EEPROM_voidWriteDataByte ( uint16 copy_u16MemoryAddress , uint8 copy_u8DataByte ) ;
	
	uint8 EEPROM_u8ReadDataByte ( uint16 copy_u16MemoryAddress ) ;

#endif 
