#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sigs, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the sigsnificant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sigs: The sigsnificant digit to sort on.
 * @buffer: A bufferer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sigs, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sigs) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / sigs) % 10] - 1] = array[i];
		count[(array[i] / sigs) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each sigsnificant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sigs, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);
	for (sigs = 1; max / sigs > 0; sigs *= 10)
	{
		radix_counting_sort(array, size, sigs, buffer);
		print_array(array, size);
	}

	free(buffer);
}
