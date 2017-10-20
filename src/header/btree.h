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
	btree *NullNode = &EmptyNode;
	btree *root = NULL;
	btree *btreeCreate(string, string, btree *);
private:
	void btreeTransplant(btree *, btree *);
	void btreePrint(btree *);
	btree EmptyNode = {"0", "0", NULL, NULL, NULL};
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
	~BTree() {
		btreeFree(root);
	}
};

#endif