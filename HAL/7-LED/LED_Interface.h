#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

	typedef enum
	{
		ACTIVE_HIGH ,
		ACTIVE_LOW
	}LED_Act_t ;

	typedef struct
	{
		DIO_Port_t Port ;
		DIO_Pin_t  Pin ;
		LED_Act_t ActivityType ;
	}LED_Config_t ;

	uint8 LED_u8SetOn  ( const LED_Config_t* copy_LEDObject);

	uint8 LED_u8SetOff ( const LED_Config_t* copy_LEDObject);

	uint8 LED_u8Toggle ( const LED_Config_t* copy_LEDObject);
	
#endif 
