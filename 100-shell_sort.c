#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j; i >= gap; i = i - gap)
			{
				if (array[i - gap] > array[i])
				{
					temp = array[i];
					array[i] = array[i - gap];
					array[i - gap] = temp;
				}
			}
		}
		print_array(array, size);
	}
}
