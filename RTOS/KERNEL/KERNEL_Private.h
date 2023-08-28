#ifndef 	KERNEL_PRIVATE_H 
#define 	KERNEL_PRIVATE_H 

	typedef struct
	{
		uint16 	Periodicity ;
		void 	(*TaskFunc)(void);
		uint8 	Status ;
	}Task_t ;

	static void Scheduler ( void ) ;

	#define			TASK_RESUMED		0U
	#define			TASK_SUSPENDED		1U

	#define			MAX 		65535U

#endif  
