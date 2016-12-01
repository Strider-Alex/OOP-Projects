#include <string>
#include <vector>
#include <iostream>
#include "game.h"
Game::Game()
	:level(1),isPrincessSaved(false){}

Game::~Game(){}

Game::Game(Game& game)
	:level(game.level),map(game.map),player(game.player),isPrincessSaved(game.isPrincessSaved){}

void Game::setLevel(int level){
	this->level=level;
}

void Game::create(){
	switch(level){
		case 2:
			map.setBasis(10,1,3,2);break;
		case 3:
			map.setBasis(15,1,5,3);break;
	}
	map.create();
}

void speak(string line){
	cout << line << endl;
	cin.get();
}

void speakType(string roomType) {
	cout << "You push the door and enter the room... This room seems to be a " << roomType << "." << endl;
	cin.get();
}
void Game::play(){
	int level;
	int count;
	string equip;
	string item;
	Room* roomPtr;
	vector<int> ways;
	string next;
	string exit;
	string roomType;
	int x, y;
	int nextX, nextY;

	//creat game
	cout << "Choose the level:" << endl <<"1.Easy 2.Normal 3.Hard" << endl;
	do{cin >> level;}while(level!=1&&level!=2&&level!=3);
	cout << "Dungeon generating..." << endl;
	setLevel(level);
	create();
	map.getStart(x, y);//get init position
	player.setPosition(x, y);

	//play game
	cin.get();
	speak("Hello, you brave warrior! You must save the beatiful princess in this dungeon!");
	speak("But this is a dangerous trip. Evil monsters are hidden in the darkness...");
	speak("Oh, don't be so nervous. You may find something to protect yourself in the dungeon as well.");
	speak("Game start!");
	while(true){
		player.getPosition(x, y);
		equip = player.getEquip();
		roomPtr = map.getRoom(x, y);
		item = roomPtr->getItem();
		roomType = roomPtr->getType();
		//check if player win
		if (roomType == "lobby"&&isPrincessSaved) {
			speak("It's a long trip indead. Both of you and the princess are so tired");
			speak("But it dosen't matter, because you arrive the lobby again. You have taken her out.");
			break;//player win
		}
		speakType(roomType);// tell the type of room
		//deal with item
		if(item=="none"){
			speak("It is empty and quiet. Only winds blow from nowhere."); 
		}
		else if(item=="princess"){
			speak("This room is empty and quiet. Only winds blow from nowhere.");
			speak("You are thirsty and tired...");
			speak("But wait! You suddenly saw lady standing the corner.");
			speak("She's exhausted, yet young and beautiful. No doubt she is the princess!");
			if(level==3){
				speak("You rush to her with excitement. But suddenly a monster show up in the darkness");
				if(equip=="sword"){
					speak("Luckily you have the sword! You kill the monster and hold the lovely hand of the princess");
				}
				else{
					speak("No! You have nothing to protect you and are killed by the Monster, lying beside the feet of the princess");
					player.setDead(true);
					break;//player dead
				}
			}
			speak("Now...it's time to take her back.");
			isPrincessSaved = true;//set princess saved
		}
		else if(item=="monster"){
			speak("A giant fiece monster is standing in front of you!");
			if(equip=="sword"){
				speak("Luckily you've got a sword. You kill the monster with bravery, but your sword is broken in the battle.");
				player.setEquip("none");
			}
			else{
				speak("You have nothing to protect yourself and is killed by the monster.");
				player.setDead(true);
				break;//player dead
			}
		}
		else if(item=="sword"){
			if(equip!="none"){
				speak("At the center of the room lies a sword! You throw your equipment away and pick up the sword");
			}
			else{
				speak("At the center of the room lies a sword! You pick it up without hesitation");
			}
			player.setEquip("sword");
		}
		else if(item=="torch"){
			if(equip=="none"){
				speak("The room seems to be empty. But you carefully find a old torch on a skeleton on the floor.");
				player.setEquip("torch");
			}
			else if(equip=="torch"){
				speak("You find another old torch in this room. Ancient magic is awoken and the two torches are turned into a shining sword!");
				player.setEquip("sword");
			}
			else if(equip=="sword"){
				speak("With care you find a torch in this room and delightedly pick it up. But later you find that  you've lost your sword.");
				player.setEquip("torch");
			}
		}
		map.removeItem(x ,y);
		//deal with ways
		map.getWays(x, y, ways);
		bool isOnlyWay;//record if there is only one way so we do not print "and"
		while(true){
			count = 0;
			isOnlyWay = true;
			for(auto& way:ways){
				if(way>0){
					count++;
				}
			}
			cout << "There are " << count <<" exits as: ";
			for(int i=0;i<ways.size();i++){
				if(ways[i]>0){
					switch(i){
						case 0:
							exit="west";break;
						case 1:
							exit="up";break;
						case 2:
							exit="east";break;
						case 3:
							exit="down";break;
					}
					if(count==1){
						if (!isOnlyWay) {
							cout << "and ";
						}
						cout << exit << "." << endl;	
					}
					else{
						cout << exit << ", ";
					}
					count--;
					isOnlyWay = false;
				}
			}
		
			cout << "Enter your command(go where): ";
			while(true){
				cin >> next >> next;
				if(next=="west"&&ways[0]>0){
					nextX = x - 1;
					nextY = y;
					break;
				}
				else if(next=="up"&&ways[1]>0){
					nextX = x;
					nextY = y + 1;
					break;
				}
				else if(next=="east"&&ways[2]>0){
					nextX = x + 1;
					nextY = y;;
					break;
				}
				else if(next=="down"&&ways[3]>0){
					nextX = x;
					nextY = y - 1;
					break;
				}
				cout << "Don't know what to do." << endl;
			}
			cin.get();
			equip = player.getEquip();
			if(equip == "torch"){
				cout << "Do you want to use your torch to lead the way?" << endl;
				cout << "Enter your command(yes or no):";
				while(true){
					cin >> next;
					if(next=="yes"){
						roomPtr = map.getRoom(nextX,nextY);
						if(roomPtr -> getItem()=="monster"){
							cout << "The torch light shows that room is dangerous. ";
						}
						else{
							cout << "The torch light shows that room is safe. ";
						}
						cout << "Your torch is consumed. You step back and reconsider." << endl;
						player.setEquip("none");
						break;
					}
					else if(next=="no"){
						break;
					}
					cout << "Don't know what to do." <<endl;
				}
				if(next=="yes"){
					continue; // reconsider
				}
				cin.get();
			}
			player.setPosition(nextX,nextY); // move on
			break;
		}

	}
	if (player.isDead()) {
		speak("You died on the journey as many other warriors. The dungeon is still waiting for the true hero to come.");
		speak("GAME OVER");
	}
	else {
		speak("You saved the princess! You were rewarded by the king and honored by all people in this kingdom.");
		if (level == 3) {
			speak("Most importantly, the beatiful and noble princess married you as a tender wife. Your legend will be remembered by the history");
		}
		speak("YOU WIN!");
	}
}
