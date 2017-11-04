#ifndef BTREE_H
#define BTREE_H

#include "tree.h"
#include <string>
using namespace std;

struct btree : public node<string, string, btree>
{
	btree *parent;
};

class BTree : public Tree<string, string, btree>
{
public:
	btree EmptyNode;
	btree *NullNode = &EmptyNode;
	btree *root = NULL;
//protected:
	btree *CreateNode(string, string, btree *);
	virtual void FreeTree(btree *);
	virtual void PrintTree(btree *);
	void TransplantNods(btree *, btree *);
// public:
	BTree() {
		NullNode->parent = NULL;
		NullNode->left = NULL;
		NullNode->right = NULL;
	}
	void AddNode(string, string);
	btree *SearchNode(string);
	virtual void DeleteNode(string);
	btree *MinNode(btree *);
	btree *MinNode();
	btree *MaxNode(btree *);
	btree *MaxNode();
	virtual void PrintTree();

	~BTree() {
		FreeTree(root);
	}
};
#endif