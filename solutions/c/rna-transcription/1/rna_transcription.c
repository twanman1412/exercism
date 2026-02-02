#include <stdlib.h>
#include <string.h>

#include "rna_transcription.h"

char *to_rna(const char *dna)
{
	const char* res = malloc((strlen(dna) + 1) * sizeof( char));
	char* rna = (char*) res;
	while (*dna)
	{
		switch (*dna)
		{
			case 'G': 
				*rna = 'C';
				break;
			case 'C':
				*rna = 'G';
				break;
			case 'T':
				*rna = 'A';
				break;
			case 'A':
				*rna = 'U';
				break;
		}

		dna++;
		rna++;
	}

	*rna = '\0';
	return (char*) res;
}
