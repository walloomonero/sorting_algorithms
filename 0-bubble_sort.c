#include "sort.h"

/**
 * swap_ints - To swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - To sort an array of integers in ascending order.
 * @array: An array of integers to be  sorted.
 * @size: Size of the array.
 *
 * Description: To print the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, len = size;
	bool bubb = false;

	if (array == NULL || size < 2)
		return;

	while (bubb == false)
	{
		bubb = true;
		for (n = 0; n < len - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap_ints(array + n, array + n + 1);
				print_array(array, size);
				bubb = false;
			}
		}
		len--;
	}
}
