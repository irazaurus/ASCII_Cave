#include "../Headers/Item.h"

bool loadFromStream(std::istream& stream, ItemDef& itemDef)
{
	std::string input;
	int inp;
	// id
	std::getline(stream, input);
	if (input.empty()) { return false; }
	itemDef.id = std::stoi(input);

	// name
	std::getline(stream, input);
	itemDef.name = input;

	// description
	std::getline(stream, input);
	itemDef.description = input;

	// trap mod
	stream >> inp;
	itemDef.trapMod = inp;
	// damage mod
	stream >> inp;
	itemDef.damageMod = inp;
	// hp mod
	stream >> inp;
	itemDef.hpMod = inp;

	// is usable
	stream >> inp;
	itemDef.isUsable = inp;
	// is equippable
	stream >> inp;
	itemDef.isEquippable = inp;

	return true;
}
