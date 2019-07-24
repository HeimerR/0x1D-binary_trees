#include "binary_trees.h"
/**
 * insert_right - inserts a node in the binary tree (right)
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node
**/
binary_tree_t *insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->right;
	node = binary_tree_node(parent, value);
	parent->right = node;
	if (tmp != NULL)
	{
		node->right = tmp;
		tmp->parent = node;
	}
	return (node);
}
/**
 * insert_left - inserts a node in the binary tree (left)
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node
**/
binary_tree_t *insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (!parent)
		return (NULL);
	tmp = parent->left;
	node = binary_tree_node(parent, value);
	parent->left = node;
	if (tmp != NULL)
	{
		node->left = tmp;
		tmp->parent = node;
	}
	return (node);
}
/**
 * bst_insert - checks if a binary tree is bts
 * @tree: pointer to the node
 * @value:number to insert
 * Return: 1 if it is bts 0 otherwise
 **/
bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *root;

	if (!tree)
		return (NULL);
	root = *tree;
	if (!root)
	{
		*tree = binary_tree_node(root, value);
		return (*tree);
	}
	while (root->left || root->right)
	{
		if (root && (root->n > value))
		{
			if (root->left)
				root = root->left;
			else
				break;
		}
		else if (root && (root->n < value))
		{
			if (root->right)
				root = root->right;
			else
				break;
		}
		else if (root && (root->n == value))
			return (NULL);
	}
	if (root && (root->n == value))
		return (NULL);
	if (root && (root->n > value))
		return (insert_left(root, value));
	else if (root && (root->n < value))
		return (insert_right(root, value));
	return (NULL);
}
