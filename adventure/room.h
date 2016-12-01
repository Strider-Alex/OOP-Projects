#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
using namespace std;
class Room{
	public:
		Room();
		Room(Room& room);
		virtual ~Room();
		virtual bool isVisited();
		virtual void setVisited(bool visited);
		virtual void setItem(string item);
		virtual string getItem();
		virtual string getType();
	protected:
		bool visited;
};
#endif
