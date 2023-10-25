#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a1: The first integer to swap.
 * @b1: The second integer to swap.
 */
void swap_ints(int *a1, int *b1)
{
	int tmp;

	tmp = *a1;
	*a1 = *b1;
	*b1= tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @arrays: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *arrays, size_t size)
{
	size_t gap, i, k;

	if (arrays == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			k = i;
			while (k >= gap && arrays[k - gap] > arrays[k])
			{
				swap_ints(arrays + k, arrays + (k - gap));
				k -= gap;
			}
		}
		print_array(arrays, size);
	}
}
