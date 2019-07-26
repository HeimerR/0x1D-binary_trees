#include "binary_trees.h"
#include "17-binary_tree_sibling.c"
#include "18-binary_tree_uncle.c"
/**
 * swaps - swaps number to be a heap
 * @node: pointer to the node
 * Return: pointer to node
 **/
heap_t *swaps(heap_t *node)
{
	int aux;

	while (node->parent && node->parent->n < node->n)
	{
		aux = node->n;
		node->n = node->parent->n;
		node->parent->n = aux;
		node = node->parent;
	}
	return (node);
}
/**
 * preorder - goes through a binary tree using pre-order traversal
 * @last_node: double pointer to find the last node
 * @tree: pointer to the root
 * @level: level to print
 * @ref: reference to start
 * Return: no return
 **/
void preorder(heap_t *tree, int level, int ref, heap_t **last_node)
{
	if (!tree)
		return;
	if (level == ref)
	{
		last_node[0] = tree;
	}
	if (tree->left)
		preorder(tree->left, level, ref + 1, last_node);
	if (tree->right)
		preorder(tree->right, level, ref + 1, last_node);
}
/**
 * height - measures the height of a binary tree
 * @tree: pointer to the node
 * Return: height of the tree
 **/
int height(heap_t *tree)
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
 * levelorder - traverses in zig-zag
 * @tree: pointer to the root
 * @last_node: las node in the tree
 * Return: no return
 **/
void levelorder(heap_t *tree, heap_t **last_node)
{
	int h, i;

	if (!tree)
		return;
	h = height(tree);
	for (i = 0; i <= h; i++)
	{
		preorder(tree, i, 0, last_node);
	}
}
/**
 * insert_right - inserts a node in the binary tree (right)
 * @parent: pointer to a parent node
 * @value: number value in the node
 * Return: pointer to the new node
**/
heap_t *insert_right(heap_t *parent, int value)
{
	heap_t *tmp, *node;

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
heap_t *insert_left(heap_t *parent, int value)
{
	heap_t *tmp, *node;

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
 * heap_insert - inserts node in a heap
 * @root: pointer to the root
 * @value: number to insert
 * Return: pointer to the new node
 **/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *first_row_node, **last_node, *insert_node, *tmp, *aux;

	if (!root)
		return (NULL);
	tree = *root;
	if (!tree)
	{
		*root = binary_tree_node(tree, value);
		return (*root);
	}
	aux = *root;
	first_row_node = *root;
	last_node = root;
	levelorder(tree, last_node);
	while (first_row_node->left)
		first_row_node = first_row_node->left;
	if (first_row_node == *last_node && first_row_node->parent == NULL)
	{
		insert_node = insert_left(first_row_node, value);
		insert_node = swaps(insert_node);
		*root = aux;
		return (insert_node);
	}
	if (binary_tree_sibling(*last_node))
	{
		tmp = binary_tree_uncle(*last_node);
		if (tmp)
			insert_node = insert_left(tmp, value);
		else
			insert_node = insert_left(first_row_node, value);
	}
	else
	{
		insert_node = insert_right(last_node[0]->parent, value);
	}
	insert_node = swaps(insert_node);
	*root = aux;
	return (insert_node);
}
