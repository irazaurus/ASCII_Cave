#include "ConsoleManager.h"
#include <iostream>

void OutputManager::gameStart()
{
	std::cout << "Welcome to the ASCII CAVE!\n";
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
