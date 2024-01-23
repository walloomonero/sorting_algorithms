#include "sort.h"

int get_max(int *array, int size);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);

/**
 * get_max - To get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: Size of the array.
 * @maxi: Maximum integer
 * Returns: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxi, n;

	for (maxi = array[0], n = 1; n < size; n++)
	{
		if (array[n] > maxi)
			maxi = array[n];
	}

	return (maxi);
}

/**
 * radix_counting_sort - To sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 * @signf: The significant digit to sort on.
 * @buf: buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int signf, int *buf)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t n;

	for (n = 0; n < size; n++)
		count[(array[n] / signf) % 10] += 1;

	for (n = 0; n < 10; n++)
		count[n] += count[n - 1];

	for (n = size - 1; (int)n >= 0; n--)
	{
		buf[count[(array[n] / signf) % 10] - 1] = array[n];
		count[(array[n] / signf) % 10] -= 1;
	}

	for (n = 0; n < size; n++)
		array[n] = buf[n];
}

/**
 * radix_sort - To sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: To implement the LSD radix sort algorithm.
 *		To print the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maxi, signf, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	maxi = get_max(array, size);
	for (signf = 1; maxi / signf > 0; signf *= 10)
	{
		radix_counting_sort(array, size, signf, buf);
		print_array(array, size);
	}

	free(buf);
}
