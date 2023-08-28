#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

											/* SPI REGISTERS */

		#define 	SPCR	                *((volatile uint8*)0x2D)	  	/*SPI Control Register*/
		#define 	SPCR_SPIE			 	7u                           	/*SPI Interrupt Enable*/
		#define 	SPCR_SPE			 	6u                           	/*SPI Enable*/
		#define 	SPCR_DORD			 	5u                           	/*Data Order*/
		#define 	SPCR_MSTR		 		4u                           	/*Master/Slave Select*/
		#define 	SPCR_CPOL			 	3u                           	/*Clock Polarity*/
		#define 	SPCR_CPHA		 		2u                           	/*Clock Phase*/
		#define 	SPCR_SPR1				1u                           	/*SPI Clock Rate*/
		#define 	SPCR_SPR0			 	0u                           	/*SPI Clock Rate*/

		#define 	SPSR	                *((volatile uint8*)0x2E)	  	/*SPI Status Register*/
		#define 	SPSR_SPIF			 	7u                           	/*SPI Interrupt Flag*/
		#define 	SPSR_WCOL			 	6u                           	/*Write COLlision Flag*/
		#define 	SPSR_R1 			 	5u                           	/*Reserved Bits*/
		#define 	SPSR_R2	     		 	4u                           	/*Reserved Bits*/
		#define 	SPSR_R3 			 	3u                           	/*Reserved Bits*/
		#define 	SPSR_R4  			 	2u                           	/*Reserved Bits*/
		#define 	SPSR_R5		    		1u                           	/*Reserved Bits*/
		#define 	SPSR_SPI2X			 	0u                           	/*Double SPI Speed Bit*/

		#define 	SPDR	                *((volatile uint8*)0x2F)	  	/*SPI Data Register*/
		#define 	SPDR_MSB			 	7u                           	/*MSB*/
		#define 	SPDR_B6 			 	6u                           	/*Bit 6*/
		#define 	SPDR_B5 			 	5u                           	/*Bit 5*/
		#define 	SPDR_B4 			 	4u                           	/*Bit 4*/
		#define 	SPDR_B3 			 	3u                           	/*Bit 3*/
		#define 	SPDR_B2 			 	2u                           	/*Bit 2*/
		#define 	SPDR_B1 				1u                           	/*Bit 1*/
		#define 	SPDR_LSB			 	0u                           	/*LSB*/

#endif
