#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
	
											/* Functions Deceleration */
	void TIMER_voidInitT0 ( void ) ;

	uint8 TIMER_u8StartTimer (  void(*copy_pvNotification)(void) ) ;
#endif
