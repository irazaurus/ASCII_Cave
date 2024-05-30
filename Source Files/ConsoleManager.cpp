#include "../Headers/ConsoleManager.h"
#include <iostream>
#include <Windows.h>

void ConsoleManager::gameStart() {
	std::cout << "Welcome to the ASCII CAVE!\n"
			  << "The King chose you to fight with a dragon....\n"
			  << "(Press Enter...) ";
	std::cin.ignore();
	//TODO dialog with a King
}

void ConsoleManager::writeToCoord(int x, int y, std::string s) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD written = 0;
	COORD coord = {x, y};
	WriteConsoleOutputCharacter(hout, s.c_str(), s.length(), coord, &written);
}

std::string ConsoleManager::getChoice(CommandManager& manager) {
	std::cout << "> ";
	std::string inp;
	std::cin >> inp;
	manager.manage(inp);
	return inp;
}

void ConsoleManager::goTo(CommandManager& manager, std::vector<std::string>* options) {
	std::cout << "Where to go?" << std::endl;

	for (size_t i = 0; i < options->size(); i++) {
		std::cout << options->at(i) << std::endl;
	}

	int inp = getNum(manager);
	while (!manager.go(inp)) {
		if (inp == -1) return;
		inp = getNum(manager);
	}

	manager.setLast(GO);
}

void ConsoleManager::fightMenu(Player* player, NPCDef* monster) {
	system("cls");
	writeToCoord(10, 0, "You see a " + monster->name + "!");

	// monster drawing
	for (int i = 0; i < 20; i++)
		writeToCoord(60, 4 + i, monster->drawing1[i]);

	// parameters
	writeToCoord(60, 2, monster->name + "'s HP: " + std::to_string(monster->hp));
	writeToCoord(60, 3, "Your HP: " + std::to_string(player->hp));
}

bool isNum(std::string s) {
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

// needs num but executes basic commands
int ConsoleManager::getNum(CommandManager& manager)
{
	std::cout << "> ";
	std::string input;
	std::cin >> input;

	while (!isNum(input)) {
		if (sToCommand(input) != INVALID) {
			manager.manage(input);
			if (sToCommand(input) == EXIT) return -1;
		}
		else {
			std::cout << "Write a number.\n";
		}
		std::cout << "> ";
		std::cin >> input;
	}
	
	return std::stoi(input);
}