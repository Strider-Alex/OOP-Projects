#include <string>
#ifndef STUDENT_H
#define STUDENT_H
#define SCORECOUNT 3 //refers to the number of the input score
using namespace std;
class Student{
    public:
        void init(string in_name,int *in_score);
        int get_score(int index);
        string get_name();
        double get_avr();
        void show();
    private:
        string name;
        int score[SCORECOUNT];
        double average;
};
#endif
