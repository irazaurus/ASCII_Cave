#include "../Headers/NPC.h"
#include <iostream>
#include <cassert>


Alignment NPCRegister::sToAlignment(std::string str)
{
	if (str == "GOOD") return GOOD;
	if (str == "EVIL") return EVIL;
	return NEUTRAL;
}

NPCDef* NPCRegister::getNPCDef(int id)
{
	if (id >= 0 && id < npc_.size()) return &npc_[id];
	return nullptr; // TODO обработать
}

void NPCRegister::loadFromStream(std::istream& stream)
{
	npc_.clear();

	int N = 0;
	stream >> N;

	std::string input;
	NPCDef firstDef;
	firstDef.id = 0;
	npc_.push_back(std::move(firstDef));

	for (size_t i = 0; i < N; i++)
	{
		NPCDef tempDef;

		// id
		std::getline(stream, input);
		if (input.empty()) { i--; continue; }
		tempDef.id = std::stoi(input);

		// name
		std::getline(stream, input);
		tempDef.name = input;

		// align
		std::getline(stream, input);
		tempDef.align = sToAlignment(input);

		// HP
		std::getline(stream, input);
		tempDef.hp = std::stoi(input);

		// ATK
		std::getline(stream, input);
		tempDef.damage = std::stoi(input);

		// GOLD
		std::getline(stream, input);
		tempDef.gold = std::stoi(input);

		npc_.push_back(std::move(tempDef));
	}
}

void NPCRegister::loadDrawFromStream(std::istream& stream)
{
	// TODO fix unicode reading

	int n = 0;
	stream >> n;
	std::string input;
	std::getline(stream, input);

	for (size_t i = 0; i < n; i++)
	{
		// id
		int id;
		stream >> id;
		std::getline(stream, input);

		// drawing
		while (!input.empty())
		{
			npc_.at(id).drawing.push_back(input);
			std::getline(stream, input);
		}
	}
}

void NPCRegister::draw(int id)
{
	assert(id >= 0 && id < npc_.size());
	for (size_t i = 0; i < npc_[id].drawing.size(); i++)
	{
		std::cout << npc_[id].drawing[i] << std::endl;
	}
}
