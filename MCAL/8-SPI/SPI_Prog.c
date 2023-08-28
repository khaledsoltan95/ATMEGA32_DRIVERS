#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "SPI_Reg.h"
#include "SPI_Cfg.h"
#include "SPI_Prv.h"
#include "SPI_Interface.h"

static void (*SPI_pvNotificationFunc)(void) = NULL ;

	void SPI_voidInitial 		( void )
	{
		#if 				SPI_u8ROLE == MASTER

		SET_BIT(SPCR,SPCR_MSTR) ;   	// MASTER SELECTION

												/* CLOCK RATE SELECTION */

				#if 				SPI_u8ClockRate == DIVIDED_BY_4

				CLR_BIT(SPCR,SPCR_SPR0);
				CLR_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPSR,SPSR_SPI2X);

				#elif 				SPI_u8ClockRate == DIVIDED_BY_16

				SET_BIT(SPCR,SPCR_SPR0);
				CLR_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPSR,SPSR_SPI2X);

				#elif 				SPI_u8ClockRate == DIVIDED_BY_64

				CLR_BIT(SPCR,SPCR_SPR0);
				SET_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPSR,SPSR_SPI2X);

				#elif 				SPI_u8ClockRate == DIVIDED_BY_128

				SET_BIT(SPCR,SPCR_SPR0);
				SET_BIT(SPCR,SPCR_SPR1);
				CLR_BIT(SPSR,SPSR_SPI2X);

				#elif 				SPI_u8ClockRate == DIVIDED_BY_2

				CLR_BIT(SPCR,SPCR_SPR0);
				CLR_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPSR,SPSR_SPI2X);

				#elif 				SPI_u8ClockRate == DIVIDED_BY_8

				SET_BIT(SPCR,SPCR_SPR0);
				CLR_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPSR,SPSR_SPI2X);

				#elif 				SPI_u8ClockRate == DIVIDED_BY_32

				CLR_BIT(SPCR,SPCR_SPR0);
				SET_BIT(SPCR,SPCR_SPR1);
				SET_BIT(SPSR,SPSR_SPI2X);

				#else

					#error Wrong SPI_u8ClockRate Configuration Value

				#endif
		#elif 				SPI_u8ROLE == SLAVE

		CLR_BIT(SPCR,SPCR_MSTR) ;		// SLAVE SELECTION

		#else

			#error Wrong SPI_u8ROLE Configuration Value

		#endif

		#if 				SPI_u8InterruptEnable == ENABLE

		SET_BIT(SPCR,SPCR_SPIE) ;   	// ENABLE INTERRUPT

		#elif 				SPI_u8InterruptEnable == DISABLE

		CLR_BIT(SPCR,SPCR_SPIE) ;		// DISABLE INTERRUPT

		#else

			#error Wrong SPI_u8InterruptEnable Configuration Value

		#endif

		#if 				SPI_u8DataOrder == LSB_FIRST

		SET_BIT(SPCR,SPCR_DORD) ;   	// LSB FIRST

		#elif 				SPI_u8DataOrder == MSB_FIRST

		CLR_BIT(SPCR,SPCR_DORD) ;		// MSB FIRST

		#else

			#error Wrong SPI_u8DataOrder Configuration Value

		#endif

		#if 				SPI_u8ClockPolarity == IDLE_HIGH

		SET_BIT(SPCR,SPCR_CPOL) ;   	// IDLE HIGH

		#elif 				SPI_u8ClockPolarity == IDLE_LOW

		CLR_BIT(SPCR,SPCR_CPOL) ;		// IDLE LOW

		#else

			#error Wrong SPI_u8ClockPolarity Configuration Value

		#endif

		#if 				SPI_u8ClockPhase == SAMPLE_FIRST

		CLR_BIT(SPCR,SPCR_CPHA) ;   	// SAMPLE FIRST

		#elif 				SPI_u8ClockPhase == SETUP_FIRST

		SET_BIT(SPCR,SPCR_CPHA) ;		// SETUP FIRST

		#else

			#error Wrong SPI_u8ClockPhase Configuration Value

		#endif

											/* SPI ENABLE */

		SET_BIT(SPCR,SPCR_SPE) ;


	}

	void SPI_voidInit		   	( uint8 copy_u8Role )
	{

												/* DATA ORDER */

		CLR_BIT(SPCR,SPCR_DORD) ;     // the MSB of the data word is transmitted first.

												/* MASTER / SLAVE SELECT */

		if ( ( copy_u8Role == 'M' ) || ( copy_u8Role == 'm' ) )
		{
			SET_BIT(SPCR,SPCR_MSTR) ;   	// MASTER SELECTION

												/* CLOCK RATE SELECT */

			CLR_BIT(SPCR,SPCR_SPR0) ; 			// MAXIMUM SPEED
			CLR_BIT(SPCR,SPCR_SPR1) ; 			// MAXIMUM SPEED
			SET_BIT(SPSR,SPSR_SPI2X) ; 			// MAXIMUM SPEED

		}
		else if ( ( copy_u8Role == 'S' ) || ( copy_u8Role == 's' ) )
		{
			CLR_BIT(SPCR,SPCR_MSTR) ;		// SLAVE SELECTION
		}
		else
		{
			// DO NOTHING
		}

												/* SPI ENABLE */

		SET_BIT(SPCR,SPCR_SPE) ;

	}

	uint8 SPI_u8Transceive 		( uint8 copy_u8Data)
	{
												/* PUT DATA ON SPDR */
		SPDR = copy_u8Data ;

												/* WAIT FOR SPIF TO BE RAISED */

		while ( (GET_BIT(SPSR,SPSR_SPIF)) != 1 ) ;

												/* RETURN SPDR */

		return SPDR ;
	}

	uint8 SPI_u8SetCallBack (  void(*copy_pvNotification)(void) )

		{
			uint8 Local_u8ErrorState = OK ;
			if (  copy_pvNotification != NULL  )
			{
						/* CONVERT THE NOTIFICATION FUNCTION LOCAL VARIABLES TO GLOBAL */

				SPI_pvNotificationFunc = copy_pvNotification ;
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}

			return Local_u8ErrorState ;
		}
								/* Serial Transfer Complete ISR */

	void __vector_12 ( void )			__attribute__((signal)) ;
	void __vector_12 ( void )
	{

	if ( SPI_pvNotificationFunc != NULL )
	{
	SPI_pvNotificationFunc() ;
	}
	else
	{
	// DO NOTHING
	}

	}
