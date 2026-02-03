#include <math.h>

#include "resistor_color_trio.h"

static const unit units[4] = { UNITS };

resistor_value_t color_code(resistor_band_t* t)
{
	resistor_value_t res = {
		.value = t[0] * 10 + t[1],
		.unit = OHMS,
	};

	res.value *= (int) pow(10, t[2] % 3);
	res.unit = units[t[2] / 3];

	if (res.value > 0 && res.value % 1000 == 0)
	{
		res.value /= 1000;
		res.unit = units[res.unit + 1];
	}
	
	return res;
}
