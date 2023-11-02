#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

											/* TIMER 0 REGISTERS */

		#define 	TCCR0                	*((volatile uint8*)0x53)	  	/*TIMER/COUNTER CONTROL REGISTER*/
		#define 	TCCR0_FOC0			 	7u                           	/*FORCE OUTPUT COMPARE*/
		#define 	TCCR0_WGM00			 	6u                           	/*WAVEFORM GENERATION MODE*/
		#define 	TCCR0_COM01			 	5u                           	/*COMPARE MATCH OUTPUT MODE*/
		#define 	TCCR0_COM00			 	4u                           	/*COMPARE MATCH OUTPUT MODE*/
		#define 	TCCR0_WGM01			 	3u                           	/*WAVEFORM GENERATION MODE*/
		#define 	TCCR0_CS02			 	2u                           	/*CLOCK SELECT*/
		#define 	TCCR0_CS01				1u                           	/*CLOCK SELECT*/
		#define 	TCCR0_CS00			 	0u                           	/*CLOCK SELECT*/

		#define 	TCNT0               	*((volatile uint8*)0x52)		/*TIMER/COUNTER REGISTER*/

		#define 	OCR0                	*((volatile uint8*)0x5C)		/*OUTPUT COMPARE REGISTER*/

											/* TIMER 1 REGISTERS */

		#define 	TCCR1A               	*((volatile uint8*)0x4F)	  	/*Timer/Counter1 Control Register A*/
		#define 	TCCR1A_COM1A1		 	7u                           	/*Compare Output Mode for Channel A*/
		#define 	TCCR1A_COM1A0			6u                           	/*Compare Output Mode for Channel A*/
		#define 	TCCR1A_COM1B1			5u                           	/*Compare Output Mode for Channel B*/
		#define 	TCCR1A_COM1B0			4u                           	/*Compare Output Mode for Channel B*/
		#define 	TCCR1A_FOC1A			3u                           	/*Force Output Compare for Channel A*/
		#define 	TCCR1A_FOC1B			2u                           	/*Force Output Compare for Channel B*/
		#define 	TCCR1A_WGM11			1u                           	/*Waveform Generation Mode*/
		#define 	TCCR1A_WGM10			0u                           	/*Waveform Generation Mode*/

		#define 	TCCR1B               	*((volatile uint8*)0x4E)	  	/*Timer/Counter1 ControlRegister B*/
		#define 	TCCR1B_ICNC1		 	7u                           	/*Input Capture Noise Canceler*/
		#define 	TCCR1B_ICES1			6u                           	/*Input Capture Edge Select*/
		#define 	TCCR1B_RESERVED			5u                           	/*Reserved Bit*/
		#define 	TCCR1B_WGM13			4u                           	/*Waveform Generation Mode*/
		#define 	TCCR1B_WGM12			3u                           	/*Waveform Generation Mode*/
		#define 	TCCR1B_CS12				2u                           	/*Clock Select*/
		#define 	TCCR1B_CS11				1u                           	/*Clock Select*/
		#define 	TCCR1B_CS10				0u                           	/*Clock Select*/

		#define 	TCNT1H               	*((volatile uint8*)0x4D)		/*Timer/Counter1 REGISTER*/
		#define 	TCNT1L             		*((volatile uint8*)0x4C)		/*Timer/Counter1 REGISTER*/
		#define 	TCNT1             		*((volatile uint16*)0x4C)		/*Timer/Counter1 REGISTER*/

		#define 	OCR1AH                	*((volatile uint8*)0x4B)		/*OUTPUT COMPARE REGISTER 1 A*/
		#define 	OCR1AL                	*((volatile uint8*)0x4A)		/*OUTPUT COMPARE REGISTER 1 A*/
		#define 	OCR1A                	*((volatile uint16*)0x4A)		/*OUTPUT COMPARE REGISTER 1 A*/

		#define 	OCR1BH                	*((volatile uint8*)0x49)		/*OUTPUT COMPARE REGISTER 1 B*/
		#define 	OCR1BL               	*((volatile uint8*)0x48)		/*OUTPUT COMPARE REGISTER 1 B*/
		#define 	OCR1B               	*((volatile uint16*)0x48)		/*OUTPUT COMPARE REGISTER 1 B*/

		#define 	ICR1H                	*((volatile uint8*)0x47)		/*Input Capture Register 1*/
		#define 	ICR1L               	*((volatile uint8*)0x46)		/*Input Capture Register 1*/
		#define 	ICR1	               	*((volatile uint16*)0x46)		/*Input Capture Register 1*/

											/* TIMER 2 REGISTERS */

		#define 	TCCR2                	*((volatile uint8*)0x45)	  	/*TIMER/COUNTER CONTROL REGISTER*/
		#define 	TCCR2_FOC2			 	7u                           	/*FORCE OUTPUT COMPARE*/
		#define 	TCCR2_WGM20			 	6u                           	/*WAVEFORM GENERATION MODE*/
		#define 	TCCR2_COM21			 	5u                           	/*COMPARE MATCH OUTPUT MODE*/
		#define 	TCCR2_COM20			 	4u                           	/*COMPARE MATCH OUTPUT MODE*/
		#define 	TCCR2_WGM21			 	3u                           	/*WAVEFORM GENERATION MODE*/
		#define 	TCCR2_CS22			 	2u                           	/*CLOCK SELECT*/
		#define 	TCCR2_CS21				1u                           	/*CLOCK SELECT*/
		#define 	TCCR2_CS20			 	0u                           	/*CLOCK SELECT*/

		#define 	TCNT2               	*((volatile uint8*)0x44)		/*TIMER/COUNTER REGISTER*/

		#define 	OCR2                	*((volatile uint8*)0x43)		/*OUTPUT COMPARE REGISTER*/

											/* COMMON REGISTERS */

		#define 	TIMSK               	*((volatile uint8*)0x59)		/*TIMER/COUNTER INTERRUPT MASK REGISTER*/
		#define 	TIMSK_OCIE2				7u                           	/*TIMER/COUNTER 2 OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
		#define 	TIMSK_TOIE2				6u                           	/*TIMER/COUNTER 2 OVERFLOW INTERRUPT ENABLE*/
		#define 	TIMSK_TICIE1			5u                           	/*Timer/Counter 1 Input Capture Interrupt Enable*/
		#define 	TIMSK_OCIE1A			4u                           	/*Timer/Counter 1 Output Compare A Match Interrupt Enable*/
		#define 	TIMSK_OCIE1B			3u                           	/*Timer/Counter 1 Output Compare B Match Interrupt Enable*/
		#define 	TIMSK_TOIE1			 	2u                           	/*Timer/Counter 1 Overflow Interrupt Enable*/
		#define 	TIMSK_OCIE0				1u                           	/*TIMER/COUNTER 0 OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
		#define 	TIMSK_TOIE0				0u                           	/*TIMER/COUNTER 0 OVERFLOW INTERRUPT ENABLE*/

		#define 	TIFR                	*((volatile uint8*)0x58)		/*TIMER/COUNTER INTERRUPT FLAG REGISTER*/
		#define 	TIFR_OCF2			 	7u                           	/*TIMER/COUNTER 2 OUTPUT COMPARE FLAG 2*/
		#define 	TIFR_TOV2			 	6u                           	/*TIMER/COUNTER 2 OVERFLOW FLAG*/
		#define 	TIFR_ICF1			 	5u                           	/*Timer/Counter 1 Input Capture Flag*/
		#define 	TIFR_OCF1A			 	4u                           	/*Timer/Counter 1 Output Compare A Match Flag*/
		#define 	TIFR_OCF1B			 	3u                           	/*Timer/Counter 1 Output Compare B Match Flag*/
		#define 	TIFR_TOV1			 	2u                           	/*Timer/Counter 1 Overflow Flag*/
		#define 	TIFR_OCF0				1u                           	/*Timer/Counter 0 OUTPUT COMPARE FLAG 0*/
		#define 	TIFR_TOV0			 	0u                           	/*TIMER/COUNTER 0 OVERFLOW FLAG*/

		#define 	SFIOR               	*((volatile uint8*)0x50)		/*SPECIAL FUNCTION I/O REGISTER*/


#endif
