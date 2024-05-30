#include "../Headers/CommandManager.h"
#include "../Headers/ConsoleManager.h"
#include <iostream>
#include <iomanip>

Commands sToCommand(std::string s) {
	if (s == "h" || s == "help")
		return HELP;
	if (s == "e" || s == "exit")
		return EXIT;
	if (s == "i" || s == "inventory") 
		return INVENTORY;
	if (s == "use")
		return USE;
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
		validCommands_.insert(USE);
	}
	else if (last_ == ATTACK)
		validCommands_.insert(ATTACK);
}

void CommandManager::setLast(Commands c) {
	last_ = c;
}

void CommandManager::setState(GameState* state) {
	state_ = state;
}

void CommandManager::executeTriggers() {
	for (int i = 0; i < 10; i++) {
		if (last_ == EXIT) break;
		if (state_->getCurrRoom()->triggers[i] == nullptr) continue;

		switch (state_->getCurrRoom()->triggers[i].get()->type()) {

			// trap trigger
			case TRAP: {
				TrapTrigger* trap = (TrapTrigger*) (state_->getCurrRoom()->triggers[i].get());
				trap->setMod(state_->getPlayer()->trap_mod_);
				std::cout << "\nYou got yourself into a trap!\n";

				if (trap->execute()) {
					state_->getCurrRoom()->traps.pop();
					state_->getCurrRoom()->triggers[i] = nullptr;
					std::cout << "...\n" << "Phew, nothing serious. Let's move on." << std::endl;
				}
				else {
					TrapDef* trapDef = state_->getTrapReg()->getDef(state_->getCurrRoom()->traps.top());
					state_->getPlayer()->hp -= trapDef->damage;
					std::cout << "Owie... that hurt.\n" << "You've lost " << trapDef->damage << " hp." << std::endl;
					if (trapDef->type == SPIKE) {
						state_->getCurrRoom()->traps.pop();
						delete trapDef;
						state_->getCurrRoom()->triggers[i] = nullptr;
						std::cout << "Spikes crushed from the root and landed right on you!\n"
							<< "Luckly, they fell, so they won't hurt you again." << std::endl;
					}
					else {
						std::cout << "Trap's claws grabbed your feet so hard that you barely managed to get out.\n"
							<< "Have to be prepared for anything." << std::endl;
					}
				}
				std::cin.ignore(1);
				std::cin.ignore();
				break;
			}

			// fight trigger
			case FIGHT: {
				NPCDef* monster = state_->getNpcReg()->getDef(state_->getCurrRoom()->npc.back());
				ConsoleManager console;
				std::string input;
				bool win {false};

				FightTrigger* fight = (FightTrigger*) (state_->getCurrRoom()->triggers[i].get());
				fight->setSides(state_->getPlayer()->hp, state_->getPlayer()->damage + state_->getPlayer()->dmg_mod,
								monster->hp, monster->damage - state_->getPlayer()->armor);

				// TODO monster religion
				while (fight->gethp1() != 0 && fight->gethp2() != 0) {
					
					console.fightMenu(state_->getPlayer(), monster);

					while (input != "attack" && input != "a") {
						std::cout << "\n> ";
						std::cin >> input;
						setLast(ATTACK);
						manage(input);

						if (last_ == EXIT) break;
					}

					win = fight->execute();
					state_->getPlayer()->hp = fight->gethp1();
					monster->hp = fight->gethp2();
				}
				console.fightMenu(state_->getPlayer(), monster);

				if (win) {
					std::cout << "        You won, Congrats!\n";
					state_->getCurrRoom()->triggers[i] = std::unique_ptr<Trigger>(new LootTrigger);
					state_->getCurrRoom()->npc.pop_back();
				}
				else {
					std::cout << "          You lost :(     \n";
					state_->setCurrRoom(0);
					last_ = EXIT;
				}

				monster->hp = monster->maxHp;
				std::cin.ignore();
				std::cin.ignore();
				break;
			}

			case LOOT: {
				std::cout << "Loot!";
				break;
			}

			case WIN: {
				state_->getCurrRoom()->triggers[i]->execute();
				exit();
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
		inventory();
		last_ = INVENTORY;
		break;
	case USE:
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

void CommandManager::inventory() {
	std::cout << "hp: " << state_->getPlayer()->hp << std::endl
		<< "damage:" << state_->getPlayer()->damage << std::endl
		<< "items:" << std::endl;

	for (int i = 0; i < state_->getPlayer()->getItems()->size(); i++) {
		ItemDef* item = state_->getItemReg()->getDef(state_->getPlayer()->getItems()->at(i));
		std::cout << std::setw(13) << item->name << std::setw(30) << item->description << "\n";
	}

	std::cout << "> ";
	std::string input;
	manage(input);
}

void CommandManager::use() {
	std::vector<ItemDef*> plItems;
	for (int i : *(state_->getPlayer()->getItems())) {
		plItems.push_back(state_->getItemReg()->getDef(i));
	}

	std::string input;
	std::cin >> input;
	auto it = std::find_if(plItems.begin(), plItems.end(), [&input](ItemDef* def) {return input == def->name; });
	if (it != plItems.end()) {
		if ((*it)->isUsable) {
			//TODO Item method use();
			// delete this item from player
			//state_->getPlayer()->getItems()->at(it);
		}
		else if ((*it)->isEquippable) {
			// TODO 
		}
		else { std::cout << "You can't use that." << std::endl; }
	}
	else std::cout << "No such thing." << std::endl;
}

void CommandManager::invalid() {
	std::cout << "This is invalid command or used in the wrong context.\nWrite [help] for the list of all available commands." << std::endl;
}

void CommandManager::help() {
	std::cout << "Commands you may use:\n\n"
		<< "[h]elp - prints all available commands;\n"
		<< "[e]xit - exits the game;\n"
		<< "[i]nventory - lists all items that you have and your parameters;\n"
		<< "use {name} - uses item from inventory;\n"
		<< "{num} - lets you go to another room;\n"
		<< "[a]ttack - attack monster in a fight;" << std::endl;
}
