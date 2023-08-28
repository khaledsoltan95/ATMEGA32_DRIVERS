#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "TWI_Cfg.h"
#include "TWI_Interface.h"
#include "TWI_Prv.h"
#include "TWI_Reg.h"

static void (*TWI_pvNotificationFunc)(void) = NULL ;

												/* IF MASTER IS NOT ADDRESSED IN THE NETWORK , PASS ADDRESS 0 */

	uint8 				TWI_voidMasterInit 					( uint8 copy_u8MasterAddress )
	{
		uint8 Local_u8ErrorState = 0U ;
											/* ASSIGN MASTER ADDRESS */

		if ( (copy_u8MasterAddress == 0u ) || ( ( copy_u8MasterAddress >> 4 ) == 0b00001111 ) )
		{
			Local_u8ErrorState = RESERVED_ADDRESS_WARNING ; 				// "THIS ADDRESS IS RESERVED "
		}
		else
		{
			TWAR = ( copy_u8MasterAddress << 1 ) ; 							// ASSIGN ADDRESS IN TWAR
		}

											/* CLOCK CONFIGURATION  CPU = 16 MHZ , PRESCALER = 0 , COMMUNICATION FREQUENCY 400 KBPS */

		CLR_BIT(TWSR,TWSR_TWPS0); 											// SET PRESCALER
		CLR_BIT(TWSR,TWSR_TWPS1); 											// SET PRESCALER

		TWBR = 12U ; 														// SCL FREQUENCY 4OO KBPS ASSUMING TWPS = 0

											/* AKNOWLAGE BIT CONFIGURATION */

		SET_BIT(TWCR,TWCR_TWEA) ; 											// ENABLE AKNOWLAGE BIT

											/* TWI ENABLING */

		SET_BIT(TWCR,TWCR_TWEN) ;

		return Local_u8ErrorState ;
	}

	uint8				TWI_voidSlaveInit						( uint8 copy_u8SlaveAddress )
	{
		uint8 Local_u8ErrorState = 0U ;

											/* ASSIGN SLAVE ADDRESS */

		if ( (copy_u8SlaveAddress == 0u ) || ( ( copy_u8SlaveAddress >> 4 ) == 0b00001111 ) )
		{

			Local_u8ErrorState = RESERVED_ADDRESS_ERR ; 					// THIS ADDRESS IS RESERVED

		}
		else
		{

			TWAR = ( copy_u8SlaveAddress << 1 )  ; 							// ASSIGN ADDRESS IN TWAR

											/* AKNOWLAGE BIT CONFIGURATION */

			SET_BIT(TWCR,TWCR_TWEA) ; 								// ENABLE AKNOWLAGE BIT

											/*Enable TWI*/

			SET_BIT(TWCR,TWCR_TWEN);

		}


		return Local_u8ErrorState ;
	}

	TWI_Errorstatus_t 	TWI_voidSendStartCondition				( void )
	{
		TWI_Errorstatus_t Local_Error = NoError ;

											/* SEND START CONDITION */
		SET_BIT(TWCR,TWCR_TWSTA) ;

											/* CLEAR TWINT FLAG */

		SET_BIT(TWCR,TWCR_TWINT) ; 							//	THIS FLAG IS CLEARING WITH SETTING IT NOT CLEARING IT AS USUAL

											/* WAIT UNTIL TWINT FLAG RAISED AND THE BUS IS AVAILABLE */

		while ( ( GET_BIT(TWCR,TWCR_TWINT ) ) != 1 ) ;

											/* CHECK THE STATUS OF THE BUS */

		if ( ( TWSR & STATUS_BITS_MASK ) != START_ACK)
		{
			Local_Error = StartCondErr ;
		}
		else
		{
			// DO NOTHING
		}

		return Local_Error ;

	}

	TWI_Errorstatus_t 	TWI_voidSendRepeatedStart				( void )
	{
		TWI_Errorstatus_t Local_Error = NoError ;

											/* SEND START CONDITION */
		SET_BIT(TWCR,TWCR_TWSTA) ;

											/* CLEAR TWINT FLAG */

		SET_BIT(TWCR,TWCR_TWINT) ; 							//	THIS FLAG IS CLEARING WITH SETTING IT NOT CLEARING IT AS USUAL

											/* WAIT UNTIL TWINT FLAG RAISED AND THE BUS IS AVAILABLE */

		while ( ( GET_BIT(TWCR,TWCR_TWINT ) ) != 1 ) ;

											/* CHECK THE STATUS OF THE BUS */

		if ( ( TWSR & STATUS_BITS_MASK ) != REP_START_ACK )
		{
			Local_Error = RepStartErr ;
		}
		else
		{
			// DO NOTHING
		}

		return Local_Error ;
	}

	TWI_Errorstatus_t 	TWI_voidSendSlaveAddressWithWrite		( uint8 copy_u8SlaveAddress )
	{
		TWI_Errorstatus_t Local_Error = NoError ;

												/* SET SLAVE ADDRESS IN TWDR */
		TWDR = ( copy_u8SlaveAddress << 1 ) ;

												/* SET OPERATION AS WRITE OPERATION */

		CLR_BIT(TWDR,TWDR_TWD0) ;

												/* CLEAR THE START CONDITION BIT */

		CLR_BIT(TWCR,TWCR_TWSTA) ;

												/* CLEAR TWINT FLAG */

		SET_BIT(TWCR,TWCR_TWINT) ; 							//	THIS FLAG IS CLEARING WITH SETTING IT NOT CLEARING IT AS USUAL

												/* WAIT UNTIL TWINT FLAG RAISED */

		while ( ( GET_BIT(TWCR,TWCR_TWINT ) ) != 1 ) ;

												/* CHECK THE STATUS OF THE BUS */

		if ( ( TWSR & STATUS_BITS_MASK ) != SLAVE_ADD_AND_WR_ACK )
		{
		Local_Error = SlaveAddressWithWriteErr ;
		}
		else
		{
		// DO NOTHING
		}

		return Local_Error ;

	}

	TWI_Errorstatus_t 	TWI_voidSendSlaveAddressWithRead		( uint8 copy_u8SlaveAddress )
	{
		TWI_Errorstatus_t Local_Error = NoError ;

												/* SET SLAVE ADDRESS IN TWDR */
		TWDR = ( copy_u8SlaveAddress << 1 ) ;

												/* SET OPERATION AS READ OPERATION */

		SET_BIT(TWDR,TWDR_TWD0) ;

												/* CLEAR THE START CONDITION BIT */

		CLR_BIT(TWCR,TWCR_TWSTA) ;

												/* CLEAR TWINT FLAG */

		SET_BIT(TWCR,TWCR_TWINT) ; 							//	THIS FLAG IS CLEARING WITH SETTING IT NOT CLEARING IT AS USUAL

												/* WAIT UNTIL TWINT FLAG RAISED */

		while ( ( GET_BIT(TWCR,TWCR_TWINT ) ) != 1 ) ;

												/* CHECK THE STATUS OF THE BUS */

		if ( ( TWSR & STATUS_BITS_MASK ) != SLAVE_ADD_AND_RD_ACK )
		{
		Local_Error = SlaveAddressWithReadErr ;
		}
		else
		{
		// DO NOTHING
		}

		return Local_Error ;

	}

	TWI_Errorstatus_t 	TWI_voidMasterWriteDataByte				( uint8 copy_u8DataByte )
	{
		TWI_Errorstatus_t Local_Error = NoError ;

													/* SET DATA IN TWDR */

			TWDR = copy_u8DataByte ; 								// SET DATA IN TWDR

													/* CLEAR TWINT FLAG */

			SET_BIT(TWCR,TWCR_TWINT) ; 							//	THIS FLAG IS CLEARING WITH SETTING IT NOT CLEARING IT AS USUAL

													/* WAIT UNTIL TWINT FLAG RAISED */

			while ( ( GET_BIT(TWCR,TWCR_TWINT ) ) != 1 ) ;

													/* CHECK THE STATUS OF THE BUS */

			if ( ( TWSR & STATUS_BITS_MASK ) != MSTR_WR_BYTE_ACK )
			{
				Local_Error = MasterWriteByteWithAckErr ;
			}
			else
			{
				// DO NOTHING
			}

		return Local_Error ;
	}

	TWI_Errorstatus_t 	TWI_voidMasterReadDataByte				( uint8* copy_u8DataByte )
	{
		TWI_Errorstatus_t Local_Error = NoError ;

		if ( copy_u8DataByte != NULL )
		{
												/* CLEAR THE INTERRUPT FLAG TO ENABLE SLAVE SEND THE DATA */

			SET_BIT(TWCR,TWCR_TWINT) ;

												/* WAIT UNTIL TWINT FLAG RAISED DUE TO SLAVE WRITTING OPERATION FINISHES */

			while ( ( GET_BIT(TWCR,TWCR_TWINT ) ) != 1 ) ;

												/* CHECK THE STATUS OF THE BUS */

			if ( ( TWSR & STATUS_BITS_MASK ) != MSTR_RD_BYTE_WITH_ACK )
			{
				Local_Error = MasterReadByteWithAckErr ;
			}
			else
			{
				*copy_u8DataByte = TWDR ;
			}
		}
		else
		{
			Local_Error = NULL_PTR ;
		}
		return Local_Error ;
	}

	void 				TWI_voidSendStopCondition				( void )
	{
												/* SEND STOP CONDITION */

		SET_BIT(TWCR,TWCR_TWSTO) ;

												/* CLEAR TWINT FLAG */

		SET_BIT(TWCR,TWCR_TWINT) ; 							//	THIS FLAG IS CLEARING WITH SETTING IT NOT CLEARING IT AS USUAL

	}


	uint8				 TWI_u8SetCallBack 						(  void(*copy_pvNotification)(void) )

		{
			uint8 Local_u8ErrorState = OK ;
			if (  copy_pvNotification != NULL  )
			{
												/* CONVERT THE NOTIFICATION FUNCTION LOCAL VARIABLES TO GLOBAL */

				TWI_pvNotificationFunc = copy_pvNotification ;
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}

			return Local_u8ErrorState ;
		}
												/* Two-wire Serial Interface ISR */

	void 				__vector_19 							( void )			__attribute__((signal)) ;
	void 				__vector_19 							( void )
	{

	if ( TWI_pvNotificationFunc != NULL )
	{
	TWI_pvNotificationFunc() ;
	}
	else
	{
	// DO NOTHING
	}

	}
