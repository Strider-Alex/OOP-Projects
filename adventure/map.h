#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include "room.h"
class Map{
	public:
		Map();
		Map(int size,int princessNum,int monsterNum,int equipNum);
		virtual ~Map();
		Map(Map& map);
		virtual void setBasis(int size, int princessNum,int monsterNum, int equipNum);
		virtual void create();
		virtual Room* getRoom(int x, int y);
		virtual void getStart(int& x, int& y);
		virtual void removeItem(int x, int y);
		virtual void setVisited(int x, int y);
		virtual void getWays(int x, int y, vector<int>& ways);
	private:
		int size;
		int princessNum;
		int monsterNum;
		int equipNum;
		int startX;
		int startY;
		vector<vector<Room*> > rooms;
};
#endif
