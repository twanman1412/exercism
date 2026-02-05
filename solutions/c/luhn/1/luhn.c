#include <stdlib.h>
#include <string.h>

#include "luhn.h"

bool luhn(const char *num)
{
	int len = strlen(num);
	if (len <= 1) return false;

	char* stripped = malloc(len + 1);
	char* dst = stripped;
	int l = 0;
	for (int i = 0; i < len; i++)
	{
		char c = num[i];
		if (c == ' ') continue;

		if (c < '0' || c > '9')
		{
			return false;
		}

		*(dst++) = c;	
		l++;
	}
	stripped[l] = '\0';

	if (l <= 1) return false;

	for (int j = l - 2; j >= 0; j -= 2)
	{
		int val = (stripped[j] - '0') * 2;
		if (val > 9) val -= 9;

		stripped[j] = val + '0';
	}

	int sum = 0;
	for (int j = 0; j < l; j++)
	{
		sum += stripped[j] - '0';
	}

	return sum % 10 == 0;
}
