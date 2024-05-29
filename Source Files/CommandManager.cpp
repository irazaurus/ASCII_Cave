#include "../Headers/CommandManager.h"
#include <iostream>

Commands sToCommand(std::string s) {
	if (s == "h" || s == "help")
		return HELP;
	if (s == "e" || s == "exit")
		return EXIT;
	if (s == "i" || s == "inventory") 
		return INVENTORY;
	if (s == "go")
		return GO;
	if (s == "a" || s == "attack")
		return ATTACK;
	return INVALID;
}

void CommandManager::resetValidCommands() {
	validCommands_.clear();

	validCommands_.insert(EXIT); // basic commands
	validCommands_.insert(HELP);
	validCommands_.insert(INVENTORY);

	if (last_ == INVENTORY) {    // inventory-based commands
		validCommands_.insert(EQUIP);
		validCommands_.insert(USE);
	}
}

void CommandManager::setLast(Commands c) {
	last_ = c;
}

void CommandManager::setState(GameState* state) {
	state_ = state;
}

void CommandManager::executeTriggers() {
	for (int i = 0; i < 10; i++) {
		if (state_->getCurrRoom()->triggers[i] == nullptr) continue;

		switch (state_->getCurrRoom()->triggers[i].get()->type()) {
			case TRAP: {
			// trap trigger
				TrapTrigger* trap = (TrapTrigger*) (state_->getCurrRoom()->triggers[i].get());
				trap->setMod(*(state_->getPlayer()->getTrapMod()));
				std::cout << "\nYou got yourself into a trap!\n";

				if (trap->execute()) {
					state_->getCurrRoom()->traps.pop();
					state_->getCurrRoom()->triggers[i] = nullptr;
					std::cout << "...\n" << "Phew, nothing serious. Let's move on." << std::endl;
				}
				else {
					TrapDef* trapDef = state_->getTrapReg()->getDef(state_->getCurrRoom()->traps.top());
					state_->getPlayer()->hp -= trapDef->damage;
					std::cout << "...\n" << "Owie... that hurt.\n" << "You've lost " << trapDef->damage << " hp." << std::endl;
					if (trapDef->type == SPIKE) {
						state_->getCurrRoom()->traps.pop();
						delete trapDef;
						state_->getCurrRoom()->triggers[i] = nullptr;
						std::cout << "Spikes crushed from the root and landed right on you!\n"
							<< "Luckly, they fell, so they won't hurt you again." << std::endl;
					}
					else {
						std::cout << "Trap's claws grabbed your feet so hard that you could barely get out.\n"
							<< "Have to be prepared for anything." << std::endl;
					}
				}
				break;
			}

			case FIGHT: {
				std::cout << "Fight!\n";
				break;
			}

			case LOOT: {
				break;
			}

			case SHOP: {
				break;
			}

			default:
				break;
			}
	}
}


void CommandManager::manage(std::string input) {
	Commands command = sToCommand(input);

	resetValidCommands();

	if (validCommands_.find(command) == validCommands_.end()) {
		invalid();
		return;
	}

	switch (command) {
	case EXIT:
		last_ = EXIT;
		exit();
		break;
	case HELP:
		help();
		break;
	case ATTACK:
		last_ = ATTACK;
		break;
	case INVENTORY:
		last_ = INVENTORY;
		break;
	case USE:
		break;
	case EQUIP:
		break;
	case BUY:
		break;
	default:
		invalid();
		break;
	}
}

bool CommandManager::go(int i) {
	if (std::find(state_->getCurrRoom()->k.begin(), state_->getCurrRoom()->k.end(), i) == state_->getCurrRoom()->k.end())
		return false;

	state_->setCurrRoom(i);
	return true;
}

void CommandManager::exit() {
	state_->isExit = true;
}

void CommandManager::invalid() {
	std::cout << "This is invalid command or used in the wrong context.\nWrite [help] for the list of all available commands." << std::endl;
}

void CommandManager::help() {
	std::cout << "Commands you may use:\n"
		<< "[h]elp - prints all available commands;\n"
		<< "[e]xit - exits the game;\n"
		<< "[i]nventory - lists all items that you have;\n"
		<< "{num} - lets you go to another room;\n"
		<< "something else..." << std::endl;
}
