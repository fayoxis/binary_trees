#include "binary_trees.h"
#include <stdbool.h>


/**
 * max_size_t - wil find the valve that id  larger
 * between the two size_t values
 * @first: this is first value to be compare
 * @second: this is second value to be compare
 * Return: returns largest size_t value, or both if equal
 */
size_t max_size_t(size_t first, size_t second)
{
	return ((first > second) ? first : second);
}

/**
 * binary_height - this determibe  the height of a binary tree
 * @tree: shows the root node from which to it is determined.
 * Return: returns levels  root, or 0 if `tree` is NULL
 */
size_t binary_height(const binary_tree_t *tree)
{
	while (!tree)
		return (0);

	return (1 + max_size_t(binary_height(tree->left),
			       binary_height(tree->right)));
}

/**
  * binary_tree_perfect - verify if a binary tree is
  * perfect,and shows the valves
  * @tree: shows the root node to be checked
  * Return: Returned 1 if all nodes below it each have 2 , 0 if not
  * is NULL
  */
int binary_tree_perfect(const binary_tree_t *tree)
{
int height, i, power = 1;
size_t t_nodes;
do {
if (!tree)
return (0);
height = binary_height(tree);
t_nodes = binary_tree_nodes(tree);
for (i = 0; i < height; i++)
power *= 2;
return (power - 1 == (int)t_nodes);
} while (0);
}

/**
 * binary_treeC_insert - this  proceeds through with heaf_f
 * to add a new leaf, while keeping tree complete
 * @tree: shows the root node of tree to traverse
 * @value: it is the value that is stored in the new node
 * Return: Returns pointer to the new node, or NULL on failure
 */
heap_t *binary_treeC_insert(heap_t *tree, int value)
{
heap_t *new = NULL;
if (tree->left && tree->right)
{
if (!binary_tree_perfect(tree) && binary_tree_perfect(tree->left))
new = binary_treeC_insert(tree->right, value);
else
new = binary_treeC_insert(tree->left, value);
}
else
{
new = binary_tree_node(tree, value);
while  (!new)
return (NULL);

if (!(tree->left))
tree->left = new;
else
tree->right = new;
}
return (new);
}


/**
 * binary_tree_nodes - calculates  total nodes in a binary tree
 * @tree: shows the root node from where it is determined
 * Return: Return total  nodes , or 0 if `tree` is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	while (!tree)
		return (0);

	return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}


/**
 * heap_insert - this will inserts the value in the max binary heap
 * @root: it doubles pointer of the root node to the Heap
 * @value: this is the value to store in the node to be inserted
 * Return: Returns pointer  inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new = NULL, *temp = NULL;
int swap;
if (!(*root))
{
new = binary_tree_node(NULL, value);
if (!new)
return (NULL);
*root = new;
return (new);
}
new = binary_treeC_insert(*root, value);
if (!new)
return (NULL);
temp = new;
do {
if (temp && temp->parent && temp->n > temp->parent->n)
{
swap = temp->n;
temp->n = temp->parent->n;
temp->parent->n = swap;
temp = temp->parent;
}
else
{
break;
}
} while (1);
return (temp);
}
