#include "sort.h"
#include "string.h"

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @prmArray: array of int to sort
 * @prmSize: size of the array
 * Return: Nothing void
 */
void counting_sort(int *prmArray, size_t prmSize)
{
	unsigned int i, j;
	int maxValue = 0, value, index;
	int *B = malloc(sizeof(int) * prmSize), *tmp;

	memcpy(B, prmArray, sizeof(int) * prmSize);

	for (i = 0; i < prmSize; i++)
		if (prmArray[i] > maxValue)
			maxValue = B[i];

	tmp = malloc(sizeof(int) * (maxValue + 1));

	for (i = 0; (int)i <= maxValue; i++)
		*(tmp + i) = 0;

	for (j = 0; j < prmSize; j++)
		*(tmp + B[j]) = *(tmp + B[j]) + 1;

	for (i = 1; (int)i <= maxValue; i++)
		tmp[i] = tmp[i] + tmp[i - 1];

	print_array(tmp, maxValue + 1);

	for (j = prmSize - 1; (int)j >= 0; j--)
	{
		value = *(B + j);
		index = tmp[value];
		*(prmArray + index - 1) = value;
		tmp[value] = tmp[value] - 1;
	}

	free(B);
	free(tmp);
}
