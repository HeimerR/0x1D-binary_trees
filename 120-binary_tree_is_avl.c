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
	int a = 0, b = 0, c = 0, hleft = 0, hright = 0, okh = 0, dh;
	avl_t *root;

	root = (avl_t *)tree;
	if (!root)
		return (0);
	a = binary_tree_is_bst(root);
	if (!root->left && !root->right)
		return (1);
	else
	{
		if (root->left)
		{
			b = binary_tree_is_bst(root->left);
			hleft = binary_tree_height(root->left);
		}
		if (root->right)
		{
			c = binary_tree_is_bst(root->right);
			hright = binary_tree_height(root->right);
		}
		dh = hleft - hright;
		if (dh < 0)
			dh = -dh;
		if (dh >= 1)
			okh = 0;
		else
			okh = 1;
	}
	return (a & b & c & okh);
}
