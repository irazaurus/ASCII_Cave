#include <iostream>
#include <algorithm>
#include "../Headers/Room.h"
#include "../Headers/Trap.h"
#include "../Headers/NPC.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/Loader.h"
#include "../Headers/Engine.h"
#include "../Headers/Player.h"

int main()
{
    srand(time(0));
    Loader load;
    Player player;
    Registry<RoomDef> roomReg;
    Registry<TrapDef> trapReg;
    Registry<NPCDef> npcReg;

    // load from files
    load.loadRooms(roomReg);
    load.loadNPC(npcReg);
    load.loadTraps(trapReg);

    int currRoomId = 0;
    int choice;

    OutputManager outManager;
    InputManager inManager;
    outManager.gameStart();

    // game loop
    while (true) {

        system("cls");
        const RoomDef* currRoom = roomReg.getDef(currRoomId);
        std::cout << currRoom->description << std::endl;

        // triggers
        for (int i = 0; i < sizeof(currRoom->triggers); i++) {
            if (currRoom->triggers[i] == nullptr) break;
            currRoom->triggers[i]->execute(); // TODO обработка
        }

        // choices to go
        std::vector<std::string> choices;
        for (size_t i = 0; i < currRoom->k.size(); i++) {
            const RoomDef* r = roomReg.getDef(currRoom->k[i]);
            choices.push_back("Room No " + std::to_string(r->id));
        }

        do {
            choice = std::stoi(inManager.getChoice("Where to go?", &choices));
            system("cls");
        } while (std::find(currRoom->k.begin(), currRoom->k.end(), choice) == currRoom->k.end());

        currRoomId = choice;
        choices.clear();
    }

    return 0;
}
