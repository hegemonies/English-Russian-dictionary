#ifndef AVLTREE_H
#define AVLTREE_H

#include "btree.h"

class AVLTree : public BTree
{
	struct avltree : public btree
	{
		int height;
	};
public:
	avltree *avltreeCreate(string, string, avltree *);
	~AVLTree()
	{
		btreeFree(root);
	}
	
};

#endif