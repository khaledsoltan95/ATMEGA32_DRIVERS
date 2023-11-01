#ifndef I2C_CFG_H
#define I2C_CFG_H
											/* I2C(TWI) CONFIGURATIONS */

					/* TWI ROLE CONFIGURATION OPTIONS   	1- MASTER
					 * 										2- SLAVE
					 */
	#define 	TWI_u8ROLE 							MASTER

	#if 					TWI_u8ROLE == MASTER

					/* TWI ROLE CONFIGURATION OPTIONS   	1- DIVIDED_BY_1
					 * 										2- DIVIDED_BY_4
					 * 										3- DIVIDED_BY_16
					 * 										4- DIVIDED_BY_64
					 */
		#define 	TWI_u8ClockRate 					DIVIDED_BY_1

					/* TWI CLOCK FREQUENCY CONFIGURATION SET "SET NUMBER WITHOUT MILLION ex. 16 for 16MHZ CLOCK*/
		#define 	TWI_u8ClockFrequency 				16u

					/* TWI SCL FREQUENCY CONFIGURATION SET ex. 400 for 400 kbps "MAXIMUM VALUE CAN TWI SUPPORT" "CLOCK FREQUENCY MUST BE > (16 * SCL FREQUENCY) */
		#define 	TWI_u16SCLFrequency					400u

	#elif 					TWI_u8ROLE == SLAVE

	#else
			#error Wrong TWI_u8ROLE Configuration Value

	#endif

					/* TWI INTERRUPT ENABLE CONFIGURATION OPTIONS   	1- ENABLE
					 * 													2- DISABLE
					 */
	#define 	TWI_u8InterruptEnable 				ENABLE

					/* TWI ACKNOWLEDGE BIT OPTIONS				   		1- ENABLE
					 * 													2- DISABLE
					 */
	#define 	TWI_u8AcknowledgeBit				ENABLE

					/* TWI ENABLE CONFIGURATION OPTIONS   				1- ENABLE
					 * 													2- DISABLE
					 */
	#define 	TWI_u8Enable 						ENABLE

					/* TWI GENERAL CALL RECOGNITION OPTIONS   			1- ENABLE
					 * 													2- DISABLE
					 */
	#define 	TWI_u8GeneralCallRecognition 		ENABLE

#endif 
