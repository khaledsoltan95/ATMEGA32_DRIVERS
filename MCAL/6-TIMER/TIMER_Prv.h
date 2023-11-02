#ifndef TIMER_PRV_H
#define TIMER_PRV_H

									/*TIMER 0 PRIVATE FUNCTIONS & DEFINITIONS */
	#define		PRESCALER_MASK 																0b11111000
	#define		CTC_MODE_MASK 																0b11001111

	#define 	NORMAL_MODE 																0u
	#define 	PWM_PHASE_CORRECT_MODE 														1u
	#define 	CTC_MODE 																	2u
	#define 	FAST_PWM_MODE 																3u

	#define		NO_CLOCK_SOURCE																0u
	#define		NO_PRESCALING																1U
	#define		DIVISION_BY_8																2U
	#define		DIVISION_BY_64																3U
	#define		DIVISION_BY_256																4U
	#define		DIVISION_BY_1024															5U
	#define		CLOCK_ON_FALLING_EDGE														6U
	#define		CLOCK_ON_RISING_EDGE														7U

	#define 	OUTSOURCE																	0U
	#define 	INITIALLY_SET																1U

								/* Compare Output Mode, NON-PWM Mode */
	#define 	OC0_DISCONNECTED															0U
	#define 	OC0_TOGGLE																	0b00010000
	#define 	OC0_CLEAR																	0b00100000
	#define 	OC0_SET																		0b00110000

								/* Compare Output Mode, Fast PWM Mode */
	#define 	OC0_DISCONNECTED															0U
	#define 	RESERVED																	0b00010000
	#define 	OC0_CLEAR_ON_COMPARE_SET_AT_TOP												0b00100000
	#define 	OC0_SET_ON_COMPARE_CLEAR_AT_TOP												0b00110000

								/* Compare Output Mode, Phase Correct PWM Mode */
	#define 	OC0_DISCONNECTED															0U
	#define 	RESERVED																	1U
	#define 	OC0_CLEAR_ON_COMPARE_UP_COUNTING_SET_ON_COMPARE_DOWN_COUNTING				2U
	#define 	OC0_SET_ON_COMPARE_UP_COUNTING_CLEAR_ON_COMPARE_DOWN_COUNTING				3U

								/*TIMER 1 PRIVATE FUNCTIONS & DEFINITIONS */
	#define		PRESCALER_MASK 																0b11111000
	#define		CHANNEL_MASK 																0b00001111

								/* Compare Output Mode, Fast PWM Mode CHANNEL A  */
	#define 	OC1_DISCONNECTED_A															0U
	#define 	RESERVED_A																	0b01000000
	#define 	OC1_CLEAR_ON_COMPARE_SET_AT_TOP_A											0b10000000
	#define 	OC1_SET_ON_COMPARE_CLEAR_AT_TOP_A											0b11000000
	 							/* Compare Output Mode, Fast PWM Mode CHANNEL B  */
	#define 	OC1_DISCONNECTED_B															0U
	#define 	RESERVED_B																	0b00010000
	#define 	OC1_CLEAR_ON_COMPARE_SET_AT_TOP_B											0b00100000
	#define 	OC1_SET_ON_COMPARE_CLEAR_AT_TOP_B											0b00110000

	#define 	NORMAL_MODE																	0U
	#define 	PWM_Phase_Correct_8_bit														1U
	#define 	PWM_Phase_Correct_9_bit														2U
	#define 	PWM_Phase_Correct_10_bit													3U
	#define 	CTC_MODE1																	4U
	#define 	Fast_PWM_8_bit																5U
	#define 	Fast_PWM_9_bit																6U
	#define 	Fast_PWM_10_bit																7U
	#define 	PWM_Phase_and_Frequency_Correct1											8U
	#define 	PWM_Phase_and_Frequency_Correct2											9U
	#define 	PWM_Phase_Correct1															10U
	#define 	PWM_Phase_Correct2															11U
	#define 	CTC_MODE2																	12U
	#define 	RESERVED																	13U
	#define 	Fast_PWM1																	14U
	#define 	Fast_PWM2																	15U

									/*TIMER 2 PRIVATE FUNCTIONS & DEFINITIONS */
								/* Compare Output Mode, NON-PWM Mode */
	#define 	OC2_DISCONNECTED															0U
	#define 	OC2_TOGGLE																	0b00010000
	#define 	OC2_CLEAR																	0b00100000
	#define 	OC2_SET																		0b00110000
								/* Compare Output Mode, Fast PWM Mode */
	#define 	OC2_DISCONNECTED															0U
	#define 	RESERVED																	0b00010000
	#define 	OC2_CLEAR_ON_COMPARE_SET_AT_TOP												0b00100000
	#define 	OC2_SET_ON_COMPARE_CLEAR_AT_TOP												0b00110000
								/* Compare Output Mode, Phase Correct PWM Mode */
	#define 	OC2_DISCONNECTED															0U
	#define 	RESERVED																	1U
	#define 	OC2_CLEAR_ON_COMPARE_UP_COUNTING_SET_ON_COMPARE_DOWN_COUNTING				2U
	#define 	OC2_SET_ON_COMPARE_UP_COUNTING_CLEAR_ON_COMPARE_DOWN_COUNTING				3U

#endif
