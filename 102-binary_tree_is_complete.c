#include "binary_trees.h"
#include "9-binary_tree_height.c"
/**
 * preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root
 * @level: level to print
 * @ref: reference to start
 * @flag: used to store if the node exist or not
 * Return: condition of change (exist or not) a node
 **/
int preorder(const binary_tree_t *tree, int level, int ref, int *flag)
{
	if (level == ref)
	{
		if (*flag == 0 || *flag == 5)
		{
			*flag = 5;
			return (*flag);
		}
		*flag = 1;
	}
	else
	{
		if (tree->left)
			preorder(tree->left, level, ref + 1, flag);
		else
		{
			if (*flag == 5)
				*flag = 5;
			else
				*flag = 0;
		}
		if (tree->right)
			preorder(tree->right, level, ref + 1, flag);
		else
		{
			if (*flag == 5)
				*flag = 5;
			else
				*flag = 0;
		}
	}
	return (*flag);
}

/**
 * binary_tree_is_complete - finds the lowest common ancestor of two nodes
 * @tree: pointer to the root
 * Return: 1 if it is complete or 0 otherwise
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int h, check_level;
	int flag[1] = {1};

	if (!tree)
		return (0);
	h = binary_tree_height(tree);
	check_level = preorder(tree, h - 1, 0, &flag[0]);
	if (check_level == 1)
	{
		check_level = preorder(tree, h, 0, &flag[0]);
		if (check_level == 5)
			return (0);
	}
	else
		return (0);
	return (1);
}
