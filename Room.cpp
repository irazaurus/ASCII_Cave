#include "Room.h"
#include <iostream>
#include <string>

const RoomDef* RoomRegistry::getRoomDef(int id) const
{
	if (id >= 0 && id < rooms_.size()) return &rooms_[id];
	return nullptr; // TODO обработать
}

void RoomRegistry::loadFromStream(std::istream& stream)
{
	rooms_.clear();

	int N = 0;
	stream >> N;

	std::string input;

	for (size_t i = 0; i < N; i++)
	{
		RoomDef tempDef;
		int inp;
		// id
		std::getline(stream, input);
		if (input.empty()) { i--; continue; }
		tempDef.id = std::stoi(input);

		// connected rooms k
		std::getline(stream, input);
		for (int k = std::stoi(input); k > 0; k--)
		{
			stream >> inp;
			tempDef.k.push_back(std::move(inp));
		}

		// traps
		stream >> inp;
		tempDef.traps = inp;

		// treasures
		stream >> inp;
		tempDef.treasures = inp;

		rooms_.push_back(std::move(tempDef));
	}
}
