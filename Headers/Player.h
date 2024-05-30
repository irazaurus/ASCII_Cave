#pragma once
#include <vector>

class Player
{
private:
	std::vector<int> items_;

public:
	int hp = 30;
	int maxhp = 30;
	int damage = 3;
	int trap_mod_ = 0; // bonus that helps escaping traps
	int dmg_mod = 2;   // damage bonus
	int armor = 0;     // protection bonus
	std::vector<int>* getItems();
};

inline std::vector<int>* Player::getItems()
{
	return &items_;
}