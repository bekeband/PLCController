#include "TestOuts.h"

void TestPrintf(const char* message, ...) {
	va_list pl;

	va_start(pl, message);

	vfprintf(stdout, message, pl);
	va_end(pl);
}

