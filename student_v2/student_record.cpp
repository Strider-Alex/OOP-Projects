#include "student.h"
#include "course.h"
#include "student_record.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#define SHORTSPACE 4
#define LONGSPACE 8
using namespace std;
Student_record::Student_record(){}

void Student_record::addStudent(string name, vector<double> &a){
    vector<double>::iterator i;
	Student student(name);
	stringstream ss;
	string course;
	for(i=a.begin();i<a.end();i++){
		ss.clear();
		ss << "Score" << i-a.begin()+1;
		ss >> course;
		student.addScore(course,*i);//update student
		courses[course].addScore(*i);//update courses
	}
	students.push_back(student);
}

void Student_record::show(){
	CourseMap::iterator i;
	cout << left;
    cout << setw(SHORTSPACE)<<"no"<<setw(LONGSPACE)<<"name";
    for(i=courses.begin();i!=courses.end();i++){
        cout << setw(LONGSPACE)<<i->first; // print out all course names
    }
    cout << setw(LONGSPACE)<<"average" << endl;

    for (vector<Student>::iterator j=students.begin();j<students.end();j++){
        cout <<setw(SHORTSPACE)<< j-students.begin()+1; //print index of student
        cout <<setw(LONGSPACE)<< j->getName(); //print name of student
		for(i=courses.begin();i!=courses.end();i++){
			cout <<setw(LONGSPACE) <<j->getScore(i->first); //pirnt score of student
		}
		cout <<setw(LONGSPACE)<<j->getAverage()<<endl; //printf average score
    }
    cout << setw(SHORTSPACE+LONGSPACE)<<"min";
    for(i=courses.begin();i!=courses.end();i++){
        cout << setw(LONGSPACE) << i->second.getMin();
    }
    cout << endl;
    cout << setw(SHORTSPACE+LONGSPACE)<<"max";
    for(i=courses.begin();i!=courses.end();i++){
	    cout << setw(LONGSPACE) << i->second.getMax();
	}
    cout << endl;
    cout << setw(SHORTSPACE+LONGSPACE)<<"average";
	for(i=courses.begin();i!=courses.end();i++){
        cout << setw(LONGSPACE) << i->second.getAverage();
	}
	 cout << endl;
}

