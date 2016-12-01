#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
using namespace std;
class Player{
	public:
		Player();
		Player(int position);
		Player(Player& player);
		virtual ~Player();
		virtual void setPosition(int x, int y);
		virtual void getPosition(int& x, int& y);
		virtual void setEquip(string equip);
		virtual string getEquip();
		virtual bool isDead();
		virtual void setDead(bool dead);
	protected:
		int x;
		int y;
		string equip;
		bool dead;
};
#endif
