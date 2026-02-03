#include <stdint.h>

#include "isogram.h"

bool is_isogram(const char phrase[])
{
	if (!phrase) return false;

	char* letter = (char*) phrase;
	int32_t res = 0;

	while (*letter)
	{
		if (*letter >= 'A' && *letter <= 'Z')
		{
			if (res >> (*letter - 'A') & 1) return false;

			res = res | (1 << (*(letter++) - 'A'));
			continue;
		}

		if (*letter >= 'a' && *letter <= 'z')
		{
			if (res >> (*letter - 'a') & 1) return false;

			res = res | (1 << (*(letter++) - 'a'));
			continue;
		}

		letter++; // ignore non letters
	}

	return true;
}
