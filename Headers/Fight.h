#pragma once
#include "Engine.h"

class FightTrigger : public Trigger {
private:
	int hp1_, hp2_;
	int dmg1_, dmg2_;
public:
	TriggerType type() { return FIGHT; }
	void setSides(int hp1, int dmg1, int hp2, int dmg2);
	int gethp1();
	int gethp2();
	bool execute();
};
