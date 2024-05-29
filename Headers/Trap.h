#pragma once
#include <vector>
#include <iostream>
#include "../Headers/Engine.h"

enum TrapType { SPIKE, MANTRAP };

struct TrapDef
{
	int id;
	int damage;
	TrapType type;
};

class TrapTrigger : public Trigger {
private:
	int modification_;
public:
	TriggerType type() { return TRAP; }
	void setMod(int& mod);
	bool execute();
};

bool loadFromStream(std::istream& stream, TrapDef& itemDef);
 
TrapType sToTrap(std::string str);