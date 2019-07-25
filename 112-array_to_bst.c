#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the array
 * @size:size of the array
 * Return: pointer to root tree
 **/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (!array)
		return (NULL);
	root = NULL;
	bst_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
