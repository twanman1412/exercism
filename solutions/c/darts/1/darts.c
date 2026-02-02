#include <math.h>

#include "darts.h"

uint8_t score(struct coordinate_t coordinate) 
{
	double x = coordinate.x;
	double y = coordinate.y;

	double distance = sqrt(x * x + y * y);
	if (distance <= 1.0) 
	{
		return 10;
	} 

	if (distance <= 5.0) 
	{
		return 5;
	} 

	if (distance <= 10.0) 
	{
		return 1;
	} 

	return 0;
}
