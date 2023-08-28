#ifndef TIMER_CFG_H
#define TIMER_CFG_H
									/* CONFIGURE TIMER 0 MODES SELECT  : 1- NORMAL_MODE
									 * 								   2- PWM_PHASE_CORRECT_MODE
									 *								   3- CTC_MODE
									 * 								   4- FAST_PWM_MODE
									 */

	#define 		TIMER0_u8MODE				FAST_PWM_MODE

	#if 			TIMER0_u8MODE == CTC_MODE

			#define			 TIMER0_u8CompareValue		250U

									/* CONFIGURE CTC OPTIONS :  1- OC0_DISCONNECTED
									 * 						    2- OC0_TOGGLE
									 *						    3- OC0_CLEAR
									 * 						    4- OC0_SET
									 */
			#define 		CTC_MODE_OPTION 			OC0_DISCONNECTED

	#elif 			TIMER0_u8MODE == FAST_PWM_MODE
									/* CONFIGURE FAST PWM OPTIONS :  1- OC0_DISCONNECTED
									 * 						    	 2- RESERVED
									 *						    	 3- OC0_CLEAR_ON_COMPARE_SET_AT_TOP
									 * 						     	 4- OC0_SET_ON_COMPARE_CLEAR_AT_TOP
									 */
			#define 		FAST_PWM_MODE_OPTION 					OC0_CLEAR_ON_COMPARE_SET_AT_TOP
									/* COMPARE_VALUE_GENERATION_METHOD OPTIONS :  1- OUTSOURCE
									 * 						    	 			  2- INITIALLY_SET
									 */
			#define			COMPARE_VALUE_GENERATION_METHOD			INITIALLY_SET

					#if 			COMPARE_VALUE_GENERATION_METHOD == INITIALLY_SET

					#define			 TIMER0_u8CompareValue		64U

					#endif

	#elif 			TIMER0_u8MODE == PWM_PHASE_CORRECT_MODE
									/* CONFIGURE PWM PHASE CORRECT MODE_OPTION :  1- OC0_DISCONNECTED
									 * 						    	 			  2- RESERVED
									 *						    	 			  3- OC0_CLEAR_ON_COMPARE_UP_COUNTING_SET_ON_COMPARE_DOWN_COUNTING
									 * 						     	 			  4- OC0_SET_ON_COMPARE_UP_COUNTING_CLEAR_ON_COMPARE_DOWN_COUNTING
									 */
			#define 		PWM_PHASE_CORRECT_MODE_OPTION 			OC0_DISCONNECTED

	#elif 			TIMER0_u8MODE == NORMAL_MODE

			#define			 TIMER0_u8PreloadValue		0U


	#endif

									/* CONFIGURE TIMER CLOCK SELECT	:	1- NO_CLOCK_SOURCE
									 * 									2- NO_PRESCALING
									 *								    3- DIVISION_BY_8
									 * 									4- DIVISION_BY_64
									 * 									5- DIVISION_BY_256
									 *									6- DIVISION_BY_1024
									 * 									7- CLOCK_ON_FALLING_EDGE
									 * 									8- CLOCK_ON_RISING_EDGE
									 */
	#define 		 TIMER0_u8CLOCK				DIVISION_BY_64


			/////////////////////////////////////////////* TIMER 1 CONFIGURATIONS */////////////////////////////////////////////////////////

								     /* CONFIGURE TIMER 1 MODES SELECT  : 1- NORMAL_MODE
									 * 								      2- PWM_Phase_Correct_8_bit
									 *								      3- PWM_Phase_Correct_9_bit
									 * 								      4- PWM_Phase_Correct_10_bit
									 * 								      5- CTC_MODE1
									 * 								      6- Fast_PWM_8_bit
									 * 								      7- Fast_PWM_9_bit
									 * 								      8- Fast_PWM_10_bit
									 * 								      9- PWM_Phase_and_Frequency_Correct1
									 * 								      10- PWM_Phase_and_Frequency_Correct2
									 * 								      11- PWM_Phase_Correct1
									 * 								      12- PWM_Phase_Correct2
									 * 								      13- CTC_MODE2
									 * 								      14- RESERVED
									 * 								      15- Fast_PWM1
									 * 								      16- Fast_PWM2
									 */

	#define 		TIMER1_u8MODE				Fast_PWM1					// SET THE MODE YOU WANT TO USE FOR TIMER 1

	#if 			TIMER1_u8MODE == CTC_MODE

			#define			 TIMER1_u8CompareValue		250U

									/* CONFIGURE CTC OPTIONS :  1- OC0_DISCONNECTED
									 * 						    2- OC0_TOGGLE
									 *						    3- OC0_CLEAR
									 * 						    4- OC0_SET
									 */
			#define 		CTC_MODE_OPTION 			OC0_DISCONNECTED

	#elif 			TIMER1_u8MODE == Fast_PWM1

									/* CONFIGURE CHANNEL A FAST PWM OPTIONS :  	1- OC1_DISCONNECTED_A
									 * 						    				2- RESERVED_A
									 *						    	 			3- OC1_CLEAR_ON_COMPARE_SET_AT_TOP_A
									 * 						     	 			4- OC1_SET_ON_COMPARE_CLEAR_AT_TOP_A
									 */
			#define 		FAST_PWM_MODE_OPTION_CHANNELA 					OC1_DISCONNECTED_A

									/* CONFIGURE CHANNEL B FAST PWM OPTIONS :  	1- OC1_DISCONNECTED_B
									 * 						    				2- RESERVED_B
									 *						    	 			3- OC1_CLEAR_ON_COMPARE_SET_AT_TOP_B
									 * 						     	 			4- OC1_SET_ON_COMPARE_CLEAR_AT_TOP_B
									 */

			#define 		FAST_PWM_MODE_OPTION_CHANNELB 					OC1_CLEAR_ON_COMPARE_SET_AT_TOP_B

									/* COMPARE_VALUE_GENERATION_METHOD OPTIONS :  1- OUTSOURCE
									 * 						    	 			  2- INITIALLY_SET
									 */
			#define			COMPARE_VALUE_GENERATION_METHOD_A			OUTSOURCE

									/* COMPARE_VALUE_GENERATION_METHOD OPTIONS :  1- OUTSOURCE
									 * 						    	 			  2- INITIALLY_SET
									 */
			#define					COMPARE_VALUE_GENERATION_METHOD_B			INITIALLY_SET

					#if 			COMPARE_VALUE_GENERATION_METHOD_A == INITIALLY_SET

					#define			TIMER1_u8CompareValue_A		250U

					#endif
					#if 			COMPARE_VALUE_GENERATION_METHOD_B == INITIALLY_SET

					#define			TIMER1_u8CompareValue_B				2500U

					#endif
			#define			 		TIMER1_u8TOPValue					40000U

	#elif 			TIMER1_u8MODE == PWM_PHASE_CORRECT_MODE
									/* CONFIGURE PWM PHASE CORRECT MODE_OPTION :  1- OC0_DISCONNECTED
									 * 						    	 			  2- RESERVED
									 *						    	 			  3- OC0_CLEAR_ON_COMPARE_UP_COUNTING_SET_ON_COMPARE_DOWN_COUNTING
									 * 						     	 			  4- OC0_SET_ON_COMPARE_UP_COUNTING_CLEAR_ON_COMPARE_DOWN_COUNTING
									 */
			#define 		PWM_PHASE_CORRECT_MODE_OPTION 			OC0_DISCONNECTED

	#elif 			TIMER1_u8MODE == NORMAL_MODE

			#define			 TIMER1_u8PreloadValue		0U


	#endif

									/* CONFIGURE TIMER CLOCK SELECT	:	1- NO_CLOCK_SOURCE
									 * 									2- NO_PRESCALING
									 *								    3- DIVISION_BY_8
									 * 									4- DIVISION_BY_64
									 * 									5- DIVISION_BY_256
									 *									6- DIVISION_BY_1024
									 * 									7- CLOCK_ON_FALLING_EDGE
									 * 									8- CLOCK_ON_RISING_EDGE
									 */
	#define 		 TIMER1_u8CLOCK				DIVISION_BY_8

#endif 
