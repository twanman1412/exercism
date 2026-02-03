#include "binary_search.h"
#include <stddef.h>

const int *binary_search(int value, const int *arr, size_t length)
{
	if (!arr || length < 1) return NULL;

	size_t min = 0;
	size_t max = length;


	while (min < max)
	{
		size_t middle = (min + max) / 2;

		if (arr[middle] == value) return arr + middle;

		if (middle == min)
		{
			if (arr[max] == value) return arr + max;
			return NULL;
		}

		if (arr[middle] < value)
		{
			min = middle;
			continue;
		}

		max = middle;
	}

	if (arr[min] == value) return arr + min;
	return NULL;
}
