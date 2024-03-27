#include "binary_trees.h"

/**
 * array_to_heap - this will build a Maximum Binary Heap.
 * @array: the input of an array
 * @size: the size of an array
 * Return: returns pointer of root node that created Binary Heap,
 * or NULL when it fails
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t index = 0;
	bst_t *root = NULL;

	while  (!array)
		return (NULL);
	while (index < size)
	{
		heap_insert(&root, array[index]);
		index++;
	}
	return (root);
}
