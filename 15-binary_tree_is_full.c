#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL, return 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
int full_right, full_left;

if (!tree)
{
return (0);
}

if (!tree->left && !tree->right)
{
return (1);
}

if (!tree->left && tree->right)
{
return (0);
}

if (tree->left && !tree->right)
{
return (0);
}

full_left = binary_tree_is_full(tree->left);
full_right = binary_tree_is_full(tree->right);

if (full_right == 1 && full_left == 1)
{
return (1);
}

return (0);
}
