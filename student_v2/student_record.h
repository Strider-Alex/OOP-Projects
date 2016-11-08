#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H
#include "student.h"
#include "course.h"
#include <string>
#include <vector>
using namespace std;
class Student_record {
    public:
        Student_record();
        void addStudent(string name, vector<double> &a);
        void show();
    private:
        vector<Student> students;
		CourseMap courses;
};
#endif
