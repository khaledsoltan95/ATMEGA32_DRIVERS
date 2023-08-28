#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
	
											/* Functions Deceleration */

	void SPI_voidInitial 		( void ) ;

	void SPI_voidInit			( uint8 copy_u8Role ) ;

	uint8 SPI_u8Transceive 		( uint8 copy_u8Data);

	uint8 SPI_u8SetCallBack		( void(*copy_pvNotification)(void) ) ;


#endif
