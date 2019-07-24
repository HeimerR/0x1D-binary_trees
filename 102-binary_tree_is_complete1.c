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
		printf("%d ", 1);
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
			printf("%d ", 0);
		}
		if (tree->right)
			preorder(tree->right, level, ref + 1, flag);
		else
		{
			if (*flag == 5)
				*flag = 5;
			else
				*flag = 0;
			printf("%d ", 0);
		}
	}
	return(*flag);
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
	int h, check_level;
	int flag[1] = {1};
	if (!tree)
		return (0);
	h = height(tree);
	printf("\nLeVel: %d \n", h);
	check_level = preorder(tree, h, 0, &flag[0]);
	if (check_level == 5)
		return (0);
	return (1);
}
