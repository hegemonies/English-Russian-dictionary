#ifndef TREE_H
#define TREE_H

class Tree
{
protected:
	template<class PType, class SType>
	struct node
	{
		PType key;
		PType value;
		SType *left;
		SType *right;
	};
};

#endif