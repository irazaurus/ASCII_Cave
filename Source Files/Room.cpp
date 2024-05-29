#include "../Headers/Room.h"
#include <iostream>
#include <string>

bool loadFromStream(std::istream& stream, RoomDef& itemDef)
{
	std::string input;
	int inp;
	// id
	std::getline(stream, input);
	if (input.empty()) { return false; }
	itemDef.id = std::stoi(input);

	// description
	std::getline(stream, input);
	itemDef.description = input;

	// triggers
	stream >> inp;
	for (int k = 0; k < inp; k++)
	{
		stream >> input;
		itemDef.triggers[k] = std::unique_ptr<Trigger>(sToTrigger(input));
	}

	// connected rooms k
	stream >> input;
	for (int k = std::stoi(input); k > 0; k--)
	{
		stream >> inp;
		itemDef.k.push_back(std::move(inp));
	}

	// npc
	stream >> input;
	for (int k = std::stoi(input); k > 0; k--)
	{
		stream >> input;
		itemDef.npc.push_back(input);
	}

	// traps
	stream >> inp;
	for (int k = inp; k > 0; k--)
	{
		stream >> inp;
		itemDef.traps.push(inp);
	}

	return true;
}
