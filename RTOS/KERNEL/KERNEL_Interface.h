#ifndef 	KERNEL_INTERFACE_H 
#define 	KERNEL_INTERFACE_H 


	void 	RTOS_voidStart 		( void ) ; 

	uint8 	RTOS_u8CreateTask 	( uint8 copy_u8Periority ,  uint16 copy_u16Periodicity , void(*copy_PvTaskFunc)(void) ) ;

	void 	RTOS_voidSuspendTask( uint8 copy_u8Periority ) ;

	void 	RTOS_voidResumeTask	( uint8 copy_u8Periority ) ;

	void 	RTOS_voidDeleteTask	( uint8 copy_u8Periority ) ;

#endif
