#include <iostream>
#include <fstream>
#include <string>
#include "dictionary.h"
#include <Windows.h>
#include <locale>
using namespace std;

string Dictionary::Utf8_to_cp1251(const char *str)
{
	string res;
	int result_u, result_c;

	result_u = MultiByteToWideChar(CP_UTF8, 0, str, -1, 0, 0);

	if (!result_u) {
		return 0;
	}

	wchar_t *ures = new wchar_t[result_u];

	if (!MultiByteToWideChar(CP_UTF8, 0, str, -1, ures, result_u))
	{
		delete[] ures;
		return 0;
	}

	result_c = WideCharToMultiByte(1251, 0, ures, -1, 0, 0, 0, 0);

	if (!result_c) {
		delete[] ures;
		return 0;
	}

	char *cres = new char[result_c];

	if (!WideCharToMultiByte(1251, 0, ures, -1, cres, result_c, 0, 0)) {
		delete[] cres;
		return 0;
	}
	delete[] ures;
	res.append(cres);
	delete[] cres;
	return res;
}

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
		key = Utf8_to_cp1251(key.c_str());
		getline(in, value);
		value = Utf8_to_cp1251(value.c_str());
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
	//data.PrintTree();
}

void Dictionary::translate(string str)
{
	str = Utf8_to_cp1251(str.c_str());
	cout << "Translate: " << str << endl;
	avltree *tmp = data.SearchNode(str);
	if (tmp == data.getNullNode() || tmp == NULL) {
		cout << "\tThere is no such word\n";
		return;
	}
	cout << "\t" << tmp->value << endl;
}