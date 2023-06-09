#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
	
											/* Functions Deceleration */
	typedef enum
	{
		ADC0_SINGLE_ENDED = 0 ,
		ADC1_SINGLE_ENDED ,
		ADC2_SINGLE_ENDED ,
		ADC3_SINGLE_ENDED ,
		ADC4_SINGLE_ENDED ,
		ADC5_SINGLE_ENDED ,
		ADC6_SINGLE_ENDED ,
		ADC7_SINGLE_ENDED ,
		ADC0_POS_ADC0_NEG_10X_GAIN ,
		ADC1_POS_ADC0_NEG_10X_GAIN
		//ADC0_POS_ADC0_NEG_10X_GAIN ,
		//ADC0_POS_ADC0_NEG_10X_GAIN    // TO BE CONTINUED.....
		
	}ADC_Channel_t ;
	
	typedef struct {
		uint8   Conversion_Number;
	    uint8   *Conversion_Channel_arr;
	    uint16  *result_arr;
	    void    (*NotificationFunction)(void);

	} ChainConversionStruct_t;

	void   ADC_voidInit  		      ( void ) ;

	uint16 ADC_u8StartConversionSynch     	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult ) ;

	uint16 ADC_u8StartConversionAsynch	 	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult , void(*copy_pvNotification)(void) ) ;

	uint8  ADC_StartChainConversionAsynch 	 (ChainConversionStruct_t *copy_structpConversionChainSent);

#endif
