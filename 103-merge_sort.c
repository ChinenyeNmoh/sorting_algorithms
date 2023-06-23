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
	size_t i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	printf("Merging...\n[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);
	while (i <= mid && j <= high)
	{
		if (array[i] < array[j])
		{
			output[k] = array[i];
			i++;
		}
		else
		{
			output[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		output[k] = array[i], i++, k++;
	}
	while (j <= high)
	{
		output[k] = array[j], j++, k++;
	}
	for (i = low, k = low; i <= high; i++)
	{
		array[i] = output[k++];
	}
	printf("[Done]: ");
	print_array(array + low, high - low + 1);
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
	int mid;

	mid = (low + high) / 2;

	if (low < high)
	{
	mergesort(array, output, low, mid);
	mergesort(array, output, mid + 1, high);
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

	mergesort(array, newarray, 0, size - 1);

	free(newarray);
}
