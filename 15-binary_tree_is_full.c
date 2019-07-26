#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full(both branchs are busy)
 * @tree: pointer to the node
 * Return: 1 if it is full 0 otherwise
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int tmp1, tmp2;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if ((!tree->left && tree->right) || (!tree->right && tree->left))
		return (0);
	tmp1 = binary_tree_is_full(tree->left);
	tmp2 = binary_tree_is_full(tree->right);
	return (tmp1 && tmp2);
}
