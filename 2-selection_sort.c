#include"sort.h"
/**
 * selection_sort - sorts by selection
 * @array: array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
    size_t x, y, smallest, tmp;

    if (array == NULL || size < 2)
        return;
    for (x = 0; x < size; x++)
    {
        smallest = x;
        for (y = x + 1; y < size; y++)
        {
            if (array[smallest] > array[y])
                smallest = y;
        }
        tmp = array[x];
        array[x] = array[smallest];
        array[smallest] = tmp;
        print_array(array, size);
    }
}