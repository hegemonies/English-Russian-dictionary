#include <iostream>
#include <string>
#include <mutex>
#include "avltree.h"
using namespace std;

class Dictionary
{
public:
	AVLTree data;
	void readFile(string /*name file*/);
	void translate(string /*word*/);
	void process(string name_file, int start, int finish, mutex *mtx);
};