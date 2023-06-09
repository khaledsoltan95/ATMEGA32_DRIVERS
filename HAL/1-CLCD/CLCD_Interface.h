#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

					/*Function Deceleration */
					
	void CLCD_voidSendCommand			( uint8 Copy_u8Command)                 				  										  ;
	void CLCD_voidSendData   			( uint8 copy_u8Data)                    				  										  ;
	void CLCD_voidInit       			( void )                                 				  										  ;
	void voidSendString 				( char *copy_pu8String )                                				  										  ;
	void voidSendNumber      			( sint32 copy_s32Number)            														      ;
	void CLCD_voidGoToXY 				( uint8 copy_u8XPos , uint8 copy_u8YPos)				  										  ;
	uint8 CLCD_u8WriteSpecialCharacter	( uint8 copy_u8PatternNumber , uint8 copy_pu8PatternArr[], uint8 copy_u8XPos , uint8 copy_u8YPos );
	
#endif 
