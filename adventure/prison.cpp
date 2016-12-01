#include "prison.h"
#include <string>
#include <vector>
using namespace std;

Prison::Prison()
	:Room(), roomType("prison"), item("princess") {}

Prison::Prison(Prison& prison)
	:Room(prison), roomType(prison.roomType), item(prison.item){}

Prison::~Prison() {}

void Prison::setItem(string item) {
	this->item = item;
}

string Prison::getItem() {
	return item;
}
string Prison::getType() {
	return roomType;
}