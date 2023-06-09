#ifndef  CLCD_PRV_H
#define  CLCD_PRV_H

						/* Private Functions Deceleration & Initialization */
						
	#define 	FOUR_BIT		1U
	#define 	EIGHT_BIT		2U

	#define 	ENABLED			1U
	#define 	DISABLED		2U

	#if			CLCD_U8CONNECTION_MODE == FOUR_BIT
	static void voidSetHalfDataPort (uint8 copy_u8FourBitData);
	#endif

	static void voidSendEnablePulse ( void );

#endif
