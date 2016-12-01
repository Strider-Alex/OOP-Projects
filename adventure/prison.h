#ifndef PRISON_H
#define PRISON_H
#include <string>
#include <vector>
#include "room.h"
using namespace std;
class Prison : public Room {
public:
	Prison();
	virtual ~Prison();
	Prison(Prison& prison);
	virtual string getItem();
	virtual string getType();
	virtual void setItem(string item);
protected:
	string roomType;
	string item;
};
#endif
