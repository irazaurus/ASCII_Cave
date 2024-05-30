#include <iostream>
#include <algorithm>
#include "../Headers/Room.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/GameState.h"
#include "../Headers/CommandManager.h"

int main()
{
    srand(time(0));

    // new game initialization
    CommandManager commandMan;
    GameState game;
    game.initGame();
    commandMan.setState(&game);

    std::string choice;

    ConsoleManager ioManager;
    ioManager.gameStart();
    std::vector<std::string> choices;

    // game loop
    while (true) {
        if (game.isExit) break;

        system("cls");
        const RoomDef* currRoom = game.getCurrRoom();
        std::cout << currRoom->description << std::endl;

        // triggers
        commandMan.executeTriggers();
        std::cin.ignore();

        if (game.isExit) break;

        // choices to go
        for (size_t i = 0; i < currRoom->k.size(); i++) {
            const RoomDef* r = game.getRoomReg()->getDef(currRoom->k[i]);
            choices.push_back("Room No " + std::to_string(r->id));
        }

        ioManager.goTo(commandMan, &choices);
        choices.clear();

        if (game.isExit) break;
    }

    return 0;
}
