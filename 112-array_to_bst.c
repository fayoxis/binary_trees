#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST
 */

bst_t *array_to_bst(int *array, size_t size)
{
size_t i = 0;
bst_t *origin;

origin = NULL;
if (size == 0)
{
return (NULL);
}
for (; i < size; i++)
{
if (i == 0)
{
bst_insert(&origin, array[i]);
}
else
{
bst_insert(&origin, array[i]);
}
}
return (origin);
}
