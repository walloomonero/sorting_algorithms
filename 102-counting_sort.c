#include "sort.h"

/**
 * get_max - To get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Returns: Maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxi, ;n

	for (maxi = array[0], n = 1; n < size; n++)
	{
		if (array[n] > maxi)
			maxi = array[n];
	}

	return (maxi);
}

/**
 * counting_sort - To Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: To print the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxi, n;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxi = get_max(array, size);
	count = malloc(sizeof(int) * (maxi + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (n = 0; n < (max + 1); n++)
		count[n] = 0;
	for (n = 0; n < (int)size; n++)
		count[array[n]] += 1;
	for (n = 0; n < (maxi + 1); n++)
		count[n] += count[n - 1];
	print_array(count, maxi + 1);

	for (n = 0; n < (int)size; n++)
	{
		sorted[count[array[n]] - 1] = array[n];
		count[array[n]] -= 1;
	}

	for (n = 0; n < (int)size; n++)
		array[n] = sorted[n];

	free(sorted);
	free(count);
}
