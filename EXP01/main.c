#include <stdint.h>
#include "io.h"

#ifdef ARM
	#include "armv7m_reset.h"
#endif

void sub01() {
	int aa, bb, cc, dd, ee;
	aa = seed(1);
	bb = aa + 1;
	cc = aa - 1;
	dd = aa << 3;
	ee = aa + bb + cc + dd;
	expose( ee );
}

int main() {
	sub01();
	#ifdef ARM
		Reset();
	#endif
	return 0;
}
