#include<iostream>
#include<string>
#include"student.h"
#include"student_record.h"
#define STUDENTCOUNT 10
using namespace std;
int main(){
    int i,j,score[SCORECOUNT];
    string name;
    Student s;
    Student_record sr;
    sr.init(); //student record initialize
    for(i=0;i<STUDENTCOUNT;i++){
        cin >> name;
        for (j=0;j<SCORECOUNT;j++){
            cin >> score[j];
        }
        s.init(name,score); //student initialize
        sr.append(s); //add student to the record
    }
    sr.show();//show the whole record
}
