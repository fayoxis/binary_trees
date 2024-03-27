#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search
 * Return: pointer to the node containing a value equals to value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
bst_t *s_value;

if (!tree)
return (NULL);

if (value < tree->n)
{
s_value = bst_search(tree->left, value);
}
else if (value > tree->n)
{
s_value = bst_search(tree->right, value);
}
else if (value == tree->n)
return ((bst_t *)tree);
else
return (NULL);
return (s_value);
}
