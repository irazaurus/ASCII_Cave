#pragma once
#include <string>
#include <vector>

class OutputManager
{
public:
	void gameStart();
	void listChoices();
};

class InputManager
{
public:
	std::string getChoice(std::string question, std::vector<std::string>* choices);
};