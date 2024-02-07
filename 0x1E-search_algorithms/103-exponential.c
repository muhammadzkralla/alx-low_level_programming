#include "search_algos.h"

/**
 * ranged_binary_search - Helper binary search algorithm.
 *
 * @arr: Pointer to the first element.
 * @l: The left boundary.
 * @r: The right boundary.
 * @value: The value to search for.
 *
 * Return: Index of the item or -1.
 */
int ranged_binary_search(int *arr, size_t l, size_t r, int value)
{
	size_t mid, i;

	while (l <= r && arr != NULL)
	{
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
			printf("%d%s", arr[i], (i == r) ? "\n" : ", ");

		mid = l + (r - l) / 2;
		if (arr[mid] == value)
			return (mid);

		if (arr[mid] > value)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return (-1);
}

/**
 * exponential_search - Performs the exponetial search algorithm.
 *
 * @array: Pointer to the first element in the array.
 * @size: Size of the array.
 * @value: Value to look for.
 *
 * Return: Index of the item or -1.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t step, end;

	step = 1;

	if (array == NULL)
		return (-1);

	if (*(array) == value)
	{
		step = 0;
	}
	else
	{
		while (*(array + step) <= value && step < size)
		{
			printf("Value checked array[%ld] = [%d]\n", step, *(array + step));
			step *= 2;
		}
	}

	if (step < size)
		end = step;
	else
		end = size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", step / 2, end);
	return (ranged_binary_search(array, step / 2, end, value));
}
