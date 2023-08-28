#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_
											/* TWI REGISTERS */

		#define 	TWBR	                *((volatile uint8*)0x20)	  	/*TWI Bit Rate Register*/
		#define 	TWBR_TWBR7			 	7u                           	/*TWI Bit Rate */
		#define 	TWBR_TWBR6			 	6u                           	/*TWI Bit Rate */
		#define 	TWBR_TWBR5			 	5u                           	/*TWI Bit Rate */
		#define 	TWBR_TWBR4		 		4u                           	/*TWI Bit Rate */
		#define 	TWBR_TWBR3			 	3u                           	/*TWI Bit Rate */
		#define 	TWBR_TWBR2		 		2u                           	/*TWI Bit Rate */
		#define 	TWBR_TWBR1				1u                           	/*TWI Bit Rate */
		#define 	TWBR_TWBR0			 	0u                           	/*TWI Bit Rate */

		#define 	TWSR	                *((volatile uint8*)0x21)	  	/*TWI Status Register*/
		#define 	TWSR_TWS7			 	7u                           	/*TWI Status*/
		#define 	TWSR_TWS6			 	6u                           	/*TWI Status*/
		#define 	TWSR_TWS5			 	5u                           	/*TWI Status*/
		#define 	TWSR_TWS4			 	4u                           	/*TWI Status*/
		#define 	TWSR_TWS3			 	3u                           	/*TWI Status*/
		#define 	TWSR_R				 	2u                           	/*Reserved Bits*/
		#define 	TWSR_TWPS1				1u                           	/*TWI Prescaler Bits*/
		#define 	TWSR_TWPS0			 	0u                           	/*TWI Prescaler Bits*/

		#define 	TWAR	                *((volatile uint8*)0x22)	  	/*TWI (Slave) Address Register*/
		#define 	TWAR_TWA6			 	7u                           	/*TWI (Slave) Address*/
		#define 	TWAR_TWA5			 	6u                           	/*TWI (Slave) Address*/
		#define 	TWAR_TWA4			 	5u                           	/*TWI (Slave) Address*/
		#define 	TWAR_TWA3			 	4u                           	/*TWI (Slave) Address*/
		#define 	TWAR_TWA2			 	3u                           	/*TWI (Slave) Address*/
		#define 	TWAR_TWA1			 	2u                           	/*TWI (Slave) Address*/
		#define 	TWAR_TWA0				1u                           	/*TWI (Slave) Address*/
		#define 	TWAR_TWGCE			 	0u                           	/*TWI General Call Recognition Enable Bit*/

		#define 	TWDR	                *((volatile uint8*)0x23)	  	/*TWI Data Register*/
		#define 	TWDR_TWD7			 	7u                           	/*TWI Data*/
		#define 	TWDR_TWD6			 	6u                           	/*TWI Data*/
		#define 	TWDR_TWD5			 	5u                           	/*TWI Data*/
		#define 	TWDR_TWD4			 	4u                           	/*TWI Data*/
		#define 	TWDR_TWD3			 	3u                           	/*TWI Data*/
		#define 	TWDR_TWD2			 	2u                           	/*TWI Data*/
		#define 	TWDR_TWD1				1u                           	/*TWI Data*/
		#define 	TWDR_TWD0			 	0u                           	/*TWI Data*/

		#define 	TWCR	                *((volatile uint8*)0x56)	  	/*TWI Control Register*/
		#define 	TWCR_TWINT			 	7u                           	/*TWI Interrupt Flag*/
		#define 	TWCR_TWEA			 	6u                           	/*TWI Enable Acknowledge Bit*/
		#define 	TWCR_TWSTA 			 	5u                           	/*TWI START Condition Bit*/
		#define 	TWCR_TWSTO	     		4u                           	/*TWI STOP Condition Bit*/
		#define 	TWCR_TWWC 			 	3u                           	/*TWI Write Collision Flag*/
		#define 	TWCR_TWEN  			 	2u                           	/*TWI Enable Bit*/
		#define 	TWCR_R		    		1u                           	/*Reserved Bits*/
		#define 	TWCR_TWIE			 	0u                           	/*TWI Interrupt Enable*/

#endif
