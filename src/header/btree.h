#ifndef BTREE_H
#define BTREE_H

#include "tree.h"
#include <string>
using namespace std;
/*
class BTree : public Tree
{
protected:
	
	//struct btree
	//{
	//	string key;
	//	string value;
	//	btree *left;
	//	btree *right;
	//	btree *parent;
	//};
	
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
	~BTree() {
		btreeFree(root);
	}
};
*/
//typedef struct {} btree;
//class BTree : public Tree<string, string, btree>
//template<class SType>?????
class BTree : public Tree
{
	struct btree : node<string, string, btree>
	{
		btree *parent;
	};
	btree EmptyNode;
	btree *NullNode = &EmptyNode;
	btree *root = NULL;
protected:
	//SType *CreateNode(string, string, SType *); ???
	virtual btree *CreateNode(string, string, btree *);
	virtual void FreeTree(btree *);
	virtual void PrintTree(btree *);
public:
	virtual void AddNode(string, string);
	virtual btree *SearchNode(string);
	virtual void DeleteNode(string);
	virtual  void TransplantNods(btree *, btree *);
	virtual btree *MinNode(btree *);
	virtual btree *MinNode();
	virtual btree *MaxNode(btree *);
	virtual btree *MaxNode();
	virtual void PrintTree();
	~BTree() {
		FreeTree(root);
	}
};
#endif

/*????
BTree<BTree<btree>::btree>::SType *BTree<btree>::CreateNode(string, string, SType *)
{

}
*/