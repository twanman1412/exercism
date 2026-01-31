#include "resistor_color.h"

int color_code(resistor_band_t t)
{
	return (int) t;
}

resistor_band_t* colors()
{
	static resistor_band_t bands[10] = { BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE };
	return bands;
}
