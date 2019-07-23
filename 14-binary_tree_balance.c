#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the node
 * Return: balance factor
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left)
		return (binary_tree_balance(tree->left) + 1);
	if (tree->right)
		return (binary_tree_balance(tree->right) - 1);
	return (0);
}
