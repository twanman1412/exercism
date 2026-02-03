#include <stdlib.h>
#include <string.h>

#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
	time_t future = input + 1000000000;
	struct tm* tm = gmtime(&future);
	strftime(output, size, "%Y-%m-%d %H:%M:%S", tm);
}

