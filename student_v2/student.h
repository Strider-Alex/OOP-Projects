#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <map>
using namespace std;
typedef map<string,double> ScoreMap;
class Student{
    public:
		Student();
		Student(string name);
        void addScore(string course, double score);
        double getAverage();
		double getScore(string course);
		string getName();
    private:
        string name;
        ScoreMap scores;
     	double total;
};
#endif
