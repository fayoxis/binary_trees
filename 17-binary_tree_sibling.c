#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: if node or parent is NUL, return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (!node || !node->parent ||
!node->parent->left || !node->parent->right)
{
return (NULL);
}

if (node->parent->left->n == node->n)
{
return (node->parent->right);
}
else if (node->parent->right->n == node->n)
{
return (node->parent->left);
}

return (NULL);
}
