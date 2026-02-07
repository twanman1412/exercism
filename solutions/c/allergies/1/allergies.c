#include <stdlib.h>
#include <string.h>

#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score)
{
	return ((1 << allergen) & score);
}

allergen_list_t get_allergens(int score)
{
	int count = 0;
	bool* allergens = malloc(ALLERGEN_COUNT * sizeof(bool));

	for (int i = 0; score > 0 && i < ALLERGEN_COUNT; i++)
	{
		if (score & 1)
		{
			allergens[i] = true;
			count++;
		}
		else
			allergens[i] = false;

		score = score >> 1;
	}

	allergen_list_t list = {
		.count = count,
	};

	memcpy(list.allergens, allergens, ALLERGEN_COUNT * sizeof(bool));
	free(allergens);

	return list;
}
