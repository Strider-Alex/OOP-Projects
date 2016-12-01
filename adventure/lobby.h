#ifndef LOBBY_H
#define LOBBY_H
#include <string>
#include <vector>
#include "room.h"
using namespace std;
class Lobby : public Room {
public:
	Lobby();
	virtual ~Lobby();
	Lobby(Lobby& lobby);
	virtual string getType();
	virtual string getItem();
protected:
	string roomType;
};
#endif

