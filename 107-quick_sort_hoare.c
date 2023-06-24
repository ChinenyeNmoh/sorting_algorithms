#include "sort.h"
/**
 *qshoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@low: first array element
 *@high: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int qshoare_partition(int *array, int low, int high, int size)
{
	int temp;
	int start = low - 1, end = high + 1;
	int pivot = array[high];

	while (1)
	{

		do {
			start++;
		} while (array[start] < pivot);
		do {
			end--;
		} while (array[end] > pivot);
		if (start >= end)
			return (start);
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
}
/**
 *quicksort - qucksort algorithm implementation
 *@array: array
 *@low: first array element
 *@high: last array element
 *@size: array size
 */
void quicksort(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t pos = 0;

	if (low < high)
	{
		pos = qshoare_partition(array, low, high, size);
		quicksort(array, low, pos - 1, size);
		quicksort(array, pos, high, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
