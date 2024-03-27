#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: size of array
 * Return: pointer to the root node of the created AVL tree
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j = 0;
	avl_t *origin;

	origin = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&origin, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (origin);
}
