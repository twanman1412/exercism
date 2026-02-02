#include <stdint.h>

#ifndef DARTS_H
#define DARTS_H

typedef struct coordinate_t {
	double x;
	double y;
} coordinate_t;

uint8_t score(struct coordinate_t coordinate);

#endif
