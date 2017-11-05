#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void Dictionary::readFile(string name_file)
{
	ifstream in(name_file.c_str());

	string key;
	string value;
	int i = 0;
	while (!in.eof()) {
		getline(in, key, ' ');
		getline(in, value);
		data.AddNode(key, value);
		i++;
	}
	cout << "Read file is complete. " << i << " words."
}

void Dictionary::translate(string str)
{
	cout << "Translate: " << str << endl;
	cout << data.SearchNode(key)->value << endl;
}