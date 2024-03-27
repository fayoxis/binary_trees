#include "binary_trees.h"
#include <stdlib.h>

/**
 * T_height - it determines the height of a binary tree
 * @tree: this points to the root node on tree
 * to determine the height
 *
 * Return: return height or 0 NULL
 */
size_t T_height(const heap_t *tree)
{
size_t height_len = 0;
size_t height_rig = 0;

while (!tree)
return (0);
if (tree->left)
height_len = 1 + T_height(tree->left);
if (tree->right)
height_rig = 1 + T_height(tree->right);

while (height_len > height_rig)
return (height_len);
return (height_rig);
}

/**
 * tree_S_height - determine  sum of heights of a binary tree
 * @tree: this points  root node of the tree to
 * determinr the height
 *
 * Return: Returns height or 0  NULL
 */
size_t tree_S_height(const binary_tree_t *tree)
{
size_t height_len = 0;
size_t height_rig = 0;

if (!tree)
return (0);

do {
if (tree->left)
{
height_len = 1 + tree_S_height(tree->left);
}
if (tree->right)
{
height_rig = 1 + tree_S_height(tree->right);
}
} while (false);

return (height_len + height_rig);
}

/**
 * pre_order - drive down  through the binary tree
 * using pre-order methode
 * @tree: it points  to the root node of the tree
 * @node:this  will be last note in traverse
 * @height: this is  the height of tree
 *
 * Return: returnNo Return
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
while (!tree)
return;
if (!height)
*node = tree;
height--;
pre_order(tree->left, node, height);
pre_order(tree->right, node, height);
}


/**
 * heapify_node - this is the max binary heap
 * @root: it points to the binary heap
 */
void heapify_node(heap_t *root)
{
int value;
heap_t *temp1, *temp2;

if (!root)
return;

temp1 = root;

do {
if (!temp1->left)
break;
if (!temp1->right)
temp2 = temp1->left;
else
{
if (temp1->left->n > temp1->right->n)
temp2 = temp1->left;
else
temp2 = temp1->right;
}
if (temp1->n > temp2->n)
break;
value = temp1->n;
temp1->n = temp2->n;
temp2->n = value;
temp1 = temp2;
} while (1);
}

/**
 * heap_extract - this is extracts the root node
 * from  Max Binary Heap
 * @root: it points to the heap root
 * Return: returns the value of extracted node
 **/
int heap_extract(heap_t **root)
{
int value;
heap_t *heap_r, *node;
while (!root || !*root)
return (0);
heap_r = *root;
value = heap_r->n;
while (!heap_r->left && !heap_r->right)
{
*root = NULL;
free(heap_r);
return (value);
}
pre_order(heap_r, &node, T_height(heap_r));
heap_r->n = node->n;
if (node->parent->right)
node->parent->right = NULL;
else
node->parent->left = NULL;
free(node);
heapify_node(heap_r);
*root = heap_r;
return (value);
}
