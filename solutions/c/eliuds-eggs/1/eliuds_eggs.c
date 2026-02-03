#include "eliuds_eggs.h"

int egg_count(int encoded)
{
	int res = 0;

	while (encoded != 0)
	{
		res += encoded & 1;
		encoded = encoded >> 1;
	}

	return res;
}
