#include "binary_trees.h"
/**
 * height - mesures height
 * @tree: pointer to the node
 * Return: height
 **/
int height(binary_tree_t *tree)
{
	size_t left, right;

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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the node
 * Return: 1 if it is perfect 0 otherwise
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((!tree->left && !tree->right) || ((binary_tree_is_perfect(tree->left)
	    == 1 && binary_tree_is_perfect(tree->right) == 1) && height(tree->left)
	    == height(tree->right)))
		return (1);
	return (0);
}
