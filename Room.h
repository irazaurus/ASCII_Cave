#pragma once
#include <vector>

struct RoomDef
{
	int id;
	std::vector<int> k; // connected rooms
	int traps[10];
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