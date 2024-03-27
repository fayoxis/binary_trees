#include "binary_trees.h"
#include "14-binary_tree_balance.c"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: if tree is Null, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
int perfect = 0;

if (tree)
{
perfect = 1;
if (binary_tree_balance(tree) != 0)
{
return (0);
}
if (tree->left)
{
perfect *= binary_tree_is_perfect(tree->left);
}
if (tree->right)
{
perfect *= binary_tree_is_perfect(tree->right);
}
}
return (perfect);
}
