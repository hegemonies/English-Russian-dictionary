#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"
using namespace std;


void Dictionary::readFile(string name_file)
{
	ifstream in(name_file.c_str());
	if (!in.is_open()) {
		cout << "Can't open file\n";
		return;
	}

	string key;
	string value;
	int i = 0;

	int procent = 0;
	int num_words = 0;
	string tmp;
	while (!in.eof()) {
		getline(in, tmp);
		num_words++;
	}
	in.seekg(0);
	while (!in.eof()) {
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
	}

	cout << "Read file is complete. " << i << " words.\n";

	in.close();
	cout << "Complete read file\n";
}

void Dictionary::translate(string str)
{
	cout << "Translate: " << str << endl;
	avltree *tmp = data.SearchNode(str);
	if (tmp == data.getNullNode() || tmp == NULL) {
		cout << "\tThere is no such word\n";
		return;
	}
	cout << "\t" << tmp->value << endl;
}