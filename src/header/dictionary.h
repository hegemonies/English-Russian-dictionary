#include <iostream>
#include <string>
#include <mutex>
#include "avltree.h"
using namespace std;

class Dictionary
{
public:
	AVLTree data;
	AVLTree *data_thread;

	Dictionary()
	{
		data_thread = new AVLTree[2];
	}

	Dictionary(int amount_threads)
	{
		data_thread = new AVLTree[amount_threads];
	}

	void readFile(string /*name file*/);
	void translate(string /*word*/);
	void process(AVLTree /*data*/, string /*name_file*/, int /*start*/, int /*finish*/, mutex */*mtx*/);
	void merge();
};