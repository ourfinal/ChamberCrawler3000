#ifndef _GAME_H_
#define _GAME_H_

class Object;

class GameController{
	auto player;
	auto f;
	public:
	GameController();
	~GameController();

	void selectPlayer();
	void play();
};

#endif
