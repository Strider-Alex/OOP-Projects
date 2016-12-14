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
	int result;
	string line;
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
	diary.show(date);
	return 0;
}
