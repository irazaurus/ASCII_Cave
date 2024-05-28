#include "../Headers/ConsoleManager.h"
#include <iostream>

void OutputManager::gameStart()
{
	std::cout << "Welcome to the ASCII CAVE!\n"
			  << "The King chose you to fight with a dragon....\n"
			  << "(Press Enter...) ";
	std::cin.ignore();
	//TODO dialog with a King
}

std::string InputManager::getChoice(std::string question, std::vector<std::string>* choices)
{
	std::cout << question << std::endl;

	for (size_t i = 0; i < choices->size(); i++)
	{
		std::cout << choices->at(i) << std::endl;
	}
	std::cout << "> ";
	std::string inp;
	std::getline(std::cin, inp);
	return inp;
}
