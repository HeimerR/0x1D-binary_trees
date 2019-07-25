#include "binary_trees.h"
/**
 * bst_search - checks if a binary tree is bts
 * @tree: pointer to the node
 * @value:number to search
 * Return: pointer to the founded node
 **/
bst_t *bst_search(const bst_t *tree, int value)
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
