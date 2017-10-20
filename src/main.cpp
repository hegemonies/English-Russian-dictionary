#include <iostream>
#include <string>
#include <cstdlib>
#include "btree.h"
using namespace std;

int main(void)
{
	BTree obj;
	obj.ggg();
	obj.btreeAdd("5", "five");
	obj.btreeAdd("3", "three");
	obj.btreeAdd("2", "two");
	obj.btreeAdd("4", "four");
	obj.btreeAdd("9", "nine");
	obj.btreeAdd("7", "seven");
	obj.btreeAdd("6", "six");
	obj.btreeAdd("1", "one");
	obj.btreeAdd("8", "eight");
	
	cout << "key\tvalue\t&node\t\tparent\t\tleft\t\tright\n\n";
	obj.btreePrint();
}
