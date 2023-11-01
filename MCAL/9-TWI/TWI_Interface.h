#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

#include "TWI_Reg.h"

	typedef enum
	{
		NoError ,
		Null_PTR_ERR ,
		StartCondErr ,
		RepStartErr ,
		SlaveAddressWithWriteErr ,
		SlaveAddressWithReadErr ,
		MasterWriteByteWithAckErr ,
		MasterReadByteWithAckErr ,
	}TWI_Errorstatus_t ;
	
											/* Functions Deceleration */

	uint8				TWI_u8MasterInit 						( uint8 copy_u8MasterAddress ) ;	/* IF MASTER IS NOT ADDRESSED IN THE NETWORK , PASS ADDRESS 0u */

	uint8 				TWI_u8SlaveInit							( uint8 copy_u8SlaveAddress ) ;

	TWI_Errorstatus_t 	TWI_voidSendStartCondition				( void ) ;

	TWI_Errorstatus_t 	TWI_voidSendRepeatedStart				( void ) ;

	TWI_Errorstatus_t 	TWI_voidSendSlaveAddressWithWrite		( uint8 copy_u8SlaveAddress ) ;

	TWI_Errorstatus_t 	TWI_voidSendSlaveAddressWithRead		( uint8 copy_u8SlaveAddress ) ;

	TWI_Errorstatus_t 	TWI_voidMasterWriteDataByte				( uint8 copy_u8DataByte ) ;

	TWI_Errorstatus_t 	TWI_voidMasterReadDataByte				( uint8* copy_u8DataByte ) ;

	void 				TWI_voidSendStopCondition				( void ) ;

	uint8 				TWI_u8SetCallBack						( void(*copy_pvNotification)(void) ) ;

	uint8 				TWI_u8TWBRInitValue 					(void) ;


#endif
