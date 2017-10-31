#include "avltree.h"
#include "avltree.h"
#include <iostream>

avltree *AVLTree::CreateNode(string key, string value, avltree *parent)
{
	avltree *node;
	try {
		node = new avltree;
	} catch (bad_alloc xa) {
		cout << "\n\tBad allocation for avltree node.\n";
		exit(1);
	}
	node->key = key;
	node->value = value;
	node->left = NullNode;
	node->right = NullNode;
	node->parent = parent;
	node->height = 0;

	return node;
}

void AVLTree::AddNode(string key, string value)
{
	avltree *node = root;
	avltree *parent = NULL;
		
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

avltree *AVLTree::SearchNode(string key)
{
	avltree *node = root;

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

void AVLTree::DeleteNode(string key)
{
	avltree *node = SearchNode(key);
	avltree *save;

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

void AVLTree::TransplantNods(avltree *node, avltree *new_node)
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

avltree *AVLTree::MinNode()
{
	return MinNode(root);
}

avltree *AVLTree::MinNode(avltree *node)
{
	while (node->left != NullNode) {
		node = node->left;
	}

	return node;
}

avltree *AVLTree::MaxNode(avltree *node)
{
	while (node->right != NullNode) {
		node = node->right;
	}

	return node;
}

avltree *AVLTree::MaxNode()
{
	return MaxNode(root);
}

void AVLTree::PrintTree(avltree *node)
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

void AVLTree::PrintTree()
{
	PrintTree(root);
}

void AVLTree::FreeTree(avltree *node)
{
	if (node == NULL || node == NullNode) {
		return;
	}
	FreeTree(node->left);
	FreeTree(node->right);
	delete node;
}