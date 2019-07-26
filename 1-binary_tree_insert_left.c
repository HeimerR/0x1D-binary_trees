#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node in the binary tree (left)
 * @parent: pointer to a parent node
 * @value: number value in the node inserted
 * Return: pointer to the new node
**/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->left;
	node = binary_tree_node(parent, value);
	parent->left = node;
	if (tmp != NULL)
	{
		node->left = tmp;
		tmp->parent = node;
	}
	return (node);
}
