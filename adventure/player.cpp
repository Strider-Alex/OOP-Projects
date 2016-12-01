#include <string>
#include "player.h"
using namespace std;
Player::Player()
	:x(0),y(0),equip("none"),dead(false){}

Player::Player(int position)
	:x(0), y(0),equip("none"),dead(false){}

Player::Player(Player& player)
	:x(player.x), y(player.y), equip(player.equip), dead(player.dead) {}

Player::~Player(){}

void Player::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}

void Player::getPosition(int&x , int& y){
	x = this->x;
	y = this->y;
}

string Player::getEquip(){
	return equip;
}

void Player::setEquip(string equip){
	this->equip = equip;
}

bool Player::isDead(){
	return dead;
}

void Player::setDead(bool dead){
	this->dead = dead;
}
