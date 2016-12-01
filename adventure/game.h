#ifndef GAME_H
#define GAME_H
#include <string>
#include "map.h"
#include "room.h"
#include "player.h"
using namespace std;
class Game {
	public:
		Game();
		virtual ~Game();
		Game(Game& game);
		virtual void setLevel(int level);
		virtual void create();
		virtual void play();
	protected:
		int level;
		Map map;
		Player player;
		bool isPrincessSaved;
};
#endif
