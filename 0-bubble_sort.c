#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a1: The first integer to be swapped.
 * @b1: The second integer to be swapped.
 */
void swap_ints(int *a1, int *b1)
{
	int tmp;

	tmp = *a1;
	*a1 = *b1;
	*b1 = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of an array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
