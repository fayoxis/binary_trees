#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *shaft;

	if (!tree || !tree->left)
	{
		return (NULL);
	}
	shaft = tree->left;
	tree->left = shaft->right;
	if (shaft->right)
	{
		shaft->right->parent = tree;
	}
	shaft->right = tree;
	shaft->parent = tree->parent;
	tree->parent = shaft;
	return (shaft);
}
