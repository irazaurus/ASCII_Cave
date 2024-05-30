#pragma once
#include <set>
#include <string>
#include "GameState.h"

enum Commands { EXIT, HELP, INVALID, ATTACK, GO, INVENTORY, USE, BUY };

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
	void inventory();
	void use();
	void invalid();
	void help();
};

Commands sToCommand(std::string s);
