#include <stdint.h>

#include "pangram.h"

bool is_pangram(const char *sentence)
{
	if (!sentence) return false;

	char* letter = (char*) sentence;
	int32_t res = 0;

	while (*letter)
	{
		if (*letter >= 'A' && *letter <= 'Z')
		{
			res = res | (1 << (*(letter++) - 'A'));
			continue;
		}

		if (*letter >= 'a' && *letter <= 'z')
		{
			res = res | (1 << (*(letter++) - 'a'));
			continue;
		}

		letter++; // ignore non letters
	}

	return res == 0x3FFFFFF;
}
