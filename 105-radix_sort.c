#include "sort.h"

/**
 * _max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int _max(const int *array, size_t size)
{
	int maxm = array[0];
	size_t  i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > maxm)
			maxm = array[i];
	}
	return (maxm);
}
/**
 * countsort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @output: A buffer to store the sorted array.
 * @size: The size of the array.
 * @place: The significant digit to sort on.
 */
void countsort(int *array, int *output, size_t size, int place)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}
/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	int max, place;
	int *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	max = _max(array, size);
	for (place = 1; max / place > 0; place *= 10)
	{
		countsort(array, output, size, place);
		print_array(array, size);
	}
}
