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
	btree EmptyNode;
	btree *NullNode = &EmptyNode;
	btree *root = NULL;
protected:
	btree *CreateNode(string /*key*/, string /*value*/, btree */*node*/);
	virtual void FreeTree(btree */*node*/);
	virtual void PrintTree(btree */*node*/);
	void TransplantNods(btree */*node1*/, btree */*node2*/);
public:
	BTree(void) {
		NullNode->parent = NULL;
		NullNode->left = NULL;
		NullNode->right = NULL;
	}
	void AddNode(string /*key*/, string /*value*/);
	btree *SearchNode(string /*key*/);
	virtual void DeleteNode(string /*key*/);
	btree *MinNode(btree */*node*/);
	btree *MinNode(void);
	btree *MaxNode(btree */*node*/);
	btree *MaxNode(void);
	virtual void PrintTree(void);

	~BTree(void) {
		FreeTree(root);
	}
};
#endif