#ifndef _DIARY_H_
#define _DIARY_H_
#include <string>
#include <map>
#include <ctime>
using namespace std;
typedef map<time_t, string> DiaryRec;
class Diary {
public:
	Diary();
	Diary(string fileName);
	~Diary();
	Diary(Diary& ref);
	void read();
	void add(time_t date, string text);
	void write();
	void show(time_t date);
	void list();
	void list(time_t startDate, time_t endDate);
	int remove(time_t date);
protected:
	DiaryRec diaries;
	string fileName;
};
#endif

