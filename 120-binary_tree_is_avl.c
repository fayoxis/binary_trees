#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * aux_avl - Auxiliar function to compare each subtree if its AVL.
 * @tree: node that point to the tree to check.
 * @bottom: node that point to the higher node selected
 * @top: node that point to the lower node selected.
 * Return: 1 if tree is AVL, 0 if not.
 */
int aux_avl(const binary_tree_t *tree, int bottom, int top)
{
	size_t l_height, r_height, balanc;

	if (tree)
	{
		if (tree->n > top || tree->n < bottom)
		{
			return (0);
		}
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);
		balanc = l_height > r_height ? l_height - r_height : r_height - l_height;
		if (balanc > 1)
		{
			return (0);
		}
		return (aux_avl(tree->left, bottom, tree->n - 1) &&
			aux_avl(tree->right, tree->n + 1, top));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree:  pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (aux_avl(tree, INT_MIN, INT_MAX));
}
