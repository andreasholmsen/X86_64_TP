#include "io.h"

#ifdef ARM
	#include "armv7m_printf.h"
#else
	#include <stdio.h>
#endif

void expose( int x ) {
	printf("%d=0x%08x\n", x, x );
}

int seed( int i ) {
	return i+1;
}
