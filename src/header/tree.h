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
protected:
	virtual StructType *CreateNode(DataTypeKey /*key*/, DataTypeValue /*value*/, StructType */*node*/) = 0;
	//virtual void AddNode(DataTypeKey, DataTypeValue) = 0;
	//virtual StructType *SearchNode(DataTypeKey) = 0;
	virtual void DeleteNode(DataTypeKey /*key*/) = 0;
	virtual StructType *MinNode(StructType */*node*/) = 0;
	virtual StructType *MaxNode(StructType */*node*/) = 0;
	virtual void FreeTree(StructType */*node*/) = 0;
	virtual void PrintTree(void) = 0;
};

#endif