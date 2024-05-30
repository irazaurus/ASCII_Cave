#pragma once
#include <string>
#include <vector>
#include "CommandManager.h"
#include "Player.h"
#include "NPC.h"

class ConsoleManager
{
public:
	void gameStart();
	void writeToCoord(int x, int y, std::string s);
	std::string getChoice(CommandManager& manager);
	void goTo(CommandManager& manager, std::vector<std::string>* options);
	void fightMenu(Player* player, NPCDef* monster);
	int getNum(CommandManager& manager);
};