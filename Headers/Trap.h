#pragma once
#include <vector>
#include <iostream>

struct TrapDef
{
	int id;
	int damage;
};

class TrapRegistry
{
public:
	TrapDef* getTrapDef(int id);
	void loadFromStream(std::istream& stream);

private:
	std::vector<TrapDef> traps_;
};
