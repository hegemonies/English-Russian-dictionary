#include <iostream>
#include <string>
#include <cstdlib>
#include "btree.h"
#include "avltree.h"
using namespace std;

int main(void)
{
	AVLTree obj;
	obj.AddNode("5", "five");
	obj.AddNode("3", "three");
	obj.AddNode("2", "two");
	obj.AddNode("4", "four");
	obj.AddNode("9", "nine");
	obj.AddNode("7", "seven");
	obj.AddNode("6", "six");
	obj.AddNode("1", "one");
	obj.AddNode("8", "eight");
	
	cout << "key\tvalue\t&node\t\tparent\t\tleft\t\tright\n\n";
	obj.PrintTree();
}
