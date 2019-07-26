#include "binary_trees.h"
/**
 * array_to_avl - Builds an AVL tree from array
 * @array: pointer to array
 * @size:size of array
 * Return: pointer to new tree
 **/
avl_t *array_to_avl(int *array, size_t size);
{
	avl_t *tmp, *new;
	int flag;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	tmp = *tree;
	flag = 0;
	while (flag == 0)
	{
		if (value > tmp->n)
			if (tmp->right)
				tmp = tmp->right;
			else
			{
				flag = 1;
				new = binary_tree_node(tmp, value);
				tmp->right = new;
				return (new);
			}
		else
			if (tmp->left)
				tmp = tmp->left;
			else
			{
				flag = 1;
				new = binary_tree_node(tmp, value);
				tmp->left = new;
				return (new);
			}
	}
	return (NULL);
}
