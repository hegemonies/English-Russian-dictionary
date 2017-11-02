#ifndef AVLTREE_H
#define AVLTREE_H

#include "btree.h"

struct avltree : public node<string, string, avltree>
{
	avltree *parent;
	int height;
};

class AVLTree : public BTree
{
	avltree EmptyNode;
	avltree *NullNode = &EmptyNode;
	avltree *root = NULL;

	int getHeight(avltree *);
	int hBalance(avltree *);
	void fixHeight(avltree *);
	avltree *rotateLeft(avltree *);
	avltree *rotateRight(avltree *);
	avltree *rotateLeftRight(avltree *);
	avltree *rotateRightLeft(avltree *);
public:
	AVLTree() {
		NullNode->parent = NULL;
		NullNode->left = NULL;
		NullNode->right = NULL;
	}
	avltree *CreateNode(string, string, avltree *);
	avltree *AddNode(avltree *, string, string);
	void AddNode(string, string);
	avltree *SearchNode(string);
	void DeleteNode(string);
	void TransplantNods(avltree *, avltree *);
	avltree *MinNode();
	avltree *MinNode(avltree *);
	avltree *MaxNode();
	avltree *MaxNode(avltree *);
	void PrintTree(avltree *);
	void PrintTree();
	void FreeTree(avltree *);
	~AVLTree()
	{
		FreeTree(root);
	}
};

#endif