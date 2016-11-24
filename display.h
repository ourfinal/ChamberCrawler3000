#ifndef __DISPLAY_H_
#define __DISPLAY_H_
#include <iostream>
#include <vector>
#include "observer.h"
class Object;

class Display: public Observer {
	std::vector<std::vector<char>> theDisplay;
	const int size;
	public:
	Display(int n);
	
	void notify(Subject &whoNotify) override;
	SubscriptionType subType() const override;

	~Display();

	friend std::ostream &operator<<(std::ostream &out, const Display &td);
};

#endif
