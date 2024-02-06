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
int continue_search(int *array, size_t size, int value, int currIdx, int jump)
{
	int counter;

	printf("Value found between indexes [%d] and [%d]\n"
			, currIdx - jump, currIdx);
	currIdx -= jump;
	counter = 0;
	while (counter <= jump && currIdx + counter < (int) size)
	{
		printf("Value checked array[%d] = [%d]\n"
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
	int jump, currIdx, counter;

	jump = sqrt(size);
	counter = 0;
	currIdx = 0;

	if (array == NULL || size <= 0)
		return (-1);

	while (currIdx < (int) size)
	{
		if (*(array + currIdx) >= value)
		{
			printf("Value found between indexes [%d] and [%d]\n"
					, currIdx - jump, currIdx);
			currIdx -= jump;
			while (counter <= jump)
			{
				printf("Value checked array[%d] = [%d]\n"
						, currIdx + counter, *(array + currIdx + counter));
				if (*(array + currIdx + counter) == value)
					return (currIdx + counter);

				counter++;
			}

			return (-1);
		}
		printf("Value checked array[%d] = [%d]\n"
				, currIdx, *(array + currIdx));

		currIdx += jump;
	}

	return (continue_search(array, size, value, currIdx, jump));
}
