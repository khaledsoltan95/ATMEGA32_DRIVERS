#ifndef SPI_CFG_H
#define SPI_CFG_H
											/* SPI CONFIGURATIONS */

					/* SPI ROLE CONFIGURATION OPTIONS   	1- MASTER
					 * 										2- SLAVE
					 */
	#define 	SPI_u8ROLE 							SLAVE

	#if 					SPI_u8ROLE == MASTER

					/* SPI ROLE CONFIGURATION OPTIONS   	1- DIVIDED_BY_4
					 * 										2- DIVIDED_BY_16
					 * 										3- DIVIDED_BY_64
					 * 										4- DIVIDED_BY_128
					 * 										5- DIVIDED_BY_2
					 * 										6- DIVIDED_BY_8
					 * 										7- DIVIDED_BY_32
					 */
		#define 				SPI_u8ClockRate 						DIVIDED_BY_2

	#elif 					SPI_u8ROLE == SLAVE

	#else
			#error Wrong SPI_u8ROLE Configuration Value

	#endif

					/* SPI INTERRUPT ENABLE CONFIGURATION OPTIONS   	1- ENABLE
					 * 													2- DISABLE
					 */
	#define 	SPI_u8InterruptEnable 				DISABLE

					/* SPI DATA ORDER CONFIGURATION OPTIONS   			1- LSB_FIRST
					 * 													2- MSB_FIRST
					 */
	#define 	SPI_u8DataOrder 					MSB_FIRST

					/* SPI CLOCK POLARITY CONFIGURATION OPTIONS   		1- IDLE_HIGH
					 * 													2- IDLE_LOW
					 */
	#define 	SPI_u8ClockPolarity					IDLE_LOW

					/* SPI CLOCK PHASE CONFIGURATION OPTIONS	   		1- SAMPLE_FIRST
					 * 													2- SETUP_FIRST
					 */
	#define 	SPI_u8ClockPhase					SAMPLE_FIRST

#endif 
