#pragma once
#include <set>
#include <string>
#include "GameState.h"

enum Commands { EXIT, HELP, INVALID, ATTACK, GO, INVENTORY, USE, EQUIP, BUY };

class CommandManager
{
private:
	std::set<Commands> validCommands_;
	GameState* state_;
	Commands last_;

public:
	void resetValidCommands();
	void setLast(Commands c);
	void setState(GameState* state);

	void manage(std::string input);
	void executeTriggers();
	bool go(int i);
	void exit();
	void invalid();
	bool fight();
	void help();
};

Commands sToCommand(std::string s);