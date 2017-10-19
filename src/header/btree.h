#ifndef BTREE_H
#define BTREE_H
#include <string>
using namespace std;

class BTree
{
protected:
	struct btree
	{
		string key;
		string value;
		btree *left;
		btree *right;
		btree *parent;
	};
	btree EmptyNode = {"0", "0", NULL, NULL, NULL};
	btree *NullNode = &EmptyNode;
	btree *root = NULL;
public:
	btree *btreeCreate(string, string, btree *);
	void btreeAdd(string, string);
	btree *btreeSearch(string);
	void btreeDelete(string);
	btree *btreeTransplant(btree *, btree *);
	btree *btreeMin(btree *);
	btree *btreeMin();
	btree *btreeMax(btree *);
	btree *btreeMax();
	void btreePrint(btree *);
	void btreePrint();
};

#endif