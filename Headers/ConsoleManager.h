#pragma once
#include <string>
#include <vector>
#include "CommandManager.h"

class ConsoleManager
{
public:
	void gameStart();
	std::string getChoice(CommandManager& manager);
	void goTo(CommandManager& manager, std::vector<std::string>* options);
	int getNum(CommandManager& manager);
};