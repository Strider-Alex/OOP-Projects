#include "diary.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

Diary::Diary()
	:fileName("diaries.db"){
	read();
}
Diary::Diary(string fileName)
	:fileName(fileName){
	read();
}

Diary::~Diary(){}

Diary::Diary(Diary& ref)
	:fileName(ref.fileName),diaries(ref.diaries){}

void Diary::read() {
	fstream file(fileName,ios::in|ios::out);
	time_t date;
	string line;
	if (!file) {
		//cout << "Cannot open file!" << endl;
	}
	else {
		while (file >> date) {
			while (getline(file, line)) {
				if (line == "###") {
					break;
				}
				diaries[date] += line;
				diaries[date] += "\n";
			}
		}
	}
	file.close();
}

void Diary::add(time_t date, string text){
	diaries[date] = text;
}

void Diary::write() {
	ofstream file(fileName);
	for (DiaryRec::iterator i = diaries.begin();i != diaries.end();i++) {
		file << i->first;
		file << i->second;
		file << "###" << endl;
	}
	file.close();
}

void Diary::show(time_t date) {
	DiaryRec::iterator i = diaries.find(date);
	if(i == diaries.end()) {
		cout << "No diary found!" << endl;
		return;
	}
	cout << put_time(localtime(&(i->first)), "%Y-%m-%d");
	cout << i->second;
}

void Diary::list() {
	for (DiaryRec::iterator i = diaries.begin();i != diaries.end();i++) {
		cout << put_time(localtime(&(i->first)), "%Y-%m-%d")<< endl;
		//cout << i->second <<endl;
	}
}

void Diary::list(time_t startDate, time_t endDate) {
	for (DiaryRec::iterator i = diaries.begin();i != diaries.end();i++) {
		if (i->first >= startDate&&i->first <= endDate) {
			cout << put_time(localtime(&(i->first)), "%Y-%m-%d")<<endl;
			//cout << i->second << endl;
		}
	}
}

int Diary::remove(time_t date) {
	cout << date;
	if (diaries.find(date) == diaries.end()) {
		return -1;
	}
	else {
		diaries.erase(date);
		return 0;
	}
}

