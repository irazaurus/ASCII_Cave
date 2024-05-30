#pragma once
#include <vector>
#include <string>

enum Alignment {
	GOOD,
	NEUTRAL,
	EVIL
};

struct NPCDef {
	int id;
	std::string name;
	int damage;
	int hp, maxHp;
	Alignment align;
	int item;        // item that drops after killing
	std::string drawing1[20], drawing2[20];
};

bool loadFromStream(std::istream& stream, NPCDef& itemDef);
Alignment sToAlignment(std::string str);

void loadDrawFromStream(std::istream& stream, NPCDef* def);