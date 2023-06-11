#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
										/* Functions Deceleration */
		/**
		 * @brief options of channel conversion
		 */
	typedef enum
	{
		ADC0_SINGLE_ENDED = 0 ,     //!< ADC0_SINGLE_ENDED
		ADC1_SINGLE_ENDED ,         //!< ADC1_SINGLE_ENDED
		ADC2_SINGLE_ENDED ,         //!< ADC2_SINGLE_ENDED
		ADC3_SINGLE_ENDED ,         //!< ADC3_SINGLE_ENDED
		ADC4_SINGLE_ENDED ,         //!< ADC4_SINGLE_ENDED
		ADC5_SINGLE_ENDED ,         //!< ADC5_SINGLE_ENDED
		ADC6_SINGLE_ENDED ,         //!< ADC6_SINGLE_ENDED
		ADC7_SINGLE_ENDED ,         //!< ADC7_SINGLE_ENDED
		ADC0_POS_ADC0_NEG_10X_GAIN ,//!< ADC0_POS_ADC0_NEG_10X_GAIN
		ADC1_POS_ADC0_NEG_10X_GAIN  //!< ADC1_POS_ADC0_NEG_10X_GAIN
		//ADC0_POS_ADC0_NEG_10X_GAIN ,
		//ADC0_POS_ADC0_NEG_10X_GAIN    // TO BE CONTINUED.....
		
	}ADC_Channel_t ;
	
	typedef struct {
		uint8   		ConversionsNum;
		ADC_Channel_t   *ChannelArr;
	    uint16  		*ResultArr;
	    void    (*NotificationFunc)(void);

	} ADC_Chain_t;

	void   ADC_voidInit  		      ( void ) ;

	uint16 ADC_u8StartSingleConversionSynch     	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult ) ;

	uint16 ADC_u8StartSingleConversionAsynch	 	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult , void(*copy_pvNotification)(void) ) ;

	uint8  ADC_u8StartChainConversionAsynch 	 	 (const ADC_Chain_t *copy_ChainData);

#endif
