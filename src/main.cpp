#include <iostream>
#include <string>
#include <cstdlib>
#include "avltree.h"
using namespace std;

int main(void)
{
	cout << "AVLTREE\n";
	AVLTree obj;
	obj.AddNode("0", "null");
	obj.AddNode("1", "one");
	obj.AddNode("2", "two");
	obj.AddNode("3", "three");
	obj.AddNode("4", "four");
	obj.AddNode("5", "five");
	obj.AddNode("6", "six");
	obj.AddNode("7", "seven");
	obj.AddNode("8", "eight");
	obj.AddNode("9", "nine");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();

	cout << "delete 0\n";
	obj.Delete("0");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();

	cout << "delete 2\n";
	obj.Delete("2");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();

	cout << "delete 5\n";
	obj.Delete("5");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
}
