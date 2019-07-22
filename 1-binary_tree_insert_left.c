#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node in the binary tree (left)
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node
**/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *tmp;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	tmp = parent->left;
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	parent->left = node;
	if (tmp != NULL)
		node->left = tmp;
	return (node);
}
