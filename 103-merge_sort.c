#include "sort.h"
/**
 * merge - Sort a subarray of integers.
 * @array: A subarray of an array of integers to sort.
 * @output: A buffer to store the sorted subarray.
 * @low: The front index of the array.
 * @mid: The middle index of the array.
 * @high: The back index of the array.
 */
void merge(int *array, int *output, size_t low, size_t mid, size_t high)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + low, mid - low);

	printf("[right]: ");
	print_array(array + mid, high - mid);

	for (i = low, j = mid; i < mid && j < high; k++)
		output[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		output[k++] = array[i];
	for (; j < high; j++)
		output[k++] = array[j];
	for (i = low, k = 0; i < high; i++)
		array[i] = output[k++];

	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
 *mergesort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@array: array of integers
 *@output: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@low: fisrt element position
 *@high: last element position
 *Return: void
 */
void mergesort(int *array, int *output, int low, int high)
{
	size_t mid;

	if (high - low > 1)
	{
		mid = low + (high - low) / 2;
		mergesort(array, output, low, mid);
		mergesort(array, output, mid, high);
		merge(array, output, low, mid, high);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *newarray;

	if (array == NULL || size < 2)
		return;

	newarray = malloc(sizeof(int) * size);
	if (newarray == NULL)
		return;

	mergesort(array, newarray, 0, size);

	free(newarray);
}
