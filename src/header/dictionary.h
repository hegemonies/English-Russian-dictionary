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
	int count_theard;

	Dictionary()
	{
		count_theard = 0;
		data_thread = new AVLTree[4];
	}

	// Dictionary(int amount_threads)
	// {
	// 	data_thread = new AVLTree[amount_threads];
	// 	count_theard = amount_threads;
	// }

	void readFile(string /*name file*/);
	void translate(string /*word*/);
	void process(int /*number_of_thread*/, string /*name_file*/, int /*start*/, int /*finish*/, mutex */*mtx*/);
	void merge();
	string get_key();
};