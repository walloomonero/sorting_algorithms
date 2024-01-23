#include "sort.h"

int hoare_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t size, int left, int right);

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
 * hoare_partition - To order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: Size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Returns: The final partition index.
 *
 * Description: To use the last element of the partition as the pivot.
 *              To print the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, up, down;

	pivot = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - To implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: Size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: To use the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partit;

	if (right - left > 0)
	{
		partit = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partit - 1);
		hoare_sort(array, size, partit, right);
	}
}

/**
 * quick_sort_hoare - To sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: To use the Hoare partition scheme.
 *				To print the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
