#include <iostream>
#include <string>
#include <sys/time.h>
#include "dictionary.h"
using namespace std;

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

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
	double t = 0;

	while (answer != "exit") {
		if (first) {
			// system("clear");
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
			t = wtime();
			dict.readFile(answer);
			t = wtime() - t;
			cout << "Time is " << t << endl;
			continue;
		}
		if (answer == "translate" || answer == "tr") {
			// system("clear");
			while (1) {
				cout << "\nWord: ";
				getline(cin, answer);
				if (answer == "exit") {
					break;
				}
				// system("clear");
				dict.translate(answer);
			}
			answer.clear();
			continue;
		}
	}
}