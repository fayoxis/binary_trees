#include "binary_trees.h"
#include "17-binary_tree_sibling.c"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, otherwise NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
if (!node || !node->parent)
{
return (NULL);
}

return (binary_tree_sibling(node->parent));
}
