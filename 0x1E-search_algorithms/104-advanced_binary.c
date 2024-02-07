#include "search_algos.h"

/**
 * advanced_binary_search - Advanced binary search algorithm.
 *
 * @array: Pointer to the first element in the array.
 * @l: Left boundary.
 * @r: Right boundary.
 * @value: Value to look for.
 *
 * Return: Index of the item or -1.
 */
int advanced_binary_search(int *array, size_t l, size_t r, int value)
{
	size_t mid, i;

	if (r < l)
		return (-1);

	printf("Searching in array: ");
	for (i = l; i <= r; i++)
		printf("%d%s", *(array + i), (i == r) ? "\n" : ", ");

	mid = l + (r - l) / 2;

	if (*(array + mid) == value && (i == l || *(array + mid - 1) != value))
		return (mid);

	if (*(array + mid) >= value)
		return (advanced_binary_search(array, l, mid, value));

	return (advanced_binary_search(array, mid + 1, r, value));
}

/**
 * advanced_binary - Advanced binary search to find the first
 *			occurence of an item in an array.
 * @array: Pointer to the first item.
 * @size: Size of the array.
 * @value: The value to look for.
 *
 * Return: Index of the item or -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t l, r;

	l = 0, r = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_search(array, l, r, value));
}
