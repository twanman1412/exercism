#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "dnd_character.h"

int ability(void)
{
	srand(time(NULL));

	int min = 0;

	int roll1 = (rand() / RAND_MAX) * 5 + 1;
	if (roll1 <= min) min = roll1;

	int roll2 = (rand() / RAND_MAX) * 5 + 1;
	if (roll2 <= min) min = roll2;

	int roll3 = (rand() / RAND_MAX) * 5 + 1;
	if (roll3 <= min) min = roll3;

	int roll4 = (rand() / RAND_MAX) * 5 + 1;
	if (roll4 <= min) min = roll4;

	return roll1 + roll2 + roll3 + roll4 - min;
}

int modifier(int score)
{
	return floor((score - 10) / 2.0);
}

dnd_character_t make_dnd_character(void)
{
	dnd_character_t res = {
	   .strength = ability(),
	   .dexterity = ability(),
	   .constitution = ability(),
	   .intelligence = ability(),
	   .wisdom = ability(),
	   .charisma = ability(),
	};

	res.hitpoints = 10 + modifier(res.constitution);

	return res;
}
