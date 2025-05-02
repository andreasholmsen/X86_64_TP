#include <stdint.h>
#include "io.h"

#ifdef ARM
	#include "armv7m_reset.h"
#endif

#define BUFSIZE 9

#ifndef BUFOVERFLOW
	#define BUFOVERFLOW 0
#endif 

int sub02( int * bb ) {
	int i;
	for	( i = 0; i < BUFSIZE - 1 +BUFOVERFLOW; ++i )
		bb[i+1] += bb[i];
	return bb[BUFSIZE-1];
}

int sub01( unsigned int aa ) {
	int i;
	int buf[BUFSIZE];
	for	( i = 0; i < BUFSIZE; ++i )
		buf[i] = aa + i*i;
	i = sub02( buf );
	return i;
}

int main() {
	expose( sub01( 0x1000 ) );
	#ifdef ARM
		Reset();
	#endif
	return 0;
}
