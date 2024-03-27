#include "binary_trees.h"

/**
 * new_node - Creates a new_node in a linked_list
 * @node: Type pointer of node to be created
 * Return: the node created
 */

link_tree_t *new_node(binary_tree_t *node)
{
link_tree_t *new;

new =  malloc(sizeof(link_tree_t));
if (!new)
{
return (NULL);
}
new->node = node;
new->next = NULL;

return (new);
}

/**
 * free_node - Free the nodes at the linked list
 * @head: Node of the linked_list
 */

void free_node(link_tree_t *head)
{
link_tree_t *temp;

while (head)
{
temp = head->next;
free(head);
head = temp;
}
}

/**
 * node_push - Pushes a node into the stack
 * @node: Type pointer of node of the tree
 * @head: Type head node of in the stack
 * @tail: Type tail node of in the stack
 * Return: void
 */

void node_push(binary_tree_t *node, link_tree_t *head, link_tree_t **tail)
{
link_tree_t *new;

new = new_node(node);
if (new == NULL)
{
free_node(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
}

/**
 * node_pop - Pops a node into the stack
 * @head: Type head node of in the stack
 * Return: void
 */

void node_pop(link_tree_t **head)
{
link_tree_t *temp;

temp = (*head)->next;
free(*head);
*head = temp;
}

/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Type pointer of node of the tree
 * Return: 1 if is complete 0 if it is not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
link_tree_t *head, *tail;
int flg = 0;

if (!tree)
{
return (0);
}
head = tail = new_node((binary_tree_t *)tree);
if (!head)
{
exit(1);
}
while (head)
{
if (head->node->left != NULL)
{
if (flg == 1)
{
free_node(head);
return (0);
}
node_push(head->node->left, head, &tail);
}
else
flg = 1;
if (head->node->right != NULL)
{
if (flg == 1)
{
free_node(head);
return (0);
}
node_push(head->node->right, head, &tail);
}
else
flg = 1;
node_pop(&head);
}
return (1);
}
