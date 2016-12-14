#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
#include <locale>
#include "diary.h"
using namespace std;

int main() {
	string line,  text;
	time_t date;
	tm dateBreak = {};
	Diary diary("diaries.db");
	cout << "Enter date(YYYY-MM-DD): ";
	cin >> get_time(&dateBreak, "%Y-%m-%d");
	date = mktime(&dateBreak);
	if (date < 0) {
		cout << "Invalid input pattern!" << endl;
		return -1;
	}
	cout << "Enter text:" << endl;
	while (getline(cin, line)) {
		if (line == ".") {
			break;
		}
		text += line;
		text += "\n";
	}
	diary.add(date, text);
	diary.write();
}



