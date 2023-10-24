#include"sort."
/**
 * bubble_sort - sorts with bubble algorithm
 * @array: array if integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x = 0;
	int temp, count = 1;

	if (array == NULL || size < 2)
		return;
	while (count != 0)
	{
		count = 0;
		for (x = 0; x < size - 1; x++)
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				count++;
				print_array(array, size);
			}
	}
}
