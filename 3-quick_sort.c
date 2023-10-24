#include "sort.h"
/**
 * partition - sorts with quick sort.
 * @array: array
 * @start: starting point
 * @end: ending point
 * @size: size of array
 */
void partition(int *array, int start, int end, int size)
{
	int current_idx = start, swap_marker = start - 1, pivot = end, tmp;

	if (start == end)
		return;
	while (current_idx <= pivot)
	{
		if (array[current_idx] > array[pivot])
			current_idx += 1;
		else
		{
			swap_marker += 1;
			if (current_idx > swap_marker)
			{
				tmp = array[current_idx];
				array[current_idx] = array[swap_marker];
				array[swap_marker] = tmp;
				print_array(array, size);
				if (current_idx == pivot)
				{
					partition(array, 0, swap_marker - 1, size);
					partition(array, swap_marker + 1, end, size);
					return;
				}
			}
			else if (current_idx == swap_marker)
			{
				if (current_idx == pivot)
					partition(array, start, end - 1, size);
				current_idx += 1;
			}
		}
	}
}

/**
 * quick_sort - sorts an array with quick sort algorithm
 * @array: array of unsorted integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	partition(array, 0, size - 1, size);
}
