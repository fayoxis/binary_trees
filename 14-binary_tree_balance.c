#include "binary_trees.h"

/**
* binary_tree_height_balance - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
*
* Return: Height of the tree, if tree is NULL, 0
*/

size_t binary_tree_height_balance(const binary_tree_t *tree)
{
int right, left;

if (!tree)
{
return (-1);
}

if (!tree->right && !tree->left)
{
return (0);
}

right = binary_tree_height_balance(tree->right) + 1;
left = binary_tree_height_balance(tree->left) + 1;

if (left > right)
{
return (left);
}
else
{
return (right);
}
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree, 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
int left, right;

if (!tree)
{
return (0);
}

left = binary_tree_height_balance(tree->left);
right = binary_tree_height_balance(tree->right);

return (left - right);
}
