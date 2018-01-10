#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <functional>
#include "dictionary.h"
using namespace std;

int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;

std::thread::id th1;
std::thread::id th2;
std::thread::id th3;
std::thread::id th4;

void compute_count(std::thread::id number_thread)
{
	if (number_thread == th1) {
		count1++;
	}

	if (number_thread == th2) {
		count2++;
	}

	if (number_thread == th3) {
		count3++;
	}

	if (number_thread == th4) {
		count4++;
	}
}

int count_theard = 1;

void Dictionary::process(string name_file, int start, int finish)
{
	if (count_theard == 1) {
		th1 = std::this_thread::get_id();
		count_theard++;
	}
	if (count_theard == 2) {
		 th2 = std::this_thread::get_id();
		count_theard++;
	}
	if (count_theard == 3) {
		th3 = std::this_thread::get_id();
		count_theard++;
	}
	if (count_theard == 4) {
		th4 = std::this_thread::get_id();
	}

	ifstream in(name_file.c_str());
	if (!in.is_open()) {
		cout << "Can't open file\n";
		return;
	}

	string key;
	string value;

	for (; start != 0; start--) {
		getline(in, key);
	}

	while (start != finish) {
		getline(in, key, ' ');
		getline(in, value);
		data.AddNode(key, value);
		compute_count(this_thread::get_id());
	}

	in.close();
}

void Dictionary::readFile(string name_file)
{
	ifstream in(name_file.c_str());
	if (!in.is_open()) {
		cout << "Can't open file\n";
		return;
	}

	// string key;
	// string value;
	// int i = 0;

	// int procent = 0;
	int num_words = 0;
	string tmp;
	while (!in.eof()) {
		getline(in, tmp);
		num_words++;
	}

	in.seekg(0);

	in.close();

	int diff = num_words / 4;

	// int count1 = 0;
	// int count2 = 0;
	// int count3 = 0;
	// int count4 = 0;

	// thread t1(name_file, ref(diff - diff), ref(diff));
	// thread t2(name_file, ref(diff), ref(diff * 2));
	// thread t3(name_file, ref(diff * 2), ref(diff * 3));
	// thread t4(name_file, ref(diff * 3), ref(diff * 4));

	// auto f = bind(Dictionary::process, placeholders::_1, placeholders::_2, placeholders::_3);

	thread t1(process, name_file, 0, diff);
	thread t2(process, name_file, diff, diff * 2);
	thread t3(process, name_file, diff * 2, diff * 3);
	thread t4(process, name_file, diff * 3, diff * 4);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	// while (t1.join() && t2.join() && t3.join() && t4.join()) {
	// 	cout << count1 << ' ' << count2  << ' ' << count3 << ' ' << count4;
	// 	cout << endl;
	// }

	/*while (!in.eof()) {
	

		getline(in, key, ' ');
		getline(in, value);
		data.AddNode(key, value);

		i++;
		procent = (100 * i) / num_words;
		cout << procent << "%";
		
		int count = (procent == 0) ? 1 : 0;
		int tmp = procent;
		while (tmp != 0) {
			count++;
			tmp /= 10;
		}
		count++;
		for (; count > 0; count--) {
			cout << "\b";
		}
	}*/

	cout << "Read file is complete. " << count1 + count2 + count3 + count4 << " words.\n";
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