#pragma once
#include <vector>

class Player
{
private:
	int trap_mod_ = 0; // bonus that helps escaping traps
	std::vector<int> items_;

public:
	int hp = 30;
	int damage = 5;
	int* getTrapMod();
};
