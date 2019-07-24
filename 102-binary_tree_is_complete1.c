#include "binary_trees.h"
/**
 * preorder - goes through a binary tree using pre-order traversal
 * @func: pointer to function that prints the values
 * @tree: pointer to the root
 * @level: level to print
 * @ref: reference to start
 * Return: no return
 **/
int preorder(const binary_tree_t *tree, int level, int ref, int *flag)
{
	/*if (!tree)
	{
		if (*flag == 2)
			return (0);
		*flag = 0;
		printf("flag: %d\n", flag[0]);
		return (1);
	}*/
	if (level == ref)
	{
		printf("%d ",tree->n);
		if (*flag == 0)
		{
			*flag = 2;
			return (0);
		}
		if (*flag == 2)
			return (0);
		*flag = 1;
	}
	if (tree->left)
		 preorder(tree->left, level, ref + 1, flag);
	else
	{
		*flag = 0;
		printf("NULL ");
	}
	if (tree->right)
		 preorder(tree->right, level, ref + 1, flag);
	else
	{
		*flag = 0;
		printf("NULL ");
	}
	return (1);
}
/**
 * height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height of the tree
 **/
int height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	right = height(tree->right) + 1;
	left = height(tree->left) + 1;
	if (left > right)
		return (left);
	else
		return (right);
}
/**
 * binary_tree_is_complete - finds the lowest common ancestor of two nodes
 * @tree: pointer to the root
 * Return: 1 if it is complete or 0 otherwise
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int i, h, check_level;
	int flag[1] = {1};
	if (!tree)
		return (0);

	h = height(tree);;
	for (i = 1; i <= h; i++)
	{
		printf("\n Level: %d \n", i);
		check_level = preorder(tree, i, 0, &flag[0]);
		if (check_level == 0)
			return (0);
	}
	return (check_level);
}
