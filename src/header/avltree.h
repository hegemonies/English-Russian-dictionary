#ifndef AVLTREE_H
#define AVLTREE_H

#include "btree.h"
#include <iostream>
using namespace std;

struct avltree : public node<string, string, avltree>
{
	avltree *parent;
	int height;
};

class AVLTree : public BTree
{
	avltree EmptyNode;
	avltree *root = NULL;
	avltree *NullNode = &EmptyNode;

	int getHeight(avltree *);
	int diffHeight(avltree *);
	void fixHeight(avltree *);
	void fixHeight();

	avltree *rotateLeft(avltree *);
	avltree *rotateRight(avltree *);
	avltree *rotateLeftRight(avltree *);
	avltree *rotateRightLeft(avltree *);
	void Display(avltree *, int);
	void FreeTree(avltree *);
	void PrintTree(avltree *);
	avltree *MinNode(avltree *);
	avltree *MaxNode(avltree *);
	avltree *TransplantNods(avltree *, avltree *);
	avltree *AddNode(avltree *, string, string);

	avltree *Delete(avltree *, string);
public:
	AVLTree() {
		NullNode->parent = NULL;
		NullNode->left = NULL;
		NullNode->right = NULL;
		NullNode->height = -1;
	}
	avltree *CreateNode(string, string, avltree *);
	void AddNode(string, string);

	avltree *SearchNode(string);
	void DeleteNode(string);
	avltree *MinNode();
	avltree *MaxNode();
	void PrintTree();
	void Display();

	void Delete(string);

	avltree *getNullNode();

	~AVLTree()
	{
		FreeTree(root);
	}
};

#endif