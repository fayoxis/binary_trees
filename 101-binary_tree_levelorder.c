#include "binary_trees.h"
#include "10-binary_tree_depth.c"
#include "9-binary_tree_height.c"

/**
 * link_node - makes a linked list from depth level
 * @head: pointer to head of linked list
 * @tree: node to store
 * @level: depth of node to store
 * Return: void
 */
void link_node(link_tree_t **head, const binary_tree_t *tree, size_t level)
{
	link_tree_t *new, *aux;

	new = malloc(sizeof(link_tree_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new->next = NULL;
		aux->next = new;
	}
}
/**
 * recursion - goes through the complete tree recursively
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: void
 */
void recursion(link_tree_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		link_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print the nodes element in a lever-order
 * @tree: root node
 * @func: function to use
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_tree_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
