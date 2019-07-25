#include "binary_trees.h"
/**
 * binary_tree_rotate_right - right rotation of tree
 * @tree: pointer to the root
 * Return:Pointer to new root
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree)
		return (NULL);

	node = tree;
	tree->parent = node;

	tree->left->parent = node;
	node = tree->left;
	tree->left = NULL;
	if (node->right)
	{
		tree->left = node->right;
		tree->left->parent = tree;
	}
	tree->parent = node;
	node->right = tree;
	tree = node;
	tree->parent = NULL;
	return (tree);
}
