#ifndef AVLTREE_H
#define AVLTREE_H

#include "btree.h"

class AVLTree : public BTree
{
	struct avltree : public node<string, string, avltree>
	{
		avltree *parent;
		int height;
	};
	avltree EmptyNode;
	avltree *NullNode = &EmptyNode;
public:
	avltree *root = NULL;
	avltree *CreateNode(string, string, avltree *);
	void AddNode(string, string);
	/*
	void btreeDelete(string);//написать, изменив под авл
	~AVLTree()
	{
		btreeFree(root);
	}
	*/
};

#endif