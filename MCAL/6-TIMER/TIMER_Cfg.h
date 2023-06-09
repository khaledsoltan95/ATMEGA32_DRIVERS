#ifndef TIMER_CFG_H
#define TIMER_CFG_H
									/* CONFIGURE TIMER MODES SELECT  : 1- NORMAL_MODE
									 * 								   2- PWM_PHASE_CORRECT_MODE
									 *								   3- CTC_MODE
									 * 								   4- FAST_PWM_MODE
									 */
	#define 		TIMER_u8MODE				NORMAL_MODE

	#if 			TIMER_u8MODE == CTC_MODE
									/* CONFIGURE CTC OPTIONS :  1- OC0_DISCONNECTED
									 * 						    2- OC0_TOGGLE
									 *						    3- OC0_CLEAR
									 * 						    4- OC0_SET
									 */
			#define 		CTC_MODE_OPTION 			OC0_DISCONNECTED

	#elif 			TIMER_u8MODE == FAST_PWM_MODE
									/* CONFIGURE FAST PWM OPTIONS :  1- OC0_DISCONNECTED
									 * 						    	 2- RESERVED
									 *						    	 3- OC0_CLEAR_ON_COMPARE_SET_AT_TOP
									 * 						     	 4- OC0_SET_ON_COMPARE_CLEAR_AT_TOP
									 */
			#define 		FAST_PWM_MODE_OPTION 			OC0_DISCONNECTED

	#elif 			TIMER_u8MODE == PWM_PHASE_CORRECT_MODE
									/* CONFIGURE PWM PHASE CORRECT MODE_OPTION :  1- OC0_DISCONNECTED
									 * 						    	 			  2- RESERVED
									 *						    	 			  3- OC0_CLEAR_ON_COMPARE_UP_COUNTING_SET_ON_COMPARE_DOWN_COUNTING
									 * 						     	 			  4- OC0_SET_ON_COMPARE_UP_COUNTING_CLEAR_ON_COMPARE_DOWN_COUNTING
									 */
			#define 		PWM_PHASE_CORRECT_MODE_OPTION 			OC0_DISCONNECTED

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
	#define 		 TIMER_u8CLOCK				NO_PRESCALING

	#define			 TIMER_u16PreloadValue		0U


							
#endif 
