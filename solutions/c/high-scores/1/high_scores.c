#include "high_scores.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t latest(const int32_t *scores, size_t scores_len)
{
	return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
	scores_len = scores_len; // make the comiler shut up

	int32_t max = 0;

	for (size_t i = 0; i < scores_len; i++)
	{
		if (scores[i] >= max) max = scores[i];
	}

	return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
	int32_t* score = (int32_t*) scores;
	size_t iterations = scores_len >= 3 ? 3 : scores_len;

	for (size_t i = 0; i < iterations; i++)
	{
		for (size_t j = scores_len - 1; j > 0; j--)
		{
			if (scores[j] > scores[j - 1])
			{
				int32_t tmp = score[j - 1];
				score[j - 1] = score[j];
				score[j] = tmp;
			}
		}

		output[i] = score[i];
	}


	return iterations;
}
