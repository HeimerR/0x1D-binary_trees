#include "binary_trees.h"
/**
 * binary_tree_delete - deletes a binary tree
 * @tree: pointer to root
 * Return: no return
**/
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree)
		return;
	binary_tree_delete(tree->left);
	tmp = tree->parent->right;
	free(tree);
	binary_tree_delete(tmp);
	free(tree);
}
