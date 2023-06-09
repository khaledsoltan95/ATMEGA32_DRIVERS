#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

		#define 	TCCR0                *((volatile uint8*)0x53)	  	/*TIMER/COUNTER CONTROL REGISTER*/
		#define 	TCCR0_FOC0			 7u                           	/*FORCE OUTPUT COMPARE*/
		#define 	TCCR0_WGM00			 6u                           	/*WAVEFORM GENERATION MODE*/
		#define 	TCCR0_COM01			 5u                           	/*COMPARE MATCH OUTPUT MODE*/
		#define 	TCCR0_COM00			 4u                           	/*COMPARE MATCH OUTPUT MODE*/
		#define 	TCCR0_WGM01			 3u                           	/*WAVEFORM GENERATION MODE*/
		#define 	TCCR0_CS02			 2u                           	/*CLOCK SELECT*/
		#define 	TCCR0_CS01			 1u                           	/*CLOCK SELECT*/
		#define 	TCCR0_CS00			 0u                           	/*CLOCK SELECT*/

		#define 	TCNT0               *((volatile uint8*)0x52)		/*TIMER/COUNTER REGISTER*/

		#define 	OCR0                *((volatile uint8*)0x5C)		/*OUTPUT COMPARE REGISTER*/

		#define 	TIMSK               *((volatile uint8*)0x59)		/*TIMER/COUNTER INTERRUPT MASK REGISTER*/
		#define 	TIMSK_OCIE0			 1u                           	/*TIMER/COUNTER 0 OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
		#define 	TIMSK_TOIE0			 0u                           	/*TIMER/COUNTER 0 OVERFLOW INTERRUPT ENABLE*/

		#define 	TIFR                *((volatile uint8*)0x58)		/*TIMER/COUNTER INTERRUPT FLAG REGISTER*/
		#define 	TIFR_OCF0			 1u                           	/*OUTPUT COMPARE FLAG0*/
		#define 	TIFR_TOV0			 0u                           	/*TIMER/COUNTER0 OVERFLOW FLAG*/



#endif
