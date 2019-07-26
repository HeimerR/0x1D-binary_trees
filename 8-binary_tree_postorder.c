#include "binary_trees.h"
/**
 * binary_tree_postorder - goes through a binary tree using in-order traversal
 * @func: pointer to function that prints the values (from Holberton)
 * @tree: pointer to the root
 * Return: no return
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left)
	{
		binary_tree_postorder(tree->left, func);
	}
	if (tree->right)
	{
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
	if (!tree->left && !tree->right)
	{
		func(tree->n);
	}
}
