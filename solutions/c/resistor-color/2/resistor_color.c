#include "resistor_color.h"

int color_code(resistor_band_t t)
{
	return (int) t;
}

static resistor_band_t bands[10] = { COLOURS };
resistor_band_t* colors()
{
	return bands;
}
