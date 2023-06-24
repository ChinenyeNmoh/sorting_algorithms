#include "sort.h"
/**
 * merge - sort bitonic sequences recursively in both orders
 * @array: array
 * @size: size of the array
 * @low: first element
 * @n: The size of the sequence to sort.
 * @direction: The direction to sort in.
 */
void merge(int *array, size_t size, size_t low, size_t n,
		char direction)
{
	size_t i, distance = n / 2, temp;

	if (n > 1)
	{
		for (i = low; i < low + distance; i++)
		{
			if ((direction == UP && array[i] > array[i + distance]) ||
			    (direction == DOWN && array[i] < array[i + distance]))
			{
				temp = array[i];
				array[i] = array[i + distance];
				array[i + distance] = temp;
			}
		}
		merge(array, size, low, distance, direction);
		merge(array, size, low + distance, distance, direction);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @array: array
 * @size: The size of the array.
 * @low: The starting index of a block of the building bitonic sequence.
 * @n: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block in.
 */
void bitonicsort(int *array, size_t size, size_t low, size_t n, char direction)
{
	size_t distance = n / 2;
	char *str = (direction == DOWN) ? "DOWN" : "UP";

	if (n > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", n, size, str);
		print_array(array + low, n);

		bitonicsort(array, size, low, distance, UP);
		bitonicsort(array, size, low + distance, distance, DOWN);
		merge(array, size, low, n, direction);

		printf("Result [%lu/%lu] (%s):\n", n, size, str);
		print_array(array + low, n);
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonicsort(array, size, 0, size, UP);
}
