#include "space_age.h"

float age(planet_t planet, int64_t seconds)
{
	const float earth_year_seconds = 31557600.0f;
	float orbital_periods[] = 
	{
		0.2408467f,
		0.61519726f,
		1.0f,
		1.8808158f,
		11.862615f,
		29.447498f,
		84.016846f,
		164.79132f
	};

	if (planet < 0 || planet > 7) 
	{
		return -1.0f;
	}

	return seconds / (orbital_periods[planet] * earth_year_seconds);
}
