#include "binary_trees.h"
/**
 * binary_tree_delete - deletes a binary tree
 * @tree: pointer to root
 * Return: no return
**/
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
	{
		free(tree);
		return;
	}
	else
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
	}
}
