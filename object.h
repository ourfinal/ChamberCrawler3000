#ifndef __OBJECT_H_
#define __OBJECT_H_
#include <iostream>
#include <vector>
#include <utility>
#include "display.h"
#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
#include "floortile.h"
class Info;

class Object: public Subject, public Observer{
	FloorTile type;
	int x,y;
	public:
	Object();
	Info getInfo() const override;
	void notify(Subject &whoNotifyed) override;
	SubscriptionType subType() const override;
	void sethp(int n);
	void setatk(int n);
	void setdef(int n);


	virtual void move(std::string direction);
	virtual void beAttackBy(Object &o);
	virtual void attack(std::string direction);
	virtual void hit(Object &o);
	virtual void use(std::string direction);
	virtual void apply();
};

#endif
