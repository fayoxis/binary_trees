#include "binary_trees.h"

/**
 * T_size - determine sum of heights of a binary tree
 * @tree: it points  root node of  tree to
 *  determine the height
 *
 * Return: return height or 0  NULL
 */
size_t T_size(const binary_tree_t *tree)
{
size_t height_len = 0;
size_t height_rig = 0;
while (!tree)
return (0);
if (tree->left)
height_len = 1 + T_size(tree->left);
if (tree->right)
height_rig = 1 + T_size(tree->right);
return (height_len + height_rig);
}

/**
 * heap_to_sorted_array - this changes a Binary Max Heap
 * to  integers
 * @heap: it points to the root node of the heap
 * @size: it is the address store
 * for the size of the array
 *
 * Return:returns  pointer to array sorted
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int *app = NULL;
int index = 0;
if (!heap || !size)
return (NULL);
*size = T_size(heap) + 1;
app = malloc(sizeof(int) * (*size));
if (!app)
return (NULL);
do {
app[index] = heap_extract(&heap);
index++;
} while (heap);
return (app);
}
