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
	node->right = tree;
	tree->parent = node;

	tree->right->parent = node;
	node->right = tree->right;
	tree->right = NULL;
	if (node->right->left)
	{
		tree->right = node->right->left;
		tree->right->parent = tree;
	}
	tree->parent = node->right;
	node->right->left = tree;
	tree = node->right;
	tree->parent = NULL;
	free(node);
	return (tree);
}
