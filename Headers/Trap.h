#pragma once
#include <vector>
#include <iostream>
#include "../Headers/Engine.h"

enum TRAP_TYPE{SPIKE, TRAP};

struct TrapDef
{
	int id;
	int damage;
	TRAP_TYPE type;
};

class TrapTrigger : public Trigger {
private:
	int modification_;
public:
	void setMod(int mod);
	bool execute();
};

bool loadFromStream(std::istream& stream, TrapDef& itemDef);
 
TRAP_TYPE sToTrap(std::string str);