#include "sort.h"
/**
 * maxheapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @i: The max node of the binary tree.
 */
void maxheapify(int *array, int size, int base, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp;

	if (left < base && array[left] > array[largest])
		largest = left;
	if (right < base && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		maxheapify(array, size, base, largest);
	}
}
/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int temp, i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		maxheapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		maxheapify(array, size, i, 0);
	}
}
