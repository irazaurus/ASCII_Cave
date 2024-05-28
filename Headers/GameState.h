#pragma once
#include <vector>
#include "../Headers/Engine.h"

class GameState
{
private:
	std::vector<int> rooms_;
	int currRoomId_;

public:
	void initGame();
	int incTrigger(int id);
	int getCurrTrigger(int id) const;
	void setCurrRoom(int newId);
	int getCurrRoom();
};
