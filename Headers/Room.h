#pragma once
#include <vector>
#include <iostream>
#include <stack>
#include <memory>
#include "../Headers/Engine.h"
#include "../Headers/Trap.h"
#include "../Headers/Fight.h"

struct RoomDef
{
	int id;
	std::string description;
	std::unique_ptr<Trigger> triggers[10];
	std::vector<int> k; // connected rooms
	std::vector<std::string> npc;
	std::stack<int> traps;
	};

bool loadFromStream(std::istream& stream, RoomDef& itemDef);