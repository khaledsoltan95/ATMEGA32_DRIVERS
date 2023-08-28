#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "DIO_Interface.h" 

#include "SSD_Interface.h"
#include "SSD_Prv.h"
#include "SSD_Cfg.h"

										/* Functions Initialization */

	uint8 SSD_u8SetNumber 		( SSD_Config_t * copy_SSDObject , uint8 copy_u8Number )
	{
		uint8 Local_u8ErrorState = OK ;
		if (copy_SSDObject != NULL)
		{
			if (copy_u8Number <= 9U )
			{
										/* ARRAY OF NUMBERS FROM 0 TO 9 DECLERATION */

				static uint8 SSD_Arr[10]= {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01100111};

										/* CHECK THE START LED */
				if ( ( copy_SSDObject -> SSD_Type == SSD_u8COMMON_CATHODE ) || ( copy_SSDObject -> SSD_Type == SSD_u8ETA_KIT ) )
				{

					switch ( copy_SSDObject -> SSD_LEDAPin )
					{
					case SSD_u8PinZERO   :  DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN0 , GET_BIT(SSD_Arr[copy_u8Number] , 0 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN1 , GET_BIT(SSD_Arr[copy_u8Number] , 1 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN2 , GET_BIT(SSD_Arr[copy_u8Number] , 2 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN3 , GET_BIT(SSD_Arr[copy_u8Number] , 3 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN4 , GET_BIT(SSD_Arr[copy_u8Number] , 4 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN5 , GET_BIT(SSD_Arr[copy_u8Number] , 5 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN6 , GET_BIT(SSD_Arr[copy_u8Number] , 6 ) ) ;
											break ;
					case SSD_u8PinOne	 : 	DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN1 , GET_BIT(SSD_Arr[copy_u8Number] , 0 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN2 , GET_BIT(SSD_Arr[copy_u8Number] , 1 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN3 , GET_BIT(SSD_Arr[copy_u8Number] , 2 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN4 , GET_BIT(SSD_Arr[copy_u8Number] , 3 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN5 , GET_BIT(SSD_Arr[copy_u8Number] , 4 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN6 , GET_BIT(SSD_Arr[copy_u8Number] , 5 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN7 , GET_BIT(SSD_Arr[copy_u8Number] , 6 ) ) ;
											break ;
					default : Local_u8ErrorState = NOK ; break ;
					}
				}
				else if ( copy_SSDObject -> SSD_Type == SSD_u8COMMON_ANODE )
				{
					switch ( copy_SSDObject -> SSD_LEDAPin )
					{
					case SSD_u8PinZERO   :  DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN0 , ~ GET_BIT(SSD_Arr[copy_u8Number] , 0 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN1 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 1 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN2 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 2 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN3 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 3 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN4 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 4 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN5 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 5 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN6 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 6 ) ) ;
											break ;
					case SSD_u8PinOne	 : 	DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN1 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 0 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN2 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 1 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN3 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 2 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN4 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 3 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN5 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 4 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN6 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 5 ) ) ;
											DIO_U8SetPinValue(copy_SSDObject -> SSD_Port , DIO_PIN7 , ~	GET_BIT(SSD_Arr[copy_u8Number] , 6 ) ) ;
											break ;
					default : Local_u8ErrorState = NOK ; break ;
					}
				}
				else
				{
					Local_u8ErrorState = NOK ;
				}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}

	uint8 SSD_u8Enable		 	( const SSD_Config_t * copy_SSDObject )
	{
		uint8 Local_u8ErrorState = OK ;
		if (copy_SSDObject != NULL)
		{
					/* CHECKING THE TYPE OF SSD */

			switch ( copy_SSDObject -> SSD_Type )
			{
			case SSD_u8COMMON_ANODE   : DIO_U8SetPinValue(copy_SSDObject -> Enable_Port , copy_SSDObject ->Enable_Pin , DIO_PIN_HIGH );	break ;
			case SSD_u8COMMON_CATHODE : DIO_U8SetPinValue(copy_SSDObject -> Enable_Port , copy_SSDObject ->Enable_Pin , DIO_PIN_LOW );	break ;
			case SSD_u8ETA_KIT        : DIO_U8SetPinValue(copy_SSDObject -> Enable_Port , copy_SSDObject ->Enable_Pin , DIO_PIN_HIGH );	break ;
			default : Local_u8ErrorState = NOK ; break ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}

	uint8 SSD_u8Disable 		( const SSD_Config_t * copy_SSDObject )
	{
		uint8 Local_u8ErrorState = OK ;
		if (copy_SSDObject != NULL)
		{
					/* CHECKING THE TYPE OF SSD */

			switch ( copy_SSDObject -> SSD_Type )
			{
			case SSD_u8COMMON_ANODE   : DIO_U8SetPinValue(copy_SSDObject -> Enable_Port , copy_SSDObject ->Enable_Pin , DIO_PIN_LOW );	break ;
			case SSD_u8COMMON_CATHODE : DIO_U8SetPinValue(copy_SSDObject -> Enable_Port , copy_SSDObject ->Enable_Pin , DIO_PIN_HIGH );	break ;
			case SSD_u8ETA_KIT        : DIO_U8SetPinValue(copy_SSDObject -> Enable_Port , copy_SSDObject ->Enable_Pin , DIO_PIN_LOW );	break ;
			default : Local_u8ErrorState = NOK ; break ;
			}
		}
		else
		{
			Local_u8ErrorState = NULL_PTR ;
		}
		return Local_u8ErrorState ;
	}
