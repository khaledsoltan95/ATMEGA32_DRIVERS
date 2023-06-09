#ifndef DAC_CFG_H
#define DAC_CFG_H

					/* DAC CONFIGURATIONS */

	#define 	DAC_u8PORT    				DIO_PORTB

	#define 	DAC_u16ReferenceVolt		5000u										// 5000 mVolt
	#define 	DAC_u16Resolution			256u										// FOR 8-BIT RESOLUTION : RESOLUTION = 2^8
	#define 	DAC_u8Step				 	(DAC_u16ReferenceVolt/DAC_u16Resolution)	// STEP = (REFERENCE VOLT / (2^RESOLUTION))

#endif
