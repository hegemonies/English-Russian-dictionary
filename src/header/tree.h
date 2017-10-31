#ifndef TREE_H
#define TREE_H
#include <string>

template<class TypeKey, class TypeValue, class SType>
struct node
{
	TypeKey key;
	TypeValue value;
	SType *left;
	SType *right;
};

template<class DataTypeKey, class DataTypeValue, class StructType>
class Tree
{
// public:
// 	StructType EmptyNode;
// 	StructType *NullNode = &EmptyNode;
// 	StructType *root = NULL;
protected:
	virtual StructType *CreateNode(DataTypeKey, DataTypeValue, StructType *) = 0;
	virtual void AddNode(DataTypeKey, DataTypeValue) = 0;
	// virtual StructType *SearchNode(DataTypeKey) = 0;
	// virtual void DeleteNode(DataTypeKey) = 0;
	// virtual StructType *MinNode(StructType *) = 0;
	// virtual StructType *MaxNode(StructType *) = 0;
	// virtual void FreeTree(StructType *) = 0;
	// virtual void PrintTree() = 0;
};

#endif