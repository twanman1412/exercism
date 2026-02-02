#include <stdlib.h>
#include <string.h>

#include "rna_transcription.h"

static const char map[128] = {
	['G'] = 'C',
	['C'] = 'G',
	['T'] = 'A',
	['A'] = 'U',
};

char *to_rna(const char *dna)
{
	if (!dna) return NULL;

	char* res = malloc(strlen(dna) + 1);
	if (!res) return NULL;

	char* rna = res;
	while (*dna)
	{
		*(rna++) = map[(unsigned char) *(dna++)];
	}

	*rna = '\0';
	return (char*) res;
}
