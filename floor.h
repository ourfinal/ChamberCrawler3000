#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include <string>
#include "object.h"
#include "display.h"

class Floor{
	std::vector<std::vector<Object>> board; //the board
	Display *d; //display
	int size;
	void clearFloor();
	public:	
	Floor();
	~Floor();
	
	void init(ifstream& file); // set up the board according to the given floor in the file.
	void setPlayer(std::string); // generate player.
	void setStairWay(); //generate stairway.
	void setPotion(); //generate potion
	void setTreasure(); //generate gold.
	void setEnemy(); //generate enemy.
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
