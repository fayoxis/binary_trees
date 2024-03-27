#include "binary_trees.h"

/**
 * insert_node_value - node value instertion in a AVL.
 * @tree: pointer of root node of the AVL tree struct.
 * @parent: parent node of struct AVL.
 * @new: pointer left or right insertion.
 * @insert_val: insertion value of the AVL.
 * Return: pointer to the new root after insertion otherwise NULL
 */

avl_t *insert_node_value(avl_t **tree, avl_t *parent,
avl_t **new, int insert_val)
{
	int new_val;

	if (!*tree)
		return (*new = binary_tree_node(parent, insert_val));
	if ((*tree)->n > insert_val)
	{
		(*tree)->left = insert_node_value(&(*tree)->left, *tree, new, insert_val);
		if (!(*tree)->left)
			return (NULL);
	}
	else if ((*tree)->n < insert_val)
	{
		(*tree)->right = insert_node_value(&(*tree)->right, *tree, new, insert_val);
		if (!(*tree)->right)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	new_val = binary_tree_balance(*tree);
	if (new_val > 1 && (*tree)->left->n > insert_val)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (new_val > 1 && (*tree)->left->n < insert_val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (new_val < -1 && (*tree)->right->n < insert_val)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (new_val < -1 && (*tree)->right->n > insert_val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_node_value(tree, *tree, &new, value);
	return (new);
}
