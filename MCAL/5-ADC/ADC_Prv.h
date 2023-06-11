#ifndef ADC_PRV_H
#define ADC_PRV_H

									/*ADC PRIVATE FUNCTIONS & DEFINITIONS */
	#define 	ChannelMaxValue 		31u

	#define		DIVISION_BY_2			0U
	#define		DIVISION_BY_4			2U
	#define		DIVISION_BY_8			3U
	#define		DIVISION_BY_16			4U
	#define		DIVISION_BY_32			5U
	#define		DIVISION_BY_64			6U
	#define		DIVISION_BY_128			7U

	#define 	PRESCALER_MASK			0b11111000
	#define 	CHANNEL_SELECTION_MASK	0b11100000

	#define		EIGHT_BITS 				1u
	#define		TEN_BITS 				2u

	#define 	IDLE 					0U
	#define 	BUSY					1U

									/*ASYNCHRONOUS TYPES */

	#define		SINGLE					0U
	#define		CHAIN					1U



#endif
