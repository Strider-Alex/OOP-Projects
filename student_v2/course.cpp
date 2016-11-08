#include <string>
#include "course.h"
using namespace std;

Course::Course(){
	count = total = 0;
	min = max = -1;// set -1 as the sentinel
}

void Course::addScore(double score){
	total+=score;
	count++;
	if(min<0||min>score){
		min = score;
	}
	if(max<0||max<score){
		max = score;
	}
}

double Course::getMax(){
	return max;
}
						         
double Course::getMin(){
	return min;
}

double Course::getAverage(){
	//check if count is 0
	if(count){
		return total/count;
	}
	else {
		return 0;
	}
}

