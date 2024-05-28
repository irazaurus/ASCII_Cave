#include "../Headers/NPC.h"
#include <iostream>
#include <cassert>


Alignment sToAlignment(std::string str)
{
	if (str == "GOOD") return GOOD;
	if (str == "EVIL") return EVIL;
	return NEUTRAL;
}

bool loadFromStream(std::istream& stream, NPCDef& itemDef)
{
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

	// ATK
	std::getline(stream, input);
	itemDef.damage = std::stoi(input);

	// GOLD
	std::getline(stream, input);
	itemDef.gold = std::stoi(input);
	return true;
}

//void NPCRegister::loadDrawFromStream(std::istream& stream)
//{
//	// TODO fix unicode reading
//
//	int n = 0;
//	stream >> n;
//	std::string input;
//	std::getline(stream, input);
//
//	for (size_t i = 0; i < n; i++)
//	{
//		// id
//		int id;
//		stream >> id;
//		std::getline(stream, input);
//
//		// drawing
//		while (!input.empty())
//		{
//			//npc_.at(id).drawing.push_back(input);
//			std::getline(stream, input);
//		}
//	}
//}
//
//void NPCRegister::draw(int id)
//{
//	assert(id >= 0 && id < npc_.size());
//	for (size_t i = 0; i < npc_[id].drawing.size(); i++)
//	{
//		std::cout << npc_[id].drawing[i] << std::endl;
//	}
//}
