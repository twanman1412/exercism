#include "binary.h"

int convert(const char *input)
{
	int res = 0;
	char* bit = (char*) input;

	while (*bit)
	{
		switch (*(bit++))
		{
			case '0':
				res = res << 1;
				break;
			case '1':
				res = (res << 1) + 1;
				break;
			default:
				return -1;
		}
	}

	return res;
}
