#include <iostream>
#include <string>
#include "avltree.h"
using namespace std;

class Dictionary
{
	AVLTree data;
public:
	string Utf8_to_cp1251(const char *str);
	void readFile(string);
	void translate(string);
};