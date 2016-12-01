#ifndef CAVE_H
#define CAVE_H
#include <string>
#include <vector>
#include "room.h"
using namespace std;
class Cave : public Room {
public:
	Cave();
	Cave(string item);
	Cave(Cave& cave);
	virtual ~Cave();
	virtual void setItem(string item);
	virtual string getItem();
	virtual string getType();
protected:
	string roomType;
	string item;
};
#endif


