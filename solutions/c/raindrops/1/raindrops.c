#include <stdbool.h>
#include <stdio.h>

#include "raindrops.h"

void convert(char result[], int drops)
{
	bool pling = drops % 3 == 0;
	bool plang = drops % 5 == 0;
	bool plong = drops % 7 == 0;

	if (pling || plang || plong) 
	{
		sprintf(result, "%s%s%s", pling ? "Pling" : "", plang ? "Plang" : "", plong ? "Plong" : ""); 
		return;
	}

	sprintf(result, "%d", drops);
}
