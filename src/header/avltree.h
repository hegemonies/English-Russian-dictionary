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
	int diffHeight(avltree *);
	void fixHeight(avltree *);
	void fixHeight();
	avltree *balance(avltree *);

	avltree *rotateLeft(avltree *);
	avltree *rotateRight(avltree *);
	avltree *rotateLeftRight(avltree *);
	avltree *rotateRightLeft(avltree *);
	void Display(avltree *, int);
	void FreeTree(avltree *);
	void PrintTree(avltree *);
	avltree *MinNode(avltree *);
	avltree *MaxNode(avltree *);
	void TransplantNods(avltree *, avltree *);
	avltree *AddNode(avltree *, string, string);

public:
	AVLTree() {
		NullNode->parent = NULL;
		NullNode->left = NULL;
		NullNode->right = NULL;
		NullNode->height = 0;
	}
	avltree *CreateNode(string, string, avltree *);
	void AddNode(string, string);
	avltree *SearchNode(string);
	void DeleteNode(string);
	avltree *MinNode();
	avltree *MaxNode();
	void PrintTree();
	void Display();

	avltree *Delete(avltree *, string);
	void Delete(string);
	avltree *DeleteMin(avltree *);
	~AVLTree()
	{
		FreeTree(root);
	}
};

#endif