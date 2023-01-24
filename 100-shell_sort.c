#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the shell sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * Return: nothing void
 */

void shell_sort(int *array, size_t size)
{
	size_t cLoop1, cLoop2, tmp, interval = 0;
	int valueToInsert;

	if (array == NULL || size < 2)
		return;

	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{

		for (cLoop1 = interval; cLoop1 < size; cLoop1++)
		{
			valueToInsert = array[cLoop1];

			cLoop2 = cLoop1;

			while (cLoop2 > interval - 1 && array[cLoop2 - interval] >= valueToInsert)
			{
				tmp = array[cLoop2 - interval];
				array[cLoop2 - interval] = array[cLoop2];
				array[cLoop2] = tmp;
				cLoop2 -= interval;
			}
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
