#include "perfect_numbers.h"

kind classify_number(int number)
{
	if (number <= 0) return -1;

	int factor_sum = 0;

	for (int i = 1; i < (number + 2) / 2; i++)
	{
		if (number % i == 0) factor_sum += i;
	}

	if (factor_sum == number) return PERFECT_NUMBER;
	if (factor_sum > number)  return ABUNDANT_NUMBER;
	return DEFICIENT_NUMBER;
}
