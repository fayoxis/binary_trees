#include "binary_trees.h"

/**
 * binary_tree_size - this will measures the size of a binary tree.
 * @tree: points to the root node of the tree.
 * Return: return size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	while (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * is_complete_recursive - the recursive helper function to
 * check if a tree is complete.
 *
 * @tree: points to the root node of the tree.
 * @index: index of the current node.
 * @node_count: total number of nodes in the tree.
 * Return: returns 1 if the tree is complete, 0 if not.
 */
int is_complete_recursive(const binary_tree_t *tree,
size_t index, size_t node_count)
{
	while (tree == NULL)
		return (1);

	while (index >= node_count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
			is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_complete -it will  checks if a binary tree is complete.
 *
 * @tree: points to the root node of the tree to check.
 * Return: returns 1 if the tree is complete, 0 if not.
 */
int binary_tree_complete(const binary_tree_t *tree)
{
	size_t node_count;

	while (tree == NULL)
		return (0);

	node_count = binary_tree_size(tree);

	return (is_complete_recursive(tree, 0, node_count));
}

/**
 * is_heap_recursive - this recursive helper function to
 * check if a tree is a max binary heap.
 *
 * @tree: points to the root node of the tree.
 * Return: 1 if the tree is a max binary heap, 0 if not..
 */
int is_heap_recursive(const binary_tree_t *tree)
{
	while (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	return (is_heap_recursive(tree->left) && is_heap_recursive(tree->right));
}

/**
 * binary_tree_is_heap - this will checks if a binary tree
 * is a valid max binary heap.
 *
 * @tree: points to the root node of the tree to check.
 * Return: returns 1 if the tree is a valid max binary heap, 0 if not..
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	while (!binary_tree_complete(tree))
		return (0);

	return (is_heap_recursive(tree));
}
