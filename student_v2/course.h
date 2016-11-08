#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <map>
#include <vector>
using namespace std;
class Course{
	public:
		Course();
		void addScore(double score);
		double getMax();
		double getMin();
		double getAverage();
	private:
		double total;
		double max;
		double min;
		int count;
};

typedef map<string,Course> CourseMap;
#endif
