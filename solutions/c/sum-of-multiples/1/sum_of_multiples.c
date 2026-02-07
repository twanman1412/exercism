#include <stdbool.h>
#include <stdlib.h>

#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *item_levels, const size_t number_of_items, const unsigned int level)
{
	if (level == 0 || number_of_items == 0) return 0;

	bool *added = calloc(level + 1, sizeof(bool));
	unsigned int sum = 0;

	for (unsigned int i = 0; i < number_of_items; i++)
	{
		int item_level = item_levels[i];
		for (unsigned int j = item_level; item_level > 0 && j < level; j += item_level)
		{
			if (!added[j])
			{
				added[j] = true;
				sum += j;
			}
		}
	}

	free(added);
	return sum;
}
