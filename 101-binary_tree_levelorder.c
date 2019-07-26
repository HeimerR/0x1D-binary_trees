#include "binary_trees.h"
/**
 * preorder - goes through a binary tree using pre-order traversal
 * @func: pointer to function that prints the values
 * @tree: pointer to the root
 * @level: level to print
 * @ref: reference to start
 * Return: no return
 **/
void preorder(const binary_tree_t *tree, void (*func)(int), int level, int ref)
{
	if (!tree || !func)
		return;
	if (level == ref)
		func(tree->n);
	if (tree->left)
		preorder(tree->left, func, level, ref + 1);
	if (tree->right)
		preorder(tree->right, func, level, ref + 1);
}
/**
 * height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height of the tree
 **/
int height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = height(tree->right) + 1;
	left = height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}
/**
 * binary_tree_levelorder - finds the lowest common ancestor of two nodes
 * @tree: pointer to the root of the to find LCA
 * @func: funtion to print
 * Return: pointer to common ancestor
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h, i;

	if (!tree || !func)
		return;
	h = height(tree);
	for (i = 0; i <= h; i++)
	{
		preorder(tree, func, i, 0);
	}
}
