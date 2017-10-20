#include "avltree.h"
#include "btree.h"
#include <iostream>
/*
AVLTree::avltree *AVLTree::avltreeCreate(string key, string value, avltree *parent)
{
	btree *node_btree = BTree<btree>::btreeCreate(key, value, parent);

	avltree *node_avl;
	try {
		node_avl = new avltree;
	} catch (bad_alloc xa) {
		cout << "\n\tBad allocation for avltree node.\n";
		exit(1);
	}
	node_avl->key = node_btree->key;
	node_avl->value = node_btree->value;
	node_avl->left = node_btree->left;
	node_avl->right = node_btree->right;
	node_avl->parent = node_btree->parent;
	node_avl->height = 0;

	delete node_btree;

	return node_avl;
}
*/
/*
void AVLTree::avltreeAdd(string key, string value)
{

}
*/