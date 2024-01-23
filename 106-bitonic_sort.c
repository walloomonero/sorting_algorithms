#include "sort.h"

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size,
size_t start, size_t seq, char flow);

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
 * bitonic_merge - To sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: Size of the array.
 * @start: Starting index of the sequence in array to sort.
 * @seque: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seque,
		char flow)
{
	size_t n, jump = seque / 2;

	if (seque > 1)
	{
		for (n = start; n < start + jump; n++)
		{
			if ((flow == UP && array[n] > array[n + jump]) ||
			    (flow == DOWN && array[n] < array[n + jump]))
				swap_ints(array + n, array + n + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - To convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seque: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start,
size_t seque, char flow)
{
	size_t cut = seque / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seque > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seque, size, str);
		print_array(array + start, seque);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seque, flow);

		printf("Result [%lu/%lu] (%s):\n", seque, size, str);
		print_array(array + start, seque);
	}
}

/**
 * bitonic_sort - To sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: To print the array after each swap.
 * Only works for size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
