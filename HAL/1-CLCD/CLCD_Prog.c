#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "ERR_TYPE.h"

#include "DIO_Interface.h" 

#include "CLCD_Interface.h" 
#include "CLCD_Prv.h" 
#include "CLCD_Cfg.h"

						/* Functions Initialization */
#if			CLCD_U8CONNECTION_MODE == FOUR_BIT
static void voidSetHalfDataPort (uint8 copy_u8FourBitData)
{
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D4_PIN,GET_BIT(copy_u8FourBitData,0)) ;
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D5_PIN,GET_BIT(copy_u8FourBitData,1)) ;
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D6_PIN,GET_BIT(copy_u8FourBitData,2)) ;
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D7_PIN,GET_BIT(copy_u8FourBitData,3)) ;
}
#endif

static void voidSendEnablePulse ( void )
{
	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW);
}

void CLCD_voidSendCommand ( uint8 Copy_u8Command )
{
					// 1-Set RS pin low for command

	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_LOW);

					// 2- Set RW pin to low for write

	#if 		CLCD_u8READ_OPERATION_ENABLE == ENABLED
	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
	#endif

					// 3- Send the command

	#if			CLCD_U8CONNECTION_MODE == FOUR_BIT
					/* Send The Higher 4 Bits */
	voidSetHalfDataPort( Copy_u8Command >> 4u ) ;
								//
					/*  Send Enable Pulse */
	voidSendEnablePulse () ;
								//
					/* Send The Lower 4 Bits */
	voidSetHalfDataPort( Copy_u8Command ) ;
								//
	#elif 		CLCD_U8CONNECTION_MODE == EIGHT_BIT
	DIO_U8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Command);
	#endif

					// 4- Send Enable Pulse

	voidSendEnablePulse () ;

}
void CLCD_voidSendData   (uint8 copy_u8Data)
{
					// 1-Set RS pin High for data sending

	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_HIGH);

					// 2- Set RW pin to low for write

	#if 		CLCD_u8READ_OPERATION_ENABLE == ENABLED
	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
	#endif

					// 3- Send the data

	#if			CLCD_U8CONNECTION_MODE == FOUR_BIT
					/* Send The Higher 4 Bits */
	voidSetHalfDataPort( copy_u8Data >> 4u ) ;
								//
					/*  Send Enable Pulse */
	voidSendEnablePulse () ;
								//
					/* Send The Lower 4 Bits */
	voidSetHalfDataPort( copy_u8Data ) ;
							//
	#elif 		CLCD_U8CONNECTION_MODE == EIGHT_BIT
	DIO_U8SetPortValue(CLCD_u8DATA_PORT,copy_u8Data);
	#endif

					// 4- Send Enable Pulse

	voidSendEnablePulse () ;

}
void CLCD_voidInit       (void)
{
		//1- WAIT FOR MORE THAN 30ms after POWER ON

	_delay_ms(40);

		//2-Function Set Command : 2 lines , font size 5*7

	#if			CLCD_U8CONNECTION_MODE == FOUR_BIT
					/* Sending Command into 3 Steps */
	voidSetHalfDataPort( 0b0010 ) ;
	voidSendEnablePulse ();
	voidSetHalfDataPort( 0b0010 ) ;
	voidSendEnablePulse ();
	voidSetHalfDataPort( 0b1000 ) ;
	voidSendEnablePulse ();
									//
	#elif 		CLCD_U8CONNECTION_MODE == EIGHT_BIT
	CLCD_voidSendCommand(0b00111000);
	#endif

		//3- WAIT FOR MORE THAN 39 uSec ( already done before )

		//4-Function Set Command for Display on/off control : Display on , cursor off , Blink cursor off

	CLCD_voidSendCommand(0b00001100);

		//5- WAIT FOR MORE THAN 39 uSec ( already done before )

		//6- Clear Display

	CLCD_voidSendCommand(1);

		//7- Entry Mode Set ( Skip It )

}

void voidSendString 	( char *copy_pu8String )
{
	uint8 local_u8StringCounter = 0 ;
	uint8 local_u8Iterator = 0 ;
	for (local_u8Iterator=0 ; *(copy_pu8String+local_u8Iterator) != '\0' ; local_u8Iterator ++ )
	{
		local_u8StringCounter ++ ;
	}
	for (local_u8Iterator = 0 ; local_u8Iterator <= local_u8StringCounter-1 ; local_u8Iterator ++ )
	{
		CLCD_voidSendData(copy_pu8String[local_u8Iterator]);
	}

}

void voidSendNumber		( sint32 copy_s32Number )
{
    if (copy_s32Number < 0)
	{
	    CLCD_voidSendData('-');
	    copy_s32Number=-copy_s32Number ;
	}
    else if (copy_s32Number == 0 )
    {
    	CLCD_voidSendData('0');
    	return ;
    }
	sint32 local_s32NumberSend = copy_s32Number ;
	sint32 local_s32NumberDiv  = copy_s32Number ;
	uint8 local_u8DigitCounter = 0 ;
	uint8 local_u8Iterator ;
						/* Calculate The Number Of Digits in Number Sent To Function */
	while (local_s32NumberSend != 0)
	{
		local_s32NumberSend /= 10 ;
		local_u8DigitCounter++ ;
	}
						/* Save The Value in Array As Separated Digits */
	uint8 local_u8ArrSize = local_u8DigitCounter ;
	uint8 local_u8NumberSendArr[local_u8ArrSize];
	while (local_s32NumberDiv != 0)
	{
		local_u8NumberSendArr[local_u8ArrSize-1] = (local_s32NumberDiv % 10) ;
		local_s32NumberDiv /=10 ;
		local_u8ArrSize -- ;
	}
	for (local_u8Iterator=0 ; local_u8Iterator < (local_u8DigitCounter) ; local_u8Iterator ++ )
		{
			CLCD_voidSendData(local_u8NumberSendArr[local_u8Iterator]+'0');
		}
}

void CLCD_voidGoToXY 		( uint8 copy_u8XPos ,uint8 copy_u8YPos )
{

	uint8 Local_u8DDRamAdd = ( copy_u8YPos * 0x40u ) + copy_u8XPos ;

						/* Set Bit 7 for Setting DDRAM Address Command */

	SET_BIT( Local_u8DDRamAdd , 7U);

											//

						/* Send The Setting DDRAM Address Command */

	CLCD_voidSendCommand( Local_u8DDRamAdd );

											//

}

uint8 CLCD_u8WriteSpecialCharacter	( uint8 copy_u8PatternNumber , uint8 copy_pu8PatternArr[] , uint8 copy_u8XPos , uint8 copy_u8YPos)
{

	uint8 Local_u8ErrorStatus = OK ;
	if ( copy_pu8PatternArr != NULL )
	{

		uint8 Local_u8CGRAMAdd = copy_u8PatternNumber * 8u ;
		uint8 Local_u8Iterator ;

						/* Set Bit 6 & Clear Bit 7 for Setting CGRAM Address Command */

		SET_BIT( Local_u8CGRAMAdd , 6U ) ;

												//

						/* Set CGRAM Address */

		CLCD_voidSendCommand( Local_u8CGRAMAdd );

											   //

						/* Write the pattern inside CGRAM */

		for ( Local_u8Iterator = 0u ; Local_u8Iterator < 8u ; Local_u8Iterator ++)
		{
			CLCD_voidSendData( copy_pu8PatternArr [ Local_u8Iterator ] );
		}

											  //

						/* Set DDRAM Address */

		CLCD_voidGoToXY( copy_u8XPos , copy_u8YPos ) ;

											 //

						/* Write the corresponding pattern number to display from CGRAM */

		CLCD_voidSendData( copy_u8PatternNumber ) ;

											//

	}
	else
	{

		Local_u8ErrorStatus = NULL_PTR ;

	}

	return Local_u8ErrorStatus  ;

}

