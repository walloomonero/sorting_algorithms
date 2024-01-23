#include "sort.h"

/**
 * swap_ints - To swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - To sort an array of integers in ascending
 * order using the shell sort algorithm.
 * @array: An array of integers.
 * @size:  Size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t spac, n, w;

	if (array == NULL || size < 2)
		return;

	for (spac = 1; spac < (size / 3);)
		spac = spac * 3 + 1;

	for (; spac >= 1; spac /= 3)
	{
		for (n = spac; n < size; n++)
		{
			w = n;
			while (w >= spac && array[w - spac] > array[w])
			{
				swap_ints(array + w, array + (w - spac));
				w -= spac;
			}
		}
		print_array(array, size);
	}
}
