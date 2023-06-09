#include "STD_TYPES.h"

#include "ERR_TYPE.h"

#include "DIO_Interface.h" 


#include "KPD_Interface.h" 
#include "KPD_Prv.h" 
#include "KPD_Cfg.h"

										/* Functions Initialization */
		uint8 KPD_u8GetPressedKey ( void ) 
		{
			uint8 Local_u8RowCounter , Local_u8ColCounter , Local_u8KeyState , Local_u8PressedKey = KPD_u8NO_PRESSED_KEY_VAL  ;
			static uint8 Local_u8ColArr[ COL_NUM ] = { KPD_u8CO_PIN , KPD_u8C1_PIN , KPD_u8C2_PIN , KPD_u8C3_PIN };
			static uint8 Local_u8RowArr[ ROW_NUM ] = { KPD_u8RO_PIN , KPD_u8R1_PIN , KPD_u8R2_PIN , KPD_u8R3_PIN };
			static uint8 Local_u8KPDArr[ ROW_NUM ] [ COL_NUM ] = KPD_u8BUTTON_ARR ;
			
										/* Activate the Column PINS */

			for ( Local_u8ColCounter = 0U ; Local_u8ColCounter < COL_NUM ; Local_u8ColCounter ++ )
			{
										/* Activate the current column */

				DIO_U8SetPinValue ( KPD_u8COL_PORT , Local_u8ColArr [ Local_u8ColCounter ] , DIO_PIN_LOW  ) ;

										/* Read the Row PINS */

				for ( Local_u8RowCounter = 0U ; Local_u8RowCounter < ROW_NUM ; Local_u8RowCounter ++)
				{
										/* READ the current ROW */
					DIO_u8GetPinValue( KPD_u8ROW_PORT , Local_u8RowArr [ Local_u8RowCounter ] , &Local_u8KeyState ) ;
					if ( Local_u8KeyState == DIO_PIN_LOW )
					{
						Local_u8PressedKey = Local_u8KPDArr [ Local_u8RowCounter ] [ Local_u8ColCounter ] ;

										/* WAIT UNTIL KEY IS RELEASED ( POLLING WITH BLOCKING ON PIN READING ) */

						while ( Local_u8KeyState == DIO_PIN_LOW )
						{
							DIO_u8GetPinValue( KPD_u8ROW_PORT , Local_u8RowArr [ Local_u8RowCounter ] , &Local_u8KeyState ) ;
						}
						return Local_u8PressedKey ;
					}
				}

										/* DEACTIVATE THE CURRENT COLUMN */

				DIO_U8SetPinValue ( KPD_u8COL_PORT , Local_u8ColArr [ Local_u8ColCounter ] , DIO_PIN_HIGH  ) ;

			}
			return Local_u8PressedKey ;
		}
