#include <iostream>
#include <string>
#include "dictionary.h"
using namespace std;

void help() {
	cout << "\tCommand Set:\n";
	cout << "\tload file : load\n";
	cout << "\ttranslate : translate or tr\n";
	cout << "\texit : exit\n";
}

int main(void)
{
	Dictionary dict;
	string answer;
	bool first = true;

	while (answer != "exit") {
		if (first) {
			system("clear");
			help();
			first = false;
		}
		cout << "cmd: ";
		getline(cin, answer);
		if (answer == "help") {
			help();
			continue;
		}
		if (answer == "load") {
			cout << "Name file: ";
			getline(cin, answer);
			dict.readFile(answer);
			continue;
		}
		if (answer == "translate" || answer == "tr") {
			system("clear");
			while (1) {
				cout << "\nWord: ";
				getline(cin, answer);
				if (answer == "exit") {
					break;
				}
				system("clear");
				dict.translate(answer);
			}
			answer.clear();
			continue;
		}
	}
}