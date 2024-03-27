#include "binary_trees.h"
#include "114-bst_remove.c"

/**
 * bal_factor - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: factor that is balanced
 */
void bal_factor(avl_t **tree)
{
	int balanced_val;

	if (!tree || !*tree)
		return;
	if (!(*tree)->left && !(*tree)->right)
		return;
	bal_factor(&(*tree)->left);
	bal_factor(&(*tree)->right);
	balanced_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (balanced_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balanced_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * avl_remove -  removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return:  pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *a_root = (avl_t *) bst_remove((bst_t *) root, value);

	if (!a_root)
		return (NULL);
	bal_factor(&a_root);
	return (a_root);
}
