#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H
#include "student.h"
#include <string>
#define MAX 10
using namespace std;
class Student_record {
    public:
        void init();
        void append(Student new_student);
        void show();
    private:
        int max[SCORECOUNT];
        int min[SCORECOUNT];
        int count;
        double total[SCORECOUNT];
        Student students[MAX];
};
#endif
