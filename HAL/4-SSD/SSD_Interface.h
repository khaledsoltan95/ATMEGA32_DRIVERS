#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

	typedef enum {
		SSD_u8PinZERO ,
		SSD_u8PinOne ,
	}SSD_LEDPin_t ;

	typedef enum {
		SSD_u8COMMON_ANODE ,
		SSD_u8COMMON_CATHODE ,
		SSD_u8ETA_KIT
	}SSD_Type_t ;

	typedef struct {
		SSD_Type_t 	SSD_Type ;
		DIO_Port_t 	SSD_Port ;
		DIO_Pin_t 	SSD_LEDAPin ;
		DIO_Port_t 	Enable_Port ;
		DIO_Pin_t 	Enable_Pin ;
	}SSD_Config_t ;

														/*Function Deceleration */

	uint8 SSD_u8SetNumber 		( SSD_Config_t * copy_SSDObject , uint8 copy_u8Number ) ;

	uint8 SSD_u8Enable		 	( const SSD_Config_t * copy_SSDObject ) ;

	uint8 SSD_u8Disable 		( const SSD_Config_t * copy_SSDObject ) ;
	
#endif 
