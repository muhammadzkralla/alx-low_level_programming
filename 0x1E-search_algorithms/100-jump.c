#include "search_algos.h"
#include <math.h>

/**
 * continue_search - Completes the search.
 *
 * @array: Pointer to the first item in the array.
 * @size: Size of the array.
 * @value: Value to search for.
 *
 * Return: first index where value is located, or -1 on failure
 */
int continue_search(int *array, size_t size, int value, size_t currIdx, size_t jump)
{
	size_t counter;

	printf("Value found between indexes [%lu] and [%lu]\n"
			, currIdx - jump, currIdx);
	currIdx -= jump;
	counter = 0;
	while (counter <= jump && currIdx + counter < size)
	{
		printf("Value checked array[%ld] = [%d]\n"
				, currIdx + counter, *(array + currIdx + counter));
		if (*(array + currIdx + counter) == value)
			return (currIdx + counter);

		counter++;
	}

	return (-1);
}

/**
 * jump_search - Applies the Jump Search Algorithm.
 *
 * @array: Pointer to the first item in the array.
 * @size: Size of the array.
 * @value: Value to search for.
 *
 * Return: first index where value is located, or -1 on failure
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump, currIdx, counter;

	jump = sqrt(size);
	counter = 0;
	currIdx = 0;

	while (currIdx < size)
	{
		if (*(array + currIdx) >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n"
					, currIdx - jump, currIdx);
			currIdx -= jump;
			while (counter <= jump)
			{
				printf("Value checked array[%lu] = [%d]\n"
						, currIdx + counter, *(array + currIdx + counter));
				if (*(array + currIdx + counter) == value)
					return (currIdx + counter);

				counter++;
			}

			return (-1);
		}
		printf("Value checked array[%lu] = [%d]\n"
				, currIdx, *(array + currIdx));

		currIdx += jump;
	}

	return (continue_search(array, size, value, currIdx, jump));
}
