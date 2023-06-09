#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_Interface.h"
#include "GIE_Reg.h"

	void GIE_voidEnableGlobal  ( void ) 
	{
		__asm volatile ("SEI"); 						// ASSEMBLY INSTRUCTION
		/* SET_BIT ( SREG , SREG_I ); ANOTHER WAY WITHOUT USING ASSEMBLY LANGUAGE*/
	}
	
	void GIE_voidDisableGlobal ( void ) 
	{
		__asm volatile ("CLI"); 
		/* CLR_BIT ( SREG , SREG_I ); ANOTHER WAY WITHOUT USING ASSEMBLY LANGUAGE*/
	}