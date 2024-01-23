#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - To print an array of integers
 *
 * @array: The array to be printed
 * @size: The number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t n;

	n = 0;
	while (array && n < size)
	{
		if (n > 0)
			printf(", ");
		printf("%d", array[n]);
		++n;
	}
	printf("\n");
}
