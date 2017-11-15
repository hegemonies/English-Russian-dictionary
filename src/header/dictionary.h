#include <iostream>
#include <string>
#include "avltree.h"
using namespace std;

class Dictionary
{
	AVLTree data;
public:
	void readFile(string /*name file*/);
	void translate(string /*word*/);
};