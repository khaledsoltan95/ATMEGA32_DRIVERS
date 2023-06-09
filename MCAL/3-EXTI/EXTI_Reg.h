#ifndef EXTI_REG_H
#define EXTI_REG_H

					/* Definitions */
	#define 		MCUCR 			*((volatile uint8*)0x55)       // MCU CTRL REGISTER
	#define 		MCUCR_ISC00		0u							   // INT.SENSE CTRL 0 BIT 0
	#define 		MCUCR_ISC01		1U							   // INT.SENSE CTRL 0 BIT 1
	#define 		MCUCR_ISC10		2U							   // INT.SENSE CTRL 0 BIT 1
	#define 		MCUCR_ISC11		3U							   // INT.SENSE CTRL 1 BIT 1

	#define 		MCUCSR  		*((volatile uint8*)0x54)       // MCU CTRL AN STATUS REGISTER
	#define 		MCUCSR_ISC2		6U							   // INT.SENSE CTRL 2
	
	#define	 		GICR 			*((volatile uint8*)0x5B)       // GENERAL INT CTRL REGISTER
	#define 		GICR_INT1		7U							   // INTERRUPT 1
	#define 		GICR_INT0		6U							   // INTERRUPT 0
	#define 		GICR_INT2		5U							   // INTERRUPT 2

	#define	 		GIFR 			*((volatile uint8*)0x5A)       // GENERAL INT FLAG REGISTER
	#define 		GIFR_INTF1		7U							   // INTERRUPT 1
	#define 		GIFR_INTF0		6U							   // INTERRUPT 0
	#define 		GIFR_INTF2		5U							   // INTERRUPT 2
	
#endif
