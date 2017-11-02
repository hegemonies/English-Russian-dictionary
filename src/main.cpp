#include <iostream>
#include <string>
#include <cstdlib>
#include "avltree.h"
using namespace std;

int main(void)
{
	cout << "AVLTREE\n";
	AVLTree obj;
	obj.AddNode("5", "five");
	obj.AddNode("4", "four");
	obj.AddNode("2", "two");
	obj.AddNode("3", "three");
	obj.AddNode("1", "one");
	obj.AddNode("7", "seven");
	obj.AddNode("8", "eight");
	obj.AddNode("9", "nine");
	obj.AddNode("6", "six");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();

	cout << "\nПоиск узла 5: " << obj.SearchNode("5")->value << endl;

	cout << endl;
	obj.Display();

	obj.Delete("1");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();

	// cout << "\nBTREE";
	// BTree obj1;
	// obj1.AddNode("5", "five");
	// obj1.AddNode("4", "four");
	// obj1.AddNode("2", "two");
	// obj1.AddNode("3", "three");
	// obj1.AddNode("1", "one");
	// obj1.AddNode("7", "seven");
	// obj1.AddNode("8", "eight");
	// obj1.AddNode("9", "nine");
	// obj1.AddNode("6", "six");

	// cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n\n";
	// obj1.PrintTree();
}
