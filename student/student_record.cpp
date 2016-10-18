#include "student.h"
#include "student_record.h"
#include <iostream>
#include <string>
using namespace std;
void Student_record::init(){
    int i;
    for(i=0;i<SCORECOUNT;i++){
        max[i] = min[i] = -1;
        total[i]=0;
    }
    count = 0;
}

void Student_record::append(Student new_student){
    int i, score;
    students[count] = new_student;
    for(i=0;i<SCORECOUNT;i++){
        score = new_student.get_score(i);
        if(min[i]<0||min[i]>score){
            min[i] = score;
        }
        if(max[i]<0||max[i]<score){
            max[i] = score;
        }
        total[i] += score;
    }
    count++;
}

void Student_record::show(){
    int i;
    cout << "no name ";
    for(i=0;i<SCORECOUNT;i++){
        cout << "score" << i+1 << " ";
    }
    cout << "average" << endl;
    for (i=0;i<count;i++){
        cout << i+1 << " ";
        students[i].show();
    }
    cout << "min ";
    for(i=0;i<SCORECOUNT;i++){
        cout << min[i] << " ";
    }
    cout << endl;
    cout << "max ";
    for(i=0;i<SCORECOUNT;i++){
        cout << max[i] << " ";
    }
    cout << endl;
    cout << "average ";
    for(i=0;i<SCORECOUNT;i++){
        cout << total[i]/count << " ";
    }
    cout << endl;
}
