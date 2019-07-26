#include "binary_trees.h"
/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @func: pointer to function that prints the values (from  Holberton)
 * @tree: pointer to the root
 * Return: no return
 **/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
	}
	if (tree->right)
		binary_tree_inorder(tree->right, func);
	if (!tree->left && !tree->right)
	{
		func(tree->n);
	}
}
