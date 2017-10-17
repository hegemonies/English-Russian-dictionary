#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class BTree
{
protected:
	typedef struct
	{
		string key;
		string value;
		struct btree *left;
		struct btree *right;
		struct btree *parent;
	} btree;
	btree *root;
	btree EmptyNode = {"0", "0", NULL, NULL, NULL};
	btree *NullNode = &EmptyNode;
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
	btree *btreeMin();
	btree *btreeMax();
	void btreePrint(btree *);
};

btree *btreeCreate(string key, string value, btree *parent)
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

btree *BTree::btreeSearch(string key)
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
	rbtree *node = btreeSearch(key);
	rbtree *save;
	rbtree *new_node;

	if (node->left != NULL && node->right == NullNode) {
		//new_node = node->right;
		root = btreeTransplant(root, node, node->right);
	} else if (node->right != NULL && node->left == NullNode) {
		//new_node = node->left;
		root = btreeTransplant(root, node, node->left);
	} else {
		save = rbtree_min(node->right);
		save_color = save->color;
		new_node = save->right;
		if (save->parent == node) {
			new_node->parent = save;
		} else {
			root = rbtree_transplant(root, save, save->right);
			save->right = node->right;
			save->right->parent = save;
		}
		root = btreeTransplant(root, node, save);
		save->left = node->left;
		save->left->parent = save;
		save->color = node->color;
	}
}

btree *BTree::btreeTransplant(btree *node, btree *new_node)
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

btree *BTree::btreeMin()
{
	btree *node = root;

	while (node != NullNode) {
		node = node->left;
	}

	return node;
}

btree *BTree::btreeMax()
{
	btree *node = root;

	while (node != NullNode) {
		node = node->left;
	}

	return node;
}

void BTree::btreePrint(btree *node)
{
	if (node == NULL)
		return;
	btreePrint(node->left);
	cout << node->value << " : " << node->key;
	btreePrint(node->right);
}


int main(void)
{
	BTree obj;
	obj.btreeAdd("first", "test");
	obj.btreePrint();
}