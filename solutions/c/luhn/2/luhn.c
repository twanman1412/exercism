#include <string.h>

#include "luhn.h"

bool luhn(const char *num)
{
	int len = strlen(num);
	if (len <= 1) return false;

	int sum = 0;
	int digits = 0;
	bool d = false;

	for (int i = len - 1; i >= 0; i--)
	{
		char c = num[i];
		if (c == ' ') continue;

		if (c < '0' || c > '9')
		{
			return false;
		}

		int val = c - '0';
		if (d)
		{
			val *= 2;
			if (val > 9) val -= 9;
		}

		sum += val;
		digits++;
		d = !d;
	}

	return (digits > 1) && sum % 10 == 0;
}
