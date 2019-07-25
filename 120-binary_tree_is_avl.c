#include "binary_trees.h"
#include "110-binary_tree_is_bst.c"
#include "9-binary_tree_height.c"
/**
 * binary_tree_is_avl - Determine if tree is AVL
 * @tree: pointer to the root
 * Return: 1 if tree is AVL / 0 otherwise
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int a, b, c, d, e;
	avl_t *root;

	root = (avl_t *)tree;
	if (!root)
		return (0);
	a = binary_tree_is_bst(root);
	b = binary_tree_is_bst(root->left);
	c = binary_tree_is_bst(root->right);
	d = binary_tree_height(root->left) - binary_tree_height(root->right);
	if (d < 0)
		d = -d;
	if (d >= 1)
		e = 0;
	else
		e = 1;
	return (a & b & c & e);
}
