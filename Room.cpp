#include "Room.h"
#include <iostream>

const RoomDef* RoomRegistry::getRoomDef(int id) const
{
	if (id >= 0 && id < rooms_.size()) return &rooms_[id];
	return nullptr;
}

void RoomRegistry::loadFromStream(std::istream& stream)
{
	rooms_.clear();

	int N = 0;
	stream >> N;

	RoomDef tempDef;

}
