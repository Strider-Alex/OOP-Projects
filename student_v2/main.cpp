#include<iostream>
#include<string>
#include<vector>
#include"student.h"
#include"student_record.h"
using namespace std;
int main(){
    string name;
    Student_record sr;
	string course;
	double score;
	vector<string> courses;
	vector<double>  scores;
	cout << "~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Hello! This is a program to record students' performance in exams."<<endl;
	cout << "~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "For each student, enter the name first. For each course he took, enter the couse name and the score."<<endl;
	cout << "Type # at the end of each student and ## at end of all input" << endl;
	cout << "Eg. Alex Math 5 English 5 #"<<endl;
	while(cin >> name){
		if(name == "##"){
			break;
		}
		courses.clear();
		scores.clear();
		while(cin >> course){
			if(course == "#"){
				break;
			}
			cin >> score;
			courses.push_back(course);
			scores.push_back(score);
		}
		cin.clear();
		sr.addStudent(name,courses,scores);//add student to record
	}
    sr.show();//show the whole record
}
