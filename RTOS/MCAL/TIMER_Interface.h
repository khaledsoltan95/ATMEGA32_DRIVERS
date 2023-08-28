#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
	
											/* Functions Deceleration */

	void TIMER0_voidInit			( void ) ;

	void TIMER0_voidSetCompVal 		( uint8 copy_u8CompVal);

	uint8 TIMER0_u8CounterFunction 	( void ) ;

	uint8 TIMER0_u8SetCallBack		( void(*copy_pvNotification)(void) ) ;

	void TIMER1_voidInit 			( void ) ;

	void TIMER1_voidSetAngle 		( uint16 copy_u16Val ) ;

	uint16 TIMER1_u16GetTimerVal 	( void ) ;

	void TIMER1_voidSetTimerVal 	( uint16 copy_u16Val ) ;

	uint8 TIMER1_u8SetCallBack 		( void(*copy_pvNotification)(void) ) ;



#endif
