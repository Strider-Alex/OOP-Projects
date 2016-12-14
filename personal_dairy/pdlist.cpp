#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
#include <locale>
#include "diary.h"
using namespace std;

int main(int argc, char * argv[]) {
	tm startDateBreak = {}, endDateBreak = {};
	time_t startDate, endDate;
	Diary diary("diaries.db");
	if (argc == 1) {
		diary.list();
	}
	else if(argc ==3){
		stringstream ssStart(argv[1]);
		stringstream ssEnd(argv[2]);
		
		ssStart >> get_time(&startDateBreak, "%Y-%m-%d");
		ssEnd >> get_time(&endDateBreak, "%Y-%m-%d");
		startDate = mktime(&startDateBreak);
		endDate = mktime(&endDateBreak);
		if (startDate < 0 || endDate < 0) {
			cout << "Invalid parameter!" << endl;
			return -1;
		}
		diary.list(startDate, endDate);
	}
	else {
		cout << "Invalid parameter number!(0 or 2 is needed)" << endl;
		return -1;
	}
	return 0;
}



