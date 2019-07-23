#include "binary_trees.h"
int height(binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	else
	{
		left = height(tree->left) + 1;
		right = height(tree->right) + 1;
		if (left > right)
			return (left);
		else
			return (right);
	}
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the node
 * Return: balance factor
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int hleft, hright;	

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	else
	{
		hleft = height(tree->left);
		hright = height(tree->right);
	}
	return (hleft - hright); 

}
