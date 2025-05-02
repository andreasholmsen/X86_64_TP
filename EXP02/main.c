#include <stdint.h>
#include "io.h"

#ifdef ARM
	#include "armv7m_reset.h"
#endif

int sub01( int aa, int bb, int cc, int dd, int ee ) {
	return aa * bb + aa * cc + bb * cc + cc * dd * ee - aa * ee;
}

int main() {
	int xx;
	xx = sub01( seed(1), 3, seed(3), 4, 5 );
	expose( xx );
	#ifdef ARM
		Reset();
	#endif
	return 0;
}
