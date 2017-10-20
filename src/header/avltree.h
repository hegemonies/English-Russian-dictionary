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
	void avltreeAdd(string, string);
	void btreeDelete(string);//написать, изменив под авл
	~AVLTree()
	{
		btreeFree(root);
	}
	
};

#endif