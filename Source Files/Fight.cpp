#include "../Headers/Fight.h"
#include <windows.h>

void FightTrigger::setSides(int hp1, int dmg1, int hp2, int dmg2) {
	hp1_ = hp1;
	hp2_ = hp2;
	dmg1_ = dmg1;
	dmg2_ = dmg2;
}

int FightTrigger::gethp1() {
	return hp1_;
}

int FightTrigger::gethp2() {
	return hp2_;
}

bool FightTrigger::execute() {
	hp1_ -= dmg2_;
	hp2_ -= dmg1_;
	if (hp1_ == 0) return false;
	return true;
}
