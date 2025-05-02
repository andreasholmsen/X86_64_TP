#include <stdint.h>


#ifdef ARM
	#include "armv7m_printf.h"
	#include "armv7m_reset.h"
#endif

#ifdef x86
	#include <stdio.h>
	#define Reset()
#endif

#ifdef x64
	#include <stdio.h>
	#define Reset()
#endif


int main ( void )
{
	printf("Hello World\n");
	Reset();
	return(0);
}
