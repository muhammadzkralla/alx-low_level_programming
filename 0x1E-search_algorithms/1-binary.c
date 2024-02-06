#include "search_algos.h"

/**
 * print - Prints the current range of the array.
 *
 * @ptr: Pointer to the first item in the array.
 * @l: The left index of the range.
 * @r: The right index of the range.
 */
void print(int *ptr, int l, int r)
{
	printf("Searching in array: ");
	while (l <= r)
	{
		printf("%d%s", *(ptr + l), (l == r) ? "\n" : ", ");
		l++;
	}
}

/**
 * do_binary_search - The actual algorithm.
 *
 * @array: The array to search in.
 * @size: The size of the array.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int do_binary_search(int *array, size_t size, int value)
{
	int l, r, mid;

	l = 0, r = (int) size - 1;

	while (l <= r)
	{
		print(array, l, r);
		mid = l + ((r - l) / 2);
		if (*(array + mid) == value)
		{
			return (mid);
		}

		if (*(array + mid) < value)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}

	}

	return (-1);
}

/**
 * binary_search - The calling function.
 *
 * @array: The array to search in.
 * @size: The size of the array.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int binary_search(int *array, size_t size, int value)
{
	return (do_binary_search(array, size, value));

}
