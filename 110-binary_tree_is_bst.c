#include "binary_trees.h"

/**
 * small_node - check if all nodes are smaller than
 * the root specified
 * @node: node in the tree
 * @max: maximum value to compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */

int small_node(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (!node)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = small_node(node->left, max);
		right = small_node(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * big_node - check if all the nodes are bigger than the
 * root specified
 * @node: node in the tree
 * @min: minimum value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int big_node(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (!node)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = big_node(node->left, min);
		right = big_node(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int center = 0, left = 2, right = 2;

	if (!tree)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		center = small_node(tree->left, tree->n);
		if (center == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		center = big_node(tree->right, tree->n);
		if (center == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
