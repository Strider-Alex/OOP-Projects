#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "map.h"
#include "cave.h"
#include "lobby.h"
#include "prison.h"

using namespace std;
Map::Map()
	:size(5),princessNum(1),monsterNum(1),equipNum(1) {}

Map::Map(int size,int princessNum,int monsterNum,int equipNum)
	:size(size),princessNum(princessNum),monsterNum(monsterNum),equipNum(equipNum) {}

Map::Map(Map& map)
	:size(map.size), princessNum(map.princessNum), monsterNum(map.monsterNum),
	equipNum( map.equipNum),startX(map.startX),startY(map.startY){
	//deep copy
	rooms.resize(map.rooms.size());
	string type;
	for (int i = 0;i < map.rooms.size();i++) {
		rooms[i].resize(map.rooms[0].size());
		for (int j = 0;j < map.rooms[0].size();j++) {
			if (map.rooms[i][j] == NULL) {
				rooms[i][j] = NULL;
			}
			else {
				type = map.rooms[i][j]->getType();
				if (type == "lobby") {
					rooms[i][j] = new Lobby();
				}
				else if (type == "cave") {
					rooms[i][j] = new Cave();
				}
				else if (type == "prison") {
					rooms[i][j] = new Prison();
				}
				*(rooms[i][j]) = *(map.rooms[i][j]);
			}
		}
	}
}

Map::~Map() {
	//free room pointers
	for (auto& row:rooms) {
		for (auto& roomPtr:row) {
			if (roomPtr != NULL){
				delete roomPtr;
			}
		}
	}
}

void Map::setBasis(int size,int princessNum,int monsterNum,int equipNum){
	this->size=size;
	this->princessNum=princessNum;
	this->monsterNum=monsterNum;
	this->equipNum=equipNum;
}



void Map::create() {
	int x, y;
	int roomCount, equipCount, princessCount, monsterCount;
	int type;
	const int delta[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	random_device rd;
	mt19937 mt(rd());
	vector<int> pos(2);
	vector<int> newPos(2);
	vector<vector<int> > posStack;
	vector<int> ways;
	vector<int> randInts;
	//count init
	roomCount = equipCount = princessCount = monsterCount = 0;

	//resize and init rooms
	rooms.resize(3*size);
	for (auto& row:rooms) {
		row.resize(3*size);
	}
	for (auto& row : rooms) {
		for (auto& roomPtr : row) {
			roomPtr = NULL;
		}
	}
	//create dice
	uniform_int_distribution<int> dice1(0, rooms.size() - 1);
	uniform_int_distribution<int> dice2(0, 1);
	uniform_int_distribution<int> dice3(0, 2);

	//set random start point
	startX = pos[0] = dice1(mt);
	startY = pos[1] = dice1(mt);
	rooms[pos[0]][pos[1]] = new Lobby();
	posStack.push_back(pos);

	//init random integers
	//0 = lobby,[1:monsterNum] = monster cave,[monsterNum+1,monsterNum+equipNum] =equip cave
	//[monsterNum+equipNum+1,size-2] = normal cave; size-1=prison
	for (int i = 1;i < size;i++) {
		randInts.push_back(i);
	}
	shuffle(randInts.begin(), randInts.end(), mt);

	//create random rooms
	while (randInts.size()) {
		pos = posStack.back();
		posStack.pop_back();
		for (int i = 0;i < 4;i++) {
			if (!randInts.size()) {
				break;
			}
			x = pos[0] + delta[i][0];
			y = pos[1] + delta[i][1];
			if (x >= 0 && y < rooms.size() && y >= 0 && y < rooms[0].size()) {
				if (rooms[x][y] == NULL) {
					//create new room
					if (dice2(mt) || posStack.size() == 1) {
						newPos = { x,y };
						posStack.push_back(newPos);
						type = randInts.back();
						randInts.pop_back();
						if (type >= 1 && type <= monsterNum) {
							rooms[x][y] = new Cave("monster");
						}
						else if (type >= monsterNum + 1 && type <= monsterNum + equipNum) {
							if (dice3(mt)) {
								rooms[x][y] = new Cave("torch");
							}
							else {
								rooms[x][y] = new Cave("sword");
							}
						}
						else if (type >= monsterNum + equipNum + 1 && type <= size - 2) {
							rooms[x][y] = new Cave("none");
						}
						else if (type == size - 1) {
							rooms[x][y] = new Prison();
						}
					}
				}
			}
		}

	}
	
}
void Map::getStart(int& x,int& y) {
	x = startX;
	y = startY;
}
void Map::getWays(int x, int y, vector<int>& ways) {
	int newX, newY;
	const int delta[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
	ways.clear(); // clear ways
	for (int i = 0;i < 4;i++) {
		newX = x + delta[i][0];
		newY = y + delta[i][1];
		if (newX >= 0 && newX < rooms.size() && newY >= 0 && newY < rooms.size()&&rooms[newX][newY]!=NULL) {
			ways.push_back(1);
		}
		else {
			ways.push_back(0);
		}
	}
}
Room* Map::getRoom(int x, int y){
	return rooms[x][y];
};
void Map::removeItem(int x, int y){
	rooms[x][y]->setItem("none");
}
void Map::setVisited(int x,int y){
	rooms[x][y]->setVisited(true);
}
