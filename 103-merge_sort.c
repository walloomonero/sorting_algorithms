#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_subar(int *subar, int *buf, size_t fron, size_t mid, size_t bac);
void merge_sort_recursive(int *subar, int *buf, size_t fron, size_t bac);

/**
 * merge_subar - To sort a subarray of integers.
 * @subar: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted subarray.
 * @fron: The front index of the array.
 * @mid: The middle index of the array.
 * @bac: The back index of the array.
 */
void merge_subar(int *subar, int *buf, size_t fron, size_t mid,
		size_t bac)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subar + fron, mid - fron);

	printf("[right]: ");
	print_array(subar + mid, bac - mid);

	for (i = fron, j = mid; i < mid && j < bac; k++)
		buf[k] = (subar[i] < subar[j]) ? subar[i++] : subar[j++];
	for (; i < mid; i++)
		buf[k++] = subar[i];
	for (; j < bac; j++)
		buf[k++] = subar[j];
	for (i = fron, k = 0; i < bac; i++)
		subar[i] = buf[k++];

	printf("[Done]: ");
	print_array(subar + fron, bac - fron);
}

/**
 * merge_sort_recursive - To implement the merge sort algorithm
 *through recursion.
 * @subar: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted result.
 * @fron: The front index of the subarray.
 * @bac: The back index of the subarray.
 */
void merge_sort_recursive(int *subar, int *buf, size_t fron, size_t bac)
{
	size_t mid;

	if (bac - fron > 1)
	{
		mid = fron + (bac - fron) / 2;
		merge_sort_recursive(subar, buf, fron, mid);
		merge_sort_recursive(subar, buf, mid, bac);
		merge_subar(subar, buf, fron, mid, bac);
	}
}

/**
 * merge_sort - To sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: To implement the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recursive(array, buf, 0, size);

	free(buf);
}
