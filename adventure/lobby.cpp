#include "lobby.h"
#include <string>
#include <vector>
using namespace std;

Lobby::Lobby()
	:Room(), roomType("lobby") {}

Lobby::~Lobby(){}

Lobby::Lobby(Lobby& lobby)
	:roomType(lobby.roomType){}

string Lobby::getType() {
	return roomType;
}

string Lobby::getItem() {
	return "none";
}