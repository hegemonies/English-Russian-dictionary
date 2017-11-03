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
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("4", "four");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("2", "two");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("3", "three");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("1", "one");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("7", "seven");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("8", "eight");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("9", "nine");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	obj.AddNode("6", "six");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();

	cout << "\nПоиск узла 5: " << obj.SearchNode("5")->value << endl;

	cout << endl;
	obj.Display();

	// obj.Delete("1");
	obj.Delete("4");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	cout << "\nhey\n";
	obj.Delete("1");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	cout << "\nhey\n";
	obj.Delete("3");
	cout << "\nkey\tvalue\t&node\t\tparent\t\tleft\t\tright\n";
	obj.PrintTree();
	cout << "\nhey\n";

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
