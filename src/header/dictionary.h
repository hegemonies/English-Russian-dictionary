#include <iostream>
#include <string>
#include "avltree.h"
using namespace std;

class Dictionary
{
	AVLTree data;
public:
	void readFile(string);
	void translate(string);
}