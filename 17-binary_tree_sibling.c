#include "binary_trees.h"
/**
 * binary_tree_sibling - checks if a binary tree is perfect
 * @node: pointer to the node
 * Return: pointer to sibling
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (0);
	if (node->n == node->parent->left->n)
		return (node->parent->right);
	else
		return (node->parent->left);
}
