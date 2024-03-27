#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *shaft;

	if (!tree || !tree->right)
	{
		return (NULL);
	}
	shaft = tree->right;
	tree->right = shaft->left;
	if (shaft->left)
	{
		shaft->left->parent = tree;
	}
	shaft->left = tree;
	shaft->parent = tree->parent;
	tree->parent = shaft;
	return (shaft);
}
