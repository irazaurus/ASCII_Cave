#pragma once
#include <vector>
#include <string>

enum Alignment
{
	GOOD,
	NEUTRAL,
	EVIL
};

struct NPCDef
{
	int id;
	std::string name;
	int damage;
	int hp;
	Alignment align;
	int gold;        // amount of gold after killing it
	std::vector<std::string> drawing;
};

class NPCRegister
{
private:
	std::vector<NPCDef> npc_;

public:
	NPCDef* getNPCDef(int id);
	NPCDef* getNPCDef(std::string name);
	void loadFromStream(std::istream& stream);
	void loadDrawFromStream(std::istream& stream);
	Alignment sToAlignment(std::string str);

	void draw(int id);
};