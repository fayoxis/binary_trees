#include "binary_trees.h"
/**
 * min_node - get the next min node in the right subtree
 * @node: tree to check
 * Return: the minimum value of this tree
 */
int min_node(bst_t *node)
{
	int left = 0;

	if (!node)
	{
		return (0);
	}
	else
	{
		left = min_node(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * min_node_next - gets the next successor using the min value
 * @root: node that has the next min node
 * Return: next min node
 */
int min_node_next(bst_t *root)
{
	int s_value = 0;

	s_value = min_node(root->right);
	root->n = s_value;
	return (s_value);
}
/**
 *remove_node - removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_node(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (min_node_next(root));
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
