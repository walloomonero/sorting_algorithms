#include "sort.h"

void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

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
 * max_heapify - To turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: Size of the tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - To sort an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: To implement the sift-down heap sort algorithm.
 * 		To Print the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int n;

	if (array == NULL || size < 2)
		return;

	for (n = (size / 2) - 1; n >= 0; n--)
		max_heapify(array, size, size, n);

	for (n = size - 1; n > 0; n--)
	{
		swap_ints(array, array + n);
		print_array(array, size);
		max_heapify(array, size, n, 0);
	}
}
