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

int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int sum = 0;

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

void add_count_words()
{
	sum++;
}

int count_theard = 1;

void Dictionary::process(string name_file, int start, int finish, mutex *mtx)
{
	mtx->lock();
	cout << "---------------------" << endl;
	cout << "count_theard = " << count_theard << endl;
	count_theard++;
	cout << this_thread::get_id() << endl;
	cout << start << ' ' << finish << endl;
	cout << "---------------------" << endl;
	mtx->unlock();

	ifstream in(name_file.c_str());
	if (!in.is_open()) {
		cout << "Can't open file\n";
		return;
	}

	string key;
	string value;

	int tmp = 0;

	for (; tmp < start; tmp++) {
		// cout << "..." << endl;
		getline(in, key);
	}

	mtx->lock();
	cout << "ok passed by the word thread: " << this_thread::get_id() << endl;
	mtx->unlock();

	// mutex mtx;
	this_thread::sleep_for(chrono::milliseconds(500));

	while (start != finish) {
		getline(in, key, ' ');
		getline(in, value);

		mtx->lock();
		data.AddNode(key, value);
		// compute_count(this_thread::get_id());
		add_count_words();
		start++;
		mtx->unlock();
		// int procent = (start * 100) / finish;
		// mtx->lock();
		// cout << "procent = ";
		// if (procent / 10 == 0) {
		// 	cout << "0";
		// }
		// cout << procent << "%";
		// cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b";	
		// mtx->unlock();
	}

	in.close();
	this_thread::sleep_for(chrono::milliseconds(500));
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

	mutex mtx;

	auto f1 = [&]{process(name_file, 0, diff, &mtx);};
	auto f2 = [&]{process(name_file, diff + 1, diff * 2, &mtx);};
	auto f3 = [&]{process(name_file, (diff * 2) + 1, diff * 3, &mtx);};
	auto f4 = [&]{process(name_file, (diff * 3) + 1, num_words, &mtx);};

	thread t1(f1);
	th1 = t1.get_id();
	usleep(500);
	thread t2(f2);
	th2 = t2.get_id();
	usleep(500);
	thread t3(f3);
	th3 = t3.get_id();
	usleep(500);
	thread t4(f4);
	th4 = t4.get_id();

	// thread t1(process, name_file, 0, diff);
	// thread t2(process, name_file, diff, diff * 2);
	// thread t3(process, name_file, diff * 2, diff * 3);
	// thread t4(process, name_file, diff * 3, diff * 4);

	// int sum = count1 + count2 + count3 + count4;
	// while (sum < num_words) {
	// 	cout << sum << endl;
	// 	sum = count1 + count2 + count3 + count4;
	// }

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	count_theard = 1;

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

	cout << "th1 = " << th1 << endl;
	cout << "th2 = " << th2 << endl;
	cout << "th3 = " << th3 << endl;
	cout << "th4 = " << th4 << endl;

	cout << "count1 = " << count1 << endl;
	cout << "count2 = " << count2 << endl;
	cout << "count3 = " << count3 << endl;
	cout << "count4 = " << count4 << endl;

	// while (sum != num_words) {
	// 	int procent = (sum * 100) / num_words;
	// 	cout << procent << "%";
	// 	if (procent / 10 != 0) {
	// 		cout << "\b";
	// 	}
	// 	cout << "\b\b";
	// }

	// cout << "\b" << endl;

	cout << "sum = " << sum << endl;
	cout << "num_words = " << num_words << endl;

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