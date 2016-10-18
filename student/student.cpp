#include "student.h"
#include <iostream>
#include <string>
using namespace std;
void Student::init(string in_name, int *in_score){
    int i;
    average=0;
    for(i=0;i < SCORECOUNT;i++){
        score[i] = in_score[i];
        average += in_score[i];
    }
    average /= SCORECOUNT;
    name = in_name;
}

int Student::get_score(int index){
    return score[index];
}

string Student::get_name(){
    return name;
}

double Student::get_avr(){
    return average;
}
void Student::show(){
    int i;
    cout << name << " ";
    for(i=0;i<SCORECOUNT;i++){
        cout << score[i] << " ";
    }
    cout << average << endl;
}
