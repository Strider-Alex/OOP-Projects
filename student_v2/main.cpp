#include<iostream>
#include<string>
#include<vector>
#include"student.h"
#include"student_record.h"
using namespace std;
int main(){
    string name;
    Student_record sr;
	double score;
	vector<double> a;
	while(cin >> name){
		a.clear();
		while(cin >> score){
			a.push_back(score);
		}
		cin.clear();
		sr.addStudent(name,a);//add student to record
	}
    sr.show();//show the whole record
}
