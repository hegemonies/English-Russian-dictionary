#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>
#include <unistd.h>
#include "dictionary.h"
using namespace std;

// thread::id th1;
// thread::id th2;
// thread::id th3;
// thread::id th4;

// void compute_count(std::thread::id number_thread)
// {
// 	if (number_thread == th1) {
// 		count1++;
// 	}

// 	if (number_thread == th2) {
// 		count2++;
// 	}

// 	if (number_thread == th3) {
// 		count3++;
// 	}

// 	if (number_thread == th4) {
// 		count4++;
// 	}
// }

void Dictionary::process(int number_of_thread, string name_file, int start, int finish, mutex *mtx)
{
	mtx->lock();
	// cout << "count_theard = " << count_theard << endl;
	count_theard++;
	cout << this_thread::get_id() << endl;
	cout << start << ' ' << finish << endl;

	ifstream in(name_file.c_str());
	if (!in.is_open()) {
		cout << "Can't open file\n";
		return;
	}

	string key;
	string value;

	int tmp = 0;

	for (; tmp < start; tmp++) {
		getline(in, key);
	}

	cout << "ok passed by the word thread: " << this_thread::get_id() << endl;
	mtx->unlock();

	while (start != finish) {
		getline(in, key, ' ');
		getline(in, value);

		mtx->lock();
		data_thread[number_of_thread].AddNode(key, value);
		// compute_count(this_thread::get_id());
		// add_count_words();
		start++;
		mtx->unlock();
	}

	in.close();
	// this_thread::sleep_for(chrono::milliseconds(500));
}

void Dictionary::readFile(string name_file)
{
	ifstream in(name_file.c_str());

	if (!in.is_open()) {
		cout << "Can't open file\n";
		return;
	}

	int num_words = 0;
	string tmp;
	while (!in.eof()) {
		getline(in, tmp);
		num_words++;
	}

	in.close();

	int diff = num_words / 4;

	mutex mtx;

	auto f1 = [&]{ process(0, name_file, 0, diff, &mtx); };
	auto f2 = [&]{ process(1, name_file, diff + 1, diff * 2, &mtx); };
	auto f3 = [&]{ process(2, name_file, (diff * 2) + 1, diff * 3, &mtx); };
	auto f4 = [&]{ process(3, name_file, (diff * 3) + 1, num_words, &mtx); };
	thread t1(f1);
	thread t2(f2);
	thread t3(f3);
	thread t4(f4);

	//if (count_theard == 4) {
	//}

	t1.join();
	t2.join();

	//if (count_theard == 4) {
	t3.join();
	t4.join();
	//}

	//th1 = t1.get_id();
	
	//th2 = t2.get_id();
	
	//th3 = t3.get_id();
	
	//th4 = t4.get_id();

	// cout << "th1 = " << th1 << endl;
	// cout << "th2 = " << th2 << endl;
	// cout << "th3 = " << th3 << endl;
	// cout << "th4 = " << th4 << endl;

	// cout << "count1 = " << count1 << endl;
	// cout << "count2 = " << count2 << endl;
	// cout << "count3 = " << count3 << endl;
	// cout << "count4 = " << count4 << endl;

	//merge();
	count_theard = 1;

	// cout << "sum = " << sum << endl;
	cout << "num_words = " << num_words << endl;

	// cout << "Read file is complete. " << count1 + count2 + count3 + count4 << " words.\n";
	cout << "Complete read file\n";
}

void Dictionary::translate(string str)
{
	cout << "Translate: " << str << endl;
	AVLTree::avltree *tmp = data.SearchNode(str);
	if (tmp == data.getNullNode() || tmp == NULL) {
		cout << "\tThere is no such word\n";
		return;
	}
	cout << "\t" << tmp->value << endl;
}

void Dictionary::merge()
{
	cout << "check:\n";
	cout << (data_thread[0].root->key < data_thread[1].root->key) << endl;
	cout << (data_thread[1].root->key < data_thread[2].root->key) << endl;
	cout << (data_thread[2].root->key < data_thread[3].root->key) << endl;
	//cout << (data_thread[3].root->key < data_thread[4].root->key) << endl;

	if (data.root == NULL) {
		data.root = data_thread[0].root;
		data_thread[0].root = NULL;
	}

	for (int i = 0; i < count_theard - 1; i++) {
		string new_key = data_thread[i].root->key;
		string left = new_key;
		string right = data_thread[i].root->key;

		while (!(new_key > left) && !(new_key < right)) {
			cout << "+q\n";
			new_key += "q";
		}

		AVLTree::avltree *new_root = data.CreateNode(new_key, "");

		new_root->left = data.root;
		new_root->right = data_thread[i + 1].root;

		data.root = new_root;
		data_thread[i + 1].root = NULL;
	}
}