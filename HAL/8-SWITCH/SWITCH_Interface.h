#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

	typedef enum
	{
		SWITCH_PRESSED ,
		SWITCH_RELEASED
	}SWITCH_State_t ;

	typedef enum
	{
		PULL_UP ,
		PULL_DOWN
	}SWITCH_PullType_t ;

	typedef struct
	{
		DIO_Port_t Port ;
		DIO_Pin_t  Pin ;
		SWITCH_PullType_t PullType ;
	}SWITCH_Config_t ;

	uint8 SWITCH_u8GetState  ( const SWITCH_Config_t* copy_SWITCHObject , uint8* copy_SWITCHState );
	
#endif 
