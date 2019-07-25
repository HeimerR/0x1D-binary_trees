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

	node = binary_tree_node(NULL, 98);
	node->left = tree;
	tree->parent = node;
	tree->right->parent = node;
	node->left = tree->right;

	if (tree->right->left)
		tree->right = tree->right->left;
	tree->parent = node->right;
	node->left->left = tree;
	tree->right->parent = tree;
	tree = node->left;
	tree->parent = NULL;
	return (tree);
}
