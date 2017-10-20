#ifndef BTREE_H
#define BTREE_H

#include "tree.h"
#include <string>
using namespace std;

class BTree : public Tree
{
protected:
	/*
	struct btree
	{
		string key;
		string value;
		btree *left;
		btree *right;
		btree *parent;
	};
	*/
	struct btree : node<string, btree>
	{
		btree *parent;
	};
	btree *NullNode = &EmptyNode;
	btree *root = NULL;
	btree *btreeCreate(string, string, btree *);
private:
	void btreeTransplant(btree *, btree *);
	void btreePrint(btree *);
	//btree EmptyNode = {"0", "0", NULL, NULL, NULL};
	btree EmptyNode;
public:
	void btreeAdd(string, string);
	btree *btreeSearch(string);
	void btreeDelete(string);
	btree *btreeMin(btree *);
	btree *btreeMin();
	btree *btreeMax(btree *);
	btree *btreeMax();
	void btreePrint();
	void btreeFree(btree *);
	void ggg();
	~BTree() {
		btreeFree(root);
	}
};

#endif