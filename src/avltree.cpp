#include "avltree.h"
#include <iostream>
#include <string>

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

avltree *AVLTree::AddNode(avltree *node, string key, string value)
{
	if (node == NULL || node == NullNode) {
		return CreateNode(key, value, NULL);
	}

	if (key < node->key) {
		node->left = AddNode(node->left, key, value);
		node->left->parent = node;
		if (diffHeight(node) == 2) {
			if (key < node->left->key) {
				node = rotateRight(node);
			} else {
				node = rotateLeftRight(node);
			}
		}
	} else if (key > node->key) {
		node->right = AddNode(node->right, key, value);
		node->right->parent = node;
		if (diffHeight(node) == -2) {
			if (key > node->right->key) {
				node = rotateLeft(node);
			} else {
				node = rotateRightLeft(node);
			}
		}
	}
	fixHeight();

	return node;
}

int AVLTree::diffHeight(avltree *node)
{
	int l;
	if (node->left == NullNode) {
		l = 0;
	} else {
		l = getHeight(node->left);
	}

	int r;
	if (node->right == NullNode) {
		r = 0;
	} else {
		r = getHeight(node->right);
	}
	
	return l - r;
}

void AVLTree::Delete(string key)
{
	root = Delete(root, key);
	fixHeight();
}

avltree *AVLTree::Delete(avltree *node, string key)
{
	if (node == NULL || node == NullNode) {
		return NullNode;
	}

	if (key == root->key) {
		node = root;
		DeleteNode(node->key);
		fixHeight();
		if (diffHeight(node) == -2) {
			if (node->right->left == NullNode || node->right->left == NULL) {
				node = rotateLeft(node);
			} else {
				node = rotateRightLeft(node);
			}
		}
		fixHeight();
		return root;
	}

	if (key < node->key) {
		node->left = Delete(node->left, key);
		if (key == node->left->key) {
			DeleteNode(node->left->key);
		}
		fixHeight();
		if (diffHeight(node) == -2) {
			if (node->right->left == NullNode || node->right->left == NULL) {
				node = rotateLeft(node);
			} else {
				node = rotateRightLeft(node);
			}
		}
		fixHeight();
		return node;
	} else if (key > node->key) {
		node->right = Delete(node->right, key);
		if (key == node->right->key) {
			DeleteNode(node->right->key);
		}
		fixHeight();
		if (diffHeight(node) == 2) {
			if (node->left->right == NullNode || node->left->right == NULL) {
				node = rotateRight(node);
			} else {
				node = rotateLeftRight(node);
			}
		}
		fixHeight();
		return node;
	}
	
	fixHeight();

	return node;
}

void AVLTree::AddNode(string key, string value)
{
	root = AddNode(root, key, value);
	fixHeight();
}

avltree *AVLTree::SearchNode(string key)
{
	avltree *node = root;

	while (node != NULL && node != NullNode) {
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
	if (key.empty()) {
		return;
	}
	avltree *node = SearchNode(key);
	if (!node) {
		return;
	}
	avltree *save;

	if (node->left != NULL && node->right == NullNode) {
		root = TransplantNods(node, node->left);
	} else if (node->right != NULL && node->left == NullNode) {
		root = TransplantNods(node, node->right);
	} else {
		save = node;
		node = MinNode(node->right);
		if (node->parent == save) {
			node->right->parent = node;
		} else {
			root = TransplantNods(node, node->right);
			node->right = save->right;
			node->right->parent = node;
		}
		root = TransplantNods(save, node);
		node->left = save->left;
		node->left->parent = node;
	}
}

avltree *AVLTree::TransplantNods(avltree *node, avltree *new_node)
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

	return root;
}

avltree *AVLTree::MinNode(avltree *node)
{
	while (node->left != NullNode) {
		node = node->left;
	}

	return node;
}

avltree *AVLTree::MinNode()
{
	return MinNode(root);
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
    	cout << "\t" << node->right << "\t";
    }
    cout << node->height << endl;
    PrintTree(node->right);
}

void AVLTree::PrintTree()
{
	cout << "\t\troot is " << root->key << endl;
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

int AVLTree::getHeight(avltree *node)
{
    return node ? node->height + 1 : 0;
}

void AVLTree::fixHeight()
{
	fixHeight(root);
}


void AVLTree::fixHeight(avltree *node)
{
	if (node == NullNode || node == NULL) {
		return;
	}
	fixHeight(node->left);
	fixHeight(node->right);
	int hl = getHeight(node->left);
	int hr = getHeight(node->right);
	node->height = (hl > hr ? hl : hr);
}

avltree *AVLTree::rotateLeft(avltree *node)
{
	if (node == NullNode) {
		return NullNode;
	}
	avltree *des = node->right;
	node->right = des->left;
	if (des->left != NULL) {
		des->left->parent = node;
	}
	des->parent = node->parent;
	if (node->parent != NULL) {
		if (node->parent->left == node) {
			node->parent->left = des;
		} else {
			node->parent->right = des;
		}
	} else {
		des->parent = node->parent;
	}

	des->left = node;
	node->parent = des;

	return des;
}

avltree *AVLTree::rotateRight(avltree *node)
{
	if (node == NullNode) {
		return NullNode;
	}
	avltree *des = node->left;
	node->left = des->right;
	if (des->right != NULL) {
		des->right->parent = node;
	}
	des->parent = node->parent;
	if (node->parent != NULL) {
		if (node->parent->right == node) {
			node->parent->right = des;
		} else {
			node->parent->left = des;
		}
	} else {
		des->parent = node->parent;
	}
	des->right = node;
	node->parent = des;

	return des;
}

avltree *AVLTree::rotateLeftRight(avltree *node)
{
	node->left = rotateLeft(node->left);
	return rotateRight(node);
}

avltree *AVLTree::rotateRightLeft(avltree *node)
{
	node->right = rotateRight(node->right);
	return rotateLeft(node);
}

void AVLTree::Display()
{
    Display(root, 0);
    cout << endl;
}

void AVLTree::Display(avltree *node, int level)
{
    if (node) {
        Display(node->right, level + 1);
        cout << endl;
        if (node == root)
        cout << "ROOT->";
        for (int i = 0; i < level && node != root; i++)
            cout << "        ";
        cout << node->key;
        Display(node->left, level + 1);
    }
}

avltree *AVLTree::getNullNode()
{
	return NullNode;
}