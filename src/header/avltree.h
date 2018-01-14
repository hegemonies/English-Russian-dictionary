#ifndef AVLTREE_H
#define AVLTREE_H

#include "btree.h"
#include <iostream>
using namespace std;

class AVLTree : public BTree
{
public:
	struct avltree : public node<string, string, avltree>
	{
		avltree *parent;
		int height;
		avltree(string k = "", string v = "") {
			key = k;
			value = v;
			height = 0;
			parent = NULL;
		}
	};
	AVLTree(void) {
		NullNode->parent = NULL;
		NullNode->left = NULL;
		NullNode->right = NULL;
		NullNode->height = -1;
	}
	avltree *CreateNode(string /*key*/, string /*value*/);
	void AddNode(string /*key*/, string /*value*/);

	avltree *SearchNode(string /*key*/);
	void DeleteNode(string /*key*/);
	avltree *MinNode(void);
	avltree *MaxNode(void);
	avltree *MaxNode(avltree */*node*/);
	void PrintTree(void);
	void Display(void);

	void Delete(string);

	avltree *getNullNode(void);

	~AVLTree(void)
	{
		//FreeTree(root);
	}
	avltree *root = NULL;
private:
	avltree EmptyNode;
	avltree *NullNode = &EmptyNode;

	int getHeight(avltree */*node*/);
	int diffHeight(avltree */*node*/);
	void fixHeight(avltree */*node*/);
	void fixHeight(void);

	avltree *rotateLeft(avltree */*node*/);
	avltree *rotateRight(avltree */*node*/);
	avltree *rotateLeftRight(avltree */*node*/);
	avltree *rotateRightLeft(avltree */*node*/);
	void Display(avltree */*node*/, int /*level*/);
	void FreeTree(avltree */*node*/);
	void PrintTree(avltree */*node*/);
	avltree *MinNode(avltree */*node*/);
	avltree *TransplantNods(avltree */*node1*/, avltree */*node2*/);
	avltree *AddNode(avltree */*node*/, string /*key*/, string/*value*/);

	avltree *Delete(avltree */*node*/, string /*key*/);
};

#endif