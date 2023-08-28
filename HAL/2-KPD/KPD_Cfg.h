#ifndef KPD_CFG_H
#define KPD_CFG_H

					/* KPD CONFIGURATIONS */

		#define		KPD

		#define 	KPD_u8ROW_PORT 				DIO_PORTB

		#define 	KPD_u8RO_PIN				DIO_PIN4
		#define 	KPD_u8R1_PIN				DIO_PIN5
		#define 	KPD_u8R2_PIN				DIO_PIN6
		#define 	KPD_u8R3_PIN				DIO_PIN7

		#define 	KPD_u8COL_PORT 				DIO_PORTD

		#define 	KPD_u8CO_PIN				DIO_PIN2
		#define 	KPD_u8C1_PIN				DIO_PIN3
		#define 	KPD_u8C2_PIN				DIO_PIN4
		#define 	KPD_u8C3_PIN				DIO_PIN5

		#define 	KPD_u8BUTTON_ARR			{ {55,56,57,47} , {52,53,54,42} , {49,50,51,45} , {127,48,61,43} }
		#define   	KPD_u8NO_PRESSED_KEY_VAL 	0xff



#endif
