#include "search_algos.h"

/**
 * linear_skip - Traversing a LL in O(sqrt(n))
 *
 * @list: Pointer to the first node.
 * @value: The value of the node to look for.
 *
 * Return: Pointer to the node or NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr, *nxt;

	if (list == NULL)
		return (NULL);

	curr = nxt = list;

	while (nxt->next != NULL && nxt->n < value)
	{
		curr = nxt;
		if (nxt->express != NULL)
		{
			nxt = nxt->express;
			printf("Value checked at index [%ld] = [%d]\n",
					nxt->index, nxt->n);
		}
		else
		{
			while (nxt->next != NULL)
				nxt = nxt->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			curr->index, nxt->index);

	while (curr->index < nxt->index && curr->n < value)
	{
		curr = curr->next;
		printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);
	}

	printf("Value checked at index [%ld] = [%d]\n", curr->index, curr->n);

	if (curr->n == value)
		return (curr);
	else
		return (NULL);
}
