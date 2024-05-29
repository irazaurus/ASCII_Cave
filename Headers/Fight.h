#pragma once
#include "Engine.h"

class FightTrigger : public Trigger
{
public:
	TriggerType type() { return FIGHT; }
	bool execute();
};
