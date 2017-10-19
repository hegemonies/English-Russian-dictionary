#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class BTree
{
protected:
	struct btree
	{
		string key;
		string value;
		btree *left;
		btree *right;
		btree *parent;
	};
	btree EmptyNode = {"0", "0", NULL, NULL, NULL};
	btree *NullNode = &EmptyNode;
	btree *root = NULL;
public:
	btree *btreeCreate(string key, string value, btree *parent)
	{
		btree *node;
		try {
			node = new btree;
		} catch (bad_alloc xa) {
			cout << "\n\tBad allocation\n";
			exit(1);
		}
		node->key = key;
		node->value = value;
		node->left = NullNode;
		node->right = NullNode;
		node->parent = parent;

		return node;
	}
	void btreeAdd(string, string);
	btree *btreeSearch(string);
	void btreeDelete(string);
	btree *btreeTransplant(btree *, btree *);
	btree *btreeMin(btree *);
	btree *btreeMin();
	btree *btreeMax();
	btree *btreeMax(btree *);
	void btreePrint(btree *, int);
	void btreePrint(btree *);
	void btreePrint();
};
/*
btree *BTree::btreeCreate(string key, string value, btree *parent)
{
	try {
		btree *node = new btree;
	} catch (bad_alloc xa) {
		cout << "\n\tBad allocation\n"
		exit(1);
	}
	node->key = key;
	node->value = value;
	node->left = NullNode;
	node->right = NullNode;
	node->parent = parent;

	return node;
}
*/
void BTree::btreeAdd(string key, string value)
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

	node = btreeCreate(key, value, parent);

	if (root == NULL) {
		root = node;
	} else if (key < parent->key) {
		parent->left = node;
	} else if (key > parent->key) {
		parent->right = node;
	}
}

BTree::btree *BTree::btreeSearch(string key)
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

void BTree::btreeDelete(string key)
{
	btree *node = btreeSearch(key);
	btree *save;
	btree *new_node;

	if (node->left != NULL && node->right == NullNode) {
		//new_node = node->right;
		root = btreeTransplant(node, node->right);
	} else if (node->right != NULL && node->left == NullNode) {
		//new_node = node->left;
		root = btreeTransplant(node, node->left);
	} else {
		save = btreeMin(node->right);
		new_node = save->right;
		if (save->parent == node) {
			new_node->parent = save;
		} else {
			root = btreeTransplant(save, save->right);
			save->right = node->right;
			save->right->parent = save;
		}
		root = btreeTransplant(node, save);
		save->left = node->left;
		save->left->parent = save;
	}
}

BTree::btree *BTree::btreeTransplant(btree *node, btree *new_node)
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

BTree::btree *BTree::btreeMin()
{
	return btreeMin(root);
}

BTree::btree *BTree::btreeMin(btree *node)
{
	while (node != NullNode) {
		node = node->left;
	}

	return node;
}

BTree::btree *BTree::btreeMax()
{
	return btreeMax(root);
}

BTree::btree *BTree::btreeMax(btree *node)
{
	while (node != NullNode) {
		node = node->right;
	}

	return node;
}

void BTree::btreePrint(btree *node)
{
	if (node == NULL || node == NullNode)
		return;
	cout << node->value << " : " << node->key << endl;
	btreePrint(node->left);
	btreePrint(node->right);
}
void BTree::btreePrint(btree *node, int level)
{
	if (node != NullNode || !node) {
		btreePrint(node->left, level + 1);
		for (int i = 0; i < level; i++) {
			cout << "	";
		}
	cout << node->value << " : " << node->key << endl;
	btreePrint(node->right, level + 1);
	}
}
/*
void BTree::btreePrint(btree *node)
{
	btreePrint(node, 0);
}*/

void BTree::btreePrint()
{
	btreePrint(root);
}

int main(void)
{
	BTree obj;
	obj.btreeAdd("first", "test");
	obj.btreePrint();
}
