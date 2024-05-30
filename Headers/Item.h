#pragma once
#include <string>
#include <iostream>

struct ItemDef {
	int id;
	std::string name, description;
	int trapMod, damageMod, hpMod;
	bool isUsable;
	bool isEquippable;
	bool equiped;
};

bool loadFromStream(std::istream& stream, ItemDef& itemDef);
