#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 0, i, j;
    int temp;

    while (interval < size)
    {
        interval = interval * 3 + 1;
    }
    interval = (interval - 1) / 3;
    while (interval > 0)
    {
        for (i = interval; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
        interval = (interval - 1) / 3;
        print_array(array, size);
        printf("\n");
    }
}
