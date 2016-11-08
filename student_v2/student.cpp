#include "student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(){
	name = "";
	total = 0;

}

Student::Student(string in_name){
	name = in_name;
	total = 0;
}

void Student::addScore(string course, double score){
	// if course already exist
	if(scores.count(course)){
		total = total - scores[course] + score;
	}
	else{
		total+=score;
	}
	scores[course]=score;
}

double Student::getAverage(){
	//check if size of map = 0
	if(scores.size()){
		return total/scores.size();
	}
	else{
		return 0;
	}
}

double Student::getScore(string course){
	// if course already exist
	if(scores.count(course)){
		return scores[course];
	}
	else{
		return -1; 
	}
}

string Student::getName(){
	return name;
}
