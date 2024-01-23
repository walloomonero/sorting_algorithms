#include "sort.h"

int get_max(int *array, int size);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);

/**
 * get_max - To get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxi, i;

	for (maxi = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxi)
			maxi = array[i];
	}

	return (maxi);
}

/**
 * radix_counting_sort - To sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 * @sig: The significant digit to sort on.
 * @buf: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buf)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buf[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buf[i];
}

/**
 * radix_sort - To sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size:  Size of the array.
 *
 * Description: To implement the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maxi, sig, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	maxi = get_max(array, size);
	for (sig = 1; maxi / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buf);
		print_array(array, size);
	}

	free(buf);
}
