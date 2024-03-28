#include "binary_trees.h"


/**
 * sortedArray_to_avl - Creates an AVL tree from a sorted array
 * @array: The sorted input of the array
 * @start: The starting index of the array
 * @end: The ending index of the array
 * @parent: A pointer to the parent node
 * Return: The newly created AVL tree node
 */
avl_t *sortedArray_to_avl(int *array, int start, int end, avl_t *parent)
{
if (start > end)
return (NULL);

while (start <= end)
{
int mid = (start + end) / 2;
avl_t *new = calloc(1, sizeof(avl_t));
if (!new)
return (NULL);

new->n = array[mid];
new->parent = parent;
if (mid > start)
new->left = sortedArray_to_avl(array, start, mid - 1, new);

if (mid < end)
new->right = sortedArray_to_avl(array, mid + 1, end, new);

return (new);
}

return (NULL);
}

/**
 * sorted_array_to_avl - creates an AVL tree from an array
 * @array: The sorted input array
 * @size: the size of array
 * Return: returns pointer of root node that created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

if (!array)
return (NULL);
return (sortedArray_to_avl(array, 0, size - 1, NULL));
}
