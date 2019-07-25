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

	node = binary_tree_node(NULL, 98);
	node->right = tree;
	tree->parent = node;

	tree->left->parent = node;
	node->right = tree->left;
	tree->left = NULL;
	if (node->right->right)
	{
		tree->left = node->right->right;
		tree->left->parent = tree;
	}
	tree->parent = node->right;
	node->right->right = tree;
	tree = node->right;
	tree->parent = NULL;
	free (node);
	return (tree);
}
