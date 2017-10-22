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
	avltree *root = NULL;
public:
	avltree *CreateNode(string, string, avltree *);
	void AddNode(string, string);
	avltree *SearchNode(string key);
	void DeleteNode(string key);
	void TransplantNods(avltree *node, avltree *new_node);
	avltree *MinNode();
	avltree *MinNode(avltree *node);
	avltree *MaxNode();
	void PrintTree(avltree *node);
	void PrintTree();
	void FreeTree(avltree *node);
	~AVLTree()
	{
		FreeTree(root);
	}
};

#endif