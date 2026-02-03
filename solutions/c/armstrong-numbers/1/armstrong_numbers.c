#include <math.h>

#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
	int num_digit = 0;
	int local = candidate;
	while (local > 0)
	{
		local /= 10;
		num_digit++;
	}

	int armstrong = 0;
	local = candidate;
	while (local > 0)
	{
		const int digit = local % 10;
		armstrong += pow(digit, num_digit);
		local /= 10;
	}

	return armstrong == candidate;
}
