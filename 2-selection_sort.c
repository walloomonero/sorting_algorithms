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
 * selection_sort - To sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: To prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *smal;
	size_t n, w;

	if (array == NULL || size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		smal = array + n;
		for (w = n + 1; w < size; w++)
			smal = (array[w] < *smal) ? (array + w) : smal;

		if ((array + n) != smal)
		{
			swap_ints(array + n, smal);
			print_array(array, size);
		}
	}
}
