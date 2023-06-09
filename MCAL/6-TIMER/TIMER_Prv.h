#ifndef TIMER_PRV_H
#define TIMER_PRV_H

									/*ADC PRIVATE FUNCTIONS & DEFINITIONS */
	#define		CLOCK_SELECTION_MASK 														0b11111000

	#define 	NORMAL_MODE 																0u
	#define 	PWM_PHASE_CORRECT_MODE 														1u
	#define 	CTC_MODE 																	2u
	#define 	FAST_PWM_MODE 																3u

	#define		NO_CLOCK_SOURCE																0U
	#define		NO_PRESCALING																1U
	#define		DIVISION_BY_8																2U
	#define		DIVISION_BY_64																3U
	#define		DIVISION_BY_256																4U
	#define		DIVISION_BY_1024															5U
	#define		CLOCK_ON_FALLING_EDGE														6U
	#define		CLOCK_ON_RISING_EDGE														7U
								/* Compare Output Mode, non-PWM Mode */
	#define 	OC0_DISCONNECTED															0U
	#define 	OC0_TOGGLE																	1U
	#define 	OC0_CLEAR																	2U
	#define 	OC0_SET																		3U
								/* Compare Output Mode, Fast PWM Mode */
	#define 	OC0_DISCONNECTED															0U
	#define 	RESERVED																	1U
	#define 	OC0_CLEAR_ON_COMPARE_SET_AT_TOP												2U
	#define 	OC0_SET_ON_COMPARE_CLEAR_AT_TOP												3U
								/* Compare Output Mode, Phase Correct PWM Mode */
	#define 	OC0_DISCONNECTED															0U
	#define 	RESERVED																	1U
	#define 	OC0_CLEAR_ON_COMPARE_UP_COUNTING_SET_ON_COMPARE_DOWN_COUNTING				2U
	#define 	OC0_SET_ON_COMPARE_UP_COUNTING_CLEAR_ON_COMPARE_DOWN_COUNTING				3U

#endif
