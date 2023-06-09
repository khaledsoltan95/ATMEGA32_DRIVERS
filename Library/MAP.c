#include "STD_TYPES.h"
#include "MAP.h"

sint32 MAP ( sint32 InputRangeMin , sint32 InputRangeMax ,  sint32 OutputRangeMin , sint32 OutPutRangeMax , sint32 InputValue )
{
	sint32 Ratio ; 
	sint32 OutputValue ; 
	
										/* Calculate the ratio of the input value in the input range */
										
    Ratio = ((InputValue - InputRangeMin) * 100u ) / (InputRangeMax - InputRangeMin) ; 
    
										/* Map the ratio to the output range */
										
    OutputValue = ( ( Ratio * (OutPutRangeMax - OutputRangeMin)) / 100u ) + OutputRangeMin ; 
	
										/* Return the output value */
	
    return OutputValue ; 
}