#include "binary_trees.h"

/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
*
* Return: Height of the tree, if tree is NULL, 0
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right, left;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (0);

	right = binary_tree_height(tree->right) + 1;
	left = binary_tree_height(tree->left) + 1;

	if (left > right)
		return (left);
	return (right);
}
