#include "btree.h"
#include <string>
#include <iostream>
using namespace std;

btree *BTree::CreateNode(string key, string value, btree *parent)
{
	btree *node;
	try {
		node = new btree;
	} catch (bad_alloc xa) {
		cout << "\n\tBad allocation for btree node.\n";
		exit(1);
	}
	node->key = key;
	node->value = value;
	node->left = NullNode;
	node->right = NullNode;
	node->parent = parent;

	return node;
}

void BTree::AddNode(string key, string value)
{
	btree *node = root;
	btree *parent = NULL;
		
	while (node != NullNode && node != NULL) {
		parent = node;
		if (key < node->key) {
			node = node->left;
		} else if (key > node->key) {
			node = node->right;
		} else {
			return;
		}
	}

	node = CreateNode(key, value, parent);

	if (root == NULL) {
		root = node;
	} else if (key < parent->key) {
		parent->left = node;
	} else if (key > parent->key) {
		parent->right = node;
	}
}

btree *BTree::SearchNode(string key)
{
	btree *node = root;

	while (node != NULL) {
		if (key == node->key) {
			return node;
		} else if (key < node->key) {
			node = node->left;
		} else if (key > node->key) {
			node = node->right;
		}
	}

	return node;
}

void BTree::DeleteNode(string key)
{
	btree *node = SearchNode(key);
	btree *save;

	if (node->left != NULL && node->right == NullNode) {
		TransplantNods(node, node->left);
	} else if (node->right != NULL && node->left == NullNode) {
		TransplantNods(node, node->right);
	} else {
		save = node;
		node = MinNode(node->right);
		if (node->parent == save) {
			node->right->parent = node;
		} else {
			TransplantNods(node, node->right);
			node->right = save->right;
			node->right->parent = node;
		}
		TransplantNods(save, node);
		node->left = save->left;
		node->left->parent = node;
	}
}

void BTree::TransplantNods(btree *node, btree *new_node)
{
	if (node->parent == NULL) {
		root = new_node;
	} else if (node->parent != NULL && node == node->parent->left) {
		node->parent->left = new_node;
	} else {
		node->parent->right = new_node;
	}
	if (new_node != NULL) {
		new_node->parent = node->parent;
	}
}

btree *BTree::MinNode()
{
	return MinNode(root);
}

btree *BTree::MinNode(btree *node)
{
	while (node->left != NullNode) {
		node = node->left;
	}

	return node;
}

btree *BTree::MaxNode()
{
	return MaxNode(root);
}

btree *BTree::MaxNode(btree *node)
{
	while (node->right != NullNode) {
		node = node->right;
	}

	return node;
}

void BTree::PrintTree(btree *node)
{
    if (node == NULL || node == NullNode) {
    	return;
    }
    PrintTree(node->left);
    cout << node->key << "\t" << node->value << "\t" << node;
    if (!node->parent) {
    	cout << "\t\t" << node->parent;
    } else {
    	cout << "\t" << node->parent;
    }
    if (!node->left) {
    	cout << "\t\t" << node->left;
    } else {
    	cout << "\t" << node->left;
    }
    if (!node->right) {
    	cout << "\t\t" << node->right;
    } else {
    	cout << "\t" << node->right << endl;
    }
    PrintTree(node->right);
}

void BTree::PrintTree()
{
	PrintTree(root);
}

void BTree::FreeTree(btree *node)
{
	if (node == NULL || node == NullNode) {
		return;
	}
	FreeTree(node->left);
	FreeTree(node->right);
	delete node;
}