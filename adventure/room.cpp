#include "room.h"
#include <string>
#include <vector>
using namespace std;

Room::Room() 
	:visited(false){}

Room::Room(Room& room) {
	visited = room.visited;
}

Room::~Room() {};

bool Room::isVisited(){
	return visited;
}

void Room::setVisited(bool visited){
	this->visited=visited;
}

void Room::setItem(string item){}

string Room::getItem() {
	return "none";
}

string Room::getType(){
	return "room";
}



