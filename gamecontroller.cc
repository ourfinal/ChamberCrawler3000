#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include "object.h"
#include "gamecontroller.h"
#include "quit.h"
using namespace std;

Game::GameController(){
	f = make_unique<Floor>(); //create a floor.
	selectPlayer();
}

GameController::selectPlayer() {
	while (true){
			cout << "Choose your player: (s, d, v, g, t)" << endl;
			char player;
			cin >> player;
			if (player == 's'){
				player = make_unique<Shade>();
			   	f.setPlayer(*player);
			} else if (player == 'd') {
				player = make_unique<Drow>();
				f.setPlayer(*player);
			} else if (player == 'v') {
				player = make_unique<Vampire>();
				f.setPlayer(*player);
			} else if (player == 'g') {
				player = make_unique<Goblin>();
			   	f.setPlayer(*player);
			} else if (player == 't') {
				player = make_unique<Troll>();
				f.setPlayer(*player);
			} else {continue;}
			break;
		}
}

void GameController::play(){
	//dlc
	//string bonus;
	//cin >> bonus;
	//switch 

	string cmd;
	while (true) {
		try {
			cin >> cmd;
		   	if (cmd[0] == 'u') {
				player.use(cmd);
			} else if (cmd[0] == 'a') {
				player.attack(cmd);
			} else if (cmd[0] == 'f') {
				f.stop();
			} else if (cmd[0] == 'r') {
				f.reset(new Floor());
				selectPlayer();
			} else if (cmd[0] == 'q') {
				throw Quit{};
			} else {
				player.move(cmd);
			}
		}
		catch (Quit& q) {
			f.reset(nullptr);
			player.reset(nullptr);
		}
	}
}
				

