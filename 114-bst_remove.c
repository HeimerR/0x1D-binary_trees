#include "binary_trees.h"
/**
 * bst_remove - checks if a binary tree is bts
 * @root: pointer to the root
 * @value:number to delete
 * Return: pointer to the root node
 **/
bst_t *bst_remove(bst_t *root, int value)
{
	if (!tree)
		return (NULL);
	while (tree->left || tree->right)
	{
		if (tree && (tree->n > value))
		{
			if (tree->left)
				tree = tree->left;
			else
				break;
		}
		else if (tree && (tree->n < value))
		{
			if (tree->right)
				tree = tree->right;
			else
				break;
		}
		else if (tree && (tree->n == value))
			return ((bst_t *)tree);
	}
	if (tree && (tree->n == value))
		return ((bst_t *)tree);
	return (NULL);
}
