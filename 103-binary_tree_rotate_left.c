#include "binary_trees.h"
/**
 * binary_tree_rotate_left - left rotation of tree
 * @tree: pointer to the root
 * Return:Pointer to new root
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree)
		return (NULL);

	node = tree;
	tree->parent = node;

	tree->right->parent = node;
	node = tree->right;
	tree->right = NULL;
	if (node->left)
	{
		tree->right = node->left;
		tree->right->parent = tree;
	}
	tree->parent = node;
	node->left = tree;
	tree = node;
	tree->parent = NULL;
	return (tree);
}
