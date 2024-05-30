#include "../Headers/NPC.h"
#include <iostream>


Alignment sToAlignment(std::string str) {
	if (str == "GOOD") return GOOD;
	if (str == "EVIL") return EVIL;
	return NEUTRAL;
}

bool loadFromStream(std::istream& stream, NPCDef& itemDef) {
	std::string input;

	// id
	std::getline(stream, input);
	if (input.empty()) { return false; }
	itemDef.id = std::stoi(input);

	// name
	std::getline(stream, input);
	itemDef.name = input;

	// align
	std::getline(stream, input);
	itemDef.align = sToAlignment(input);

	// HP
	std::getline(stream, input);
	itemDef.hp = std::stoi(input);
	itemDef.maxHp = std::stoi(input);

	// ATK
	std::getline(stream, input);
	itemDef.damage = std::stoi(input);

	// item
	std::getline(stream, input);
	itemDef.item = std::stoi(input);
	return true;
}

void loadDrawFromStream(std::istream& stream, NPCDef* def) {
	std::string input;

	// drawing 1
	std::getline(stream, input);
	int j = 0;
	while (!input.empty())
	{
		def->drawing1[j] = input;
		j++;
		std::getline(stream, input);
	}

	// drawing 2
	std::getline(stream, input);
	j = 0;
	while (!input.empty()) {
		def->drawing2[j] = input;
		j++;
		std::getline(stream, input);
	}
}
