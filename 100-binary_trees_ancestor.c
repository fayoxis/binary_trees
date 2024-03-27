#include "binary_trees.h"
#include "10-binary_tree_depth.c"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
int uni;

if (first && second)
{
uni = binary_tree_depth(first) - binary_tree_depth(second);
if (uni < 0)
{
uni *= -1;
while (uni--)
second = second->parent;
}
else
{
while (uni--)
first = first->parent;
}
while (first)
{
if (first == second)
return ((binary_tree_t *) first);
first = first->parent;
second = second->parent;
}
}
return (NULL);
}
