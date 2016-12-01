#include "cave.h"
#include <string>
#include <vector>
using namespace std;

Cave::Cave()
	: Room(), roomType("cave"),item("none") {}

Cave::Cave(string item)
	: roomType("cave"), item(item) {}

Cave::~Cave() {}

Cave::Cave(Cave& cave)
	: Room(cave),item(cave.item),roomType(cave.roomType){}

void Cave::setItem(string item) {
	this->item = item;
}
string Cave::getItem() {
	return item;
}
string Cave::getType() {
	return roomType;
}