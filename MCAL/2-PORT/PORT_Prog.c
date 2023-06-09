#include "STD_TYPES.h"

#include "PORT_Cfg.h"
#include "PORT_Prv.h"
#include "PORT_Reg.h"
#include "PORT_Interface.h"

	void PORT_voidInit ( void ) 
	{
		DDRA  = PORTA_DIR     ; 
		DDRB  = PORTB_DIR     ;
		DDRC  = PORTC_DIR     ;
		DDRD  = PORTD_DIR     ;
		
		PORTA = PORTA_INITVAL ; 
		PORTB = PORTB_INITVAL ; 
		PORTC = PORTC_INITVAL ; 
		PORTD = PORTD_INITVAL ; 
	}