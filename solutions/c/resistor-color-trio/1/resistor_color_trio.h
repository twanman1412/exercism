#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>

#define COLOURS BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE,
#define UNITS OHMS, KILOOHMS, MEGAOHMS, GIGAOHMS

typedef enum {
	COLOURS
} resistor_band_t;

typedef enum {
	UNITS
} unit;

typedef struct {
	uint32_t value;
	unit unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t* t);

#endif
