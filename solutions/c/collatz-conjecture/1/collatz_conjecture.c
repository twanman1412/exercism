#include "collatz_conjecture.h"

int steps(int start)
{

	if (start <= 0) return ERROR_VALUE;

	int steps = 0;
	for (; start != 1; steps++)
	{
		if ((start & 1) == 0) 
		{ // If the number is even
			start >>= 1;
		}
		else
		{ // If the number is odd
			start *= 3;
			start += 1;
		}
	}

	return steps;
}
