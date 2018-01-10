#include <iostream>
#include <string>
#include "avltree.h"
using namespace std;

class Dictionary
{
public:
	static AVLTree data;
	void readFile(string /*name file*/);
	static void translate(string /*word*/);
	static void process(string name_file, int start, int finish);
};

AVLTree Dictionary::data;