#pragma once
#include <vector>
#include <iostream>

struct RoomDef
{
	int id;
	std::vector<int> k; // connected rooms
	int traps;
	int treasures;
	// monsters
};

class RoomRegistry
{
private:
	std::vector<RoomDef> rooms_;

public:
	const RoomDef* getRoomDef(int id) const;
	void loadFromStream(std::istream& stream);
};