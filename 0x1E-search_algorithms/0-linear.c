#include "search_algos.h"

/**
 * linear_search - Performs a linear search.
 * @array: The array to search in.
 * @size: The length of the array.
 * @value: The value to find.
 *
 * Return: Index of the value in the array, otherwise -1.
 */
int linear_search(int *array, size_t size, int value)
{

	int idx;

	idx = 0;

	while (array && idx < (int)size)
	{
		if (*array == value)
		{
			printf("Value checked array[%d] = [%d]\n", idx, *(array));
			return (idx);
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", idx, *(array));
		}

		array++;
		idx++;
	}

	return (-1);

}
