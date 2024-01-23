#include "sort.h"

void swap_ints(int *a, int *b);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);

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
 * lomuto_partition - Orders a subset of an array of integers according to
 * lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Returns: 
 * The index of the pivot after partitioning.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - To implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partit;

	if (right - left > 0)
	{
		partit = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partit - 1);
		lomuto_sort(array, size, partit + 1, right);
	}
}

/**
 * quick_sort - To sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 *              To print the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
