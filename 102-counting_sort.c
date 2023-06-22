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
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, k;

	if (array == NULL || size < 2)
		return;

	output = (int *)malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	k = _max(array, size);
	count = (int *)malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}
	/*initialize count array with 0*/
	for (i = 0; i < (k + 1); i++)
		count[i] = 0;
	/*Count the number of occurrences of each number in the main array*/
	for (i = 0; i < size; i++)
		count[array[i]]++;
	/*Update the count array to store the actual positions in the output array*/
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	/*Place elements in the output array according to the count array*/
	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}
	/*Copy output to the original array*/
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
