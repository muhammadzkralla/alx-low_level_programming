#include "search_algos.h"

/**
 * do_jump - Jumps a certain step.
 *
 * @node: Beginning node.
 * @step: Desired step to jump.
 *
 * Return: The current node after jumping.
 */
listint_t *do_jump(listint_t *node, size_t step)
{
	size_t counter;

	counter = 0;

	while (node->next != NULL && counter < step)
	{
		node = node->next;
		counter++;
	}

	return (node);
}

/**
 * jump_list - Applies Jump Search to a singly LL.
 *
 * @list: Pointer to the first node.
 * @size: Size of the LL.
 * @value: Node to look for.
 *
 * Return: A pointer to the node or NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump;
	listint_t *start, *end;

	if (list == NULL || (int) size < 0)
		return (NULL);

	jump = sqrt(size);
	end = list;

	while (end->n <= value)
	{
		if (end->next != NULL)
		{
			start = end;
			end = do_jump(end, jump);
			printf("Value checked at index [%lu] = [%d]\n", end->index, end->n);
		}
		else
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n"
			, start->index, end->index);

	while (start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		if (start->n == value)
			return (start);

		if (start->next == NULL)
			break;

		start = start->next;
	}

	return (NULL);
}
